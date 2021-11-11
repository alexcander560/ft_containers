DEFAULT="\033[0m"
REVERS="\033[7m"
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
PURPLE="\033[35m"

IFS=$'\x10'

echo
echo "██╗░░░██╗███████╗░█████╗░████████╗░█████╗░██████╗░  ████████╗███████╗░██████╗████████╗"
echo "██║░░░██║██╔════╝██╔══██╗╚══██╔══╝██╔══██╗██╔══██╗  ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝"
echo "╚██╗░██╔╝█████╗░░██║░░╚═╝░░░██║░░░██║░░██║██████╔╝  ░░░██║░░░█████╗░░╚█████╗░░░░██║░░░"
echo "░╚████╔╝░██╔══╝░░██║░░██╗░░░██║░░░██║░░██║██╔══██╗  ░░░██║░░░██╔══╝░░░╚═══██╗░░░██║░░░"
echo "░░╚██╔╝░░███████╗╚█████╔╝░░░██║░░░╚█████╔╝██║░░██║  ░░░██║░░░███████╗██████╔╝░░░██║░░░"
echo "░░░╚═╝░░░╚══════╝░╚════╝░░░░╚═╝░░░░╚════╝░╚═╝░░╚═╝  ░░░╚═╝░░░╚══════╝╚═════╝░░░░╚═╝░░░"
echo

declare -i point=0
declare -i all=0
declare -i rez=0

# Функция запускает нужный тест (1 аргумент - имя теста, 2 аргумент - путь до файла с тестом) 
run_test()
{
	printf "$YELLOW $1 $DEFAULT \n"
	clang++	-Wall -Wextra -Werror $2 -o vector_prog
	TEST_OUTPUT=$(./vector_prog)
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
	rm -rf vector_prog
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
# 8 тестов
check_test $temp	"ALL"	"Acc"	"acc"				"Test []"						"test_vector/vector_access/vector_access_operator.cpp"
check_test $temp	"ALL"	"Acc"	"acc_const"			"Test [] const"					"test_vector/vector_access/vector_access_operator_const.cpp"
check_test $temp	"ALL"	"Acc"	"at"				"Test at"						"test_vector/vector_access/vector_access_at.cpp"
check_test $temp	"ALL"	"Acc"	"at_const"			"Test at const"					"test_vector/vector_access/vector_access_at_const.cpp"
check_test $temp	"ALL"	"Acc"	"front"				"Test front"					"test_vector/vector_access/vector_access_front.cpp"
check_test $temp	"ALL"	"Acc"	"front_const"		"Test front const"				"test_vector/vector_access/vector_access_front_const.cpp"
check_test $temp	"ALL"	"Acc"	"back"				"Test back"						"test_vector/vector_access/vector_access_back.cpp"
check_test $temp	"ALL"	"Acc"	"back_const"		"Test back const"				"test_vector/vector_access/vector_access_back_const.cpp"

#=========================================================================================
#====================================Capacity=============================================
#=========================================================================================
if [[ "$1" == "" ]] || [[ "$1" == "Cap" ]]; then
	printf "$PURPLE Capacity $DEFAULT\n"
fi
# 6 тестов
check_test $temp	"ALL"	"Cap"	"size"				"Test size"						"test_vector/vector_capacity/vector_capacity_size.cpp"
check_test $temp	"ALL"	"Cap"	"max_size"			"Test max_size"					"test_vector/vector_capacity/vector_capacity_max_size.cpp"
check_test $temp	"ALL"	"Cap"	"capacity"			"Test capacity"					"test_vector/vector_capacity/vector_capacity_capacity.cpp"
check_test $temp	"ALL"	"Cap"	"reserve"			"Test reserve"					"test_vector/vector_capacity/vector_capacity_reserve.cpp"	
check_test $temp	"ALL"	"Cap"	"empty"				"Test empty"					"test_vector/vector_capacity/vector_capacity_empty.cpp"
check_test $temp	"ALL"	"Cap"	"resize"			"Test resize"					"test_vector/vector_capacity/vector_capacity_resize.cpp"

#=========================================================================================
#====================================Allocator============================================
#=========================================================================================
if [[ "$1" == "" ]] || [[ "$1" == "Alloc" ]]; then
	printf "$PURPLE allocator $DEFAULT\n"
fi
# 1 тест
check_test $temp	"ALL"	"Alloc"	"get_allocator"		"Test get_allocator"			"test_vector/vector_allocator/vector_allocator_get.cpp"

#=========================================================================================
#====================================Iterators============================================
#=========================================================================================
if [[ "$1" == "" ]] || [[ "$1" == "Iter" ]]; then
	printf "$PURPLE iterators $DEFAULT\n"
fi
# 4 теста
check_test $temp	"ALL"	"Iter"	"iterator"			"Test iterator"					"test_vector/vector_iterators/vector_iterators_iterator.cpp"
check_test $temp	"ALL"	"Iter"	"iterator_const"	"Test iterator const"			"test_vector/vector_iterators/vector_iterators_iterator_const.cpp"
check_test $temp	"ALL"	"Iter"	"r_iterator"		"Test reverse_iterator"			"test_vector/vector_iterators/vector_iterators_r_iterator.cpp"
check_test $temp	"ALL"	"Iter"	"r_iterator_const"	"Test reverse_iterator const"	"test_vector/vector_iterators/vector_iterators_r_iterator_const.cpp"

#=========================================================================================
#============================Non-member function overloads================================
#=========================================================================================
if [[ "$1" == "" ]] || [[ "$1" == "Non" ]]; then
	printf "$PURPLE operator $DEFAULT \n"
fi
# 2 теста
check_test $temp	"ALL"	"Non"	"operator"			"Test operator"					"test_vector/vector_operator/vector_operator_all.cpp"
check_test_d $temp	"ALL"	"Non"	"swap"	"Non_swap"	"Test swap"						"test_vector/vector_operator/vector_operator_swap.cpp"

#=========================================================================================
#===================================Modifiers=============================================
#=========================================================================================
if [[ "$1" == "" ]] || [[ "$1" == "Mod" ]]; then
	printf "$PURPLE Modifiers $DEFAULT \n"
fi
# 11 тестов
check_test_d $temp	"ALL"	"Mod"	"assign"	"assign_1"	"Test assign(InputIterator, InputIterator)"				"test_vector/vector_modifiers/vector_modifiers_assign_1.cpp"
check_test_d $temp	"ALL"	"Mod"	"assign"	"assign_2"	"Test assign(n, val)"									"test_vector/vector_modifiers/vector_modifiers_assign_2.cpp"
check_test $temp	"ALL"	"Mod"	"push_back"				"Test push_back"										"test_vector/vector_modifiers/vector_modifiers_push_back.cpp"
check_test $temp	"ALL"	"Mod"	"pop_back"				"Test pop_back"											"test_vector/vector_modifiers/vector_modifiers_pop_back.cpp"
check_test_d $temp	"ALL"	"Mod"	"insert"	"insert_1"	"Test insert(iterator, val)"							"test_vector/vector_modifiers/vector_modifiers_insert_1.cpp"
check_test_d $temp	"ALL"	"Mod"	"insert"	"insert_2"	"Test insert(iterator, n, val)"							"test_vector/vector_modifiers/vector_modifiers_insert_2.cpp"
check_test_d $temp	"ALL"	"Mod"	"insert"	"insert_3"	"Test insert(iterator, InputIterator, InputIterator)"	"test_vector/vector_modifiers/vector_modifiers_insert_3.cpp"
check_test_d $temp	"ALL"	"Mod"	"erase"		"erase_1"	"Test erase(iterator)"									"test_vector/vector_modifiers/vector_modifiers_erase_1.cpp"
check_test_d $temp	"ALL"	"Mod"	"erase"		"erase_2"	"Test erase(iterator, iterator)"						"test_vector/vector_modifiers/vector_modifiers_erase_2.cpp"
check_test_d $temp	"ALL"	"Mod"	"swap"		"Mod_swap"	"Test swap"												"test_vector/vector_modifiers/vector_modifiers_swap.cpp"
check_test $temp	"ALL"	"Mod"	"clear"					"Test clear"											"test_vector/vector_modifiers/vector_modifiers_clear.cpp"

#=========================================================================================
# Всего тестов 32
echo "-------------------------------------"
printf "$PURPLE Finish\n $point/$all $DEFAULT \n"
