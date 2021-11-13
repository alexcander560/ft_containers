DEFAULT="\033[0m"
REVERS="\033[7m"
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
PURPLE="\033[35m"

IFS=$'\x10'

echo
echo "███╗░░░███╗░█████╗░██████╗░  ████████╗███████╗░██████╗████████╗"
echo "████╗░████║██╔══██╗██╔══██╗  ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝"
echo "██╔████╔██║███████║██████╔╝  ░░░██║░░░█████╗░░╚█████╗░░░░██║░░░"
echo "██║╚██╔╝██║██╔══██║██╔═══╝░  ░░░██║░░░██╔══╝░░░╚═══██╗░░░██║░░░"
echo "██║░╚═╝░██║██║░░██║██║░░░░░  ░░░██║░░░███████╗██████╔╝░░░██║░░░"
echo "╚═╝░░░░░╚═╝╚═╝░░╚═╝╚═╝░░░░░  ░░░╚═╝░░░╚══════╝╚═════╝░░░░╚═╝░░░"
echo

declare -i point=0
declare -i all=0
declare -i rez=0

# Функция запускает нужный тест (1 аргумент - имя теста, 2 аргумент - путь до файла с тестом) 
run_test()
{
	printf "$YELLOW $1 $DEFAULT \n"
	clang++	-Wall -Wextra -Werror $2 -o map_prog
	TEST_OUTPUT=$(./map_prog)
	rez=$?
	all=all+1
	if [[ "$rez" == "139" ]]; then
		printf "$RED segmentation fault $DEFAULT \n"
		rez=0
	elif [[ "$TEST_OUTPUT" == "" ]]; then
		printf "$RED does not compile $DEFAULT \n"
	else
		echo $TEST_OUTPUT
		point=point+rez
	fi
	rm -rf map_prog
}

# Функция проверяет, нужно ли запустить тест (1 аргумент - первый аргумент который был передан скрипту bash,
# 2-4 аргументы - возможные ключи для запуска теста, 5 аргумент - имя теста, 6 аргумент - путь до файла с тестом)
check_test()
{
	if [[ "$1" == "$2" ]] || [[ "$1" == "$3" ]] || [[ "$1" == "$4" ]]; then
		run_test "$5" "$6"
	fi
}

# Функция проверяет, нужно ли запустить тест(для функций, где ключей для запуска функции 4, а не 3)
check_test_d()
{
	if [[ "$1" == "$2" ]] || [[ "$1" == "$3" ]] || [[ "$1" == "$4" ]] || [[ "$1" == "$5" ]]; then
		run_test "$6" "$7"
	fi
}

# Блок для того, чтобы можно было запустить все тесты, когда скрипт запускается без аргументов
if [[ "$1" == "" ]]; then
	temp="ALL"
else
	temp=$1
fi

#=========================================================================================
#==============================Element access=============================================
#=========================================================================================
if [[ "$1" == "" ]] || [[ "$1" == "Acc" ]]; then
	printf "$PURPLE Element access $DEFAULT\n"
fi
# 1 тест
check_test $temp	"ALL"	"Acc"	"acc"		"Test []"									"test_map/map_access/map_access_operator.cpp"

#=========================================================================================
#====================================Capacity=============================================
#=========================================================================================
if [[ "$1" == "" ]] || [[ "$1" == "Cap" ]]; then
	printf "$PURPLE Capacity $DEFAULT\n"
fi
# 3 теста
check_test $temp	"ALL"	"Cap"	"size"			"Test size"								"test_map/map_capacity/map_capacity_size.cpp"
check_test $temp	"ALL"	"Cap"	"max_size"		"Test max_size"							"test_map/map_capacity/map_capacity_max_size.cpp"
check_test $temp	"ALL"	"Cap"	"empty"			"Test empty"							"test_map/map_capacity/map_capacity_empty.cpp"

#=========================================================================================
#====================================Allocator============================================
#=========================================================================================
if [[ "$1" == "" ]] || [[ "$1" == "Alloc" ]]; then
	printf "$PURPLE allocator $DEFAULT\n"
fi
# 1 тест
check_test $temp	"ALL"	"Alloc"	"get_allocator"	"Test get_allocator"					"test_map/map_allocator/map_allocator_get.cpp"

#=========================================================================================
#====================================Iterators============================================
#=========================================================================================
if [[ "$1" == "" ]] || [[ "$1" == "Iter" ]]; then
	printf "$PURPLE iterators $DEFAULT\n"
fi
# 4 теста
check_test $temp	"ALL"	"Iter"	"iterator"			"Test iterator"						"test_map/map_iterators/map_iterators_iterator.cpp"
check_test $temp	"ALL"	"Iter"	"iterator_const"	"Test iterators const"				"test_map/map_iterators/map_iterators_iterator_const.cpp"
check_test $temp	"ALL"	"Iter"	"r_iterator"		"Test reverse_iterators"			"test_map/map_iterators/map_iterators_r_iterator_const.cpp"
check_test $temp	"ALL"	"Iter"	"r_iterator_const"	"Test reverse_iterators const"		"test_map/map_iterators/map_iterators_r_iterator_const.cpp"

#=========================================================================================
#============================Non-member function overloads================================
#=========================================================================================
if [[ "$1" == "" ]] || [[ "$1" == "Non" ]]; then
	printf "$PURPLE operator $DEFAULT \n"
fi
# 2 теста
check_test $temp	"ALL"	"Non"	"operator"			"Test operator"						"test_map/map_operator/map_operator_all.cpp"
check_test_d $temp	"ALL"	"Non"	"swap"	"Non_swap"	"Test swap"							"test_map/map_operator/map_operator_swap.cpp"

#=========================================================================================
#===================================Modifiers=============================================
#=========================================================================================
if [[ "$1" == "" ]] || [[ "$1" == "Mod" ]]; then
	printf "$PURPLE Modifiers $DEFAULT \n"
fi
# 8 тестов
check_test_d $temp	"ALL"	"Mod"		"insert"		"insert_1"		"Test insert(val)"								"test_map/map_modifiers/map_modifiers_insert_1.cpp"
check_test_d $temp	"ALL"	"Mod"		"insert"		"insert_2"		"Test insert(iterator, val)"					"test_map/map_modifiers/map_modifiers_insert_2.cpp"
check_test_d $temp	"ALL"	"Mod"		"insert"		"insert_3"		"Test insert(InputIterator, InputIterator)"		"test_map/map_modifiers/map_modifiers_insert_3.cpp"
check_test_d $temp	"ALL"	"Mod"		"erase"			"erase_1"		"Test erase(iterator)"							"test_map/map_modifiers/map_modifiers_erase_1.cpp"	
check_test_d $temp	"ALL"	"Mod"		"erase"			"erase_2"		"est erase(k)"									"test_map/map_modifiers/map_modifiers_erase_2.cpp"
check_test_d $temp	"ALL"	"Mod"		"erase"			"erase_3"		"est erase(iterator, iterator)"					"test_map/map_modifiers/map_modifiers_erase_3.cpp"
check_test_d $temp	"ALL"	"Mod"		"swap"			"Mod_swap"		"Test swap"										"test_map/map_modifiers/map_modifiers_swap.cpp"
check_test $temp	"ALL"	"Mod"		"clear"							"Test clear"									"test_map/map_modifiers/map_modifiers_clear.cpp"

#=========================================================================================
#===================================Operations============================================
#=========================================================================================
if [[ "$1" == "" ]] || [[ "$1" == "Oper" ]]; then
	printf "$PURPLE Operations $DEFAULT\n"
fi
# 9 тестов
check_test $temp	"ALL"	"Oper"		"count"					"Test count"											"test_map/map_operations/map_operations_count.cpp"
check_test $temp	"ALL"	"Oper"		"equal_range"			"Test equal_range"										"test_map/map_operations/map_operations_equal_range.cpp"
check_test $temp	"ALL"	"Oper"		"equal_range_const"		"Test equal_range const"								"test_map/map_operations/map_operations_equal_range_const.cpp"
check_test $temp	"ALL"	"Oper"		"find"					"Test find"												"test_map/map_operations/map_operations_find.cpp"
check_test $temp	"ALL"	"Oper"		"find_const"			"Test find const"										"test_map/map_operations/map_operations_find_const.cpp"
check_test $temp	"ALL"	"Oper"		"lower_bound"			"Test lower_bound"										"test_map/map_operations/map_operations_lower_bound.cpp"
check_test $temp	"ALL"	"Oper"		"lower_bound_const"		"Test lower_bound const"								"test_map/map_operations/map_operations_lower_bound_const.cpp"
check_test $temp	"ALL"	"Oper"		"upper_bound"			"Test upper_bound"										"test_map/map_operations/map_operations_upper_bound.cpp"
check_test $temp	"ALL"	"Oper"		"upper_bound_const"		"Test upper_bound const"								"test_map/map_operations/map_operations_upper_bound_const.cpp"

#=========================================================================================
# Всего тестов 28
echo "-------------------------------------"
printf "$PURPLE Finish\n $point/$all $DEFAULT \n"
