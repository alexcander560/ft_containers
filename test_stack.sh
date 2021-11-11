DEFAULT="\033[0m"
REVERS="\033[7m"
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
PURPLE="\033[35m"

IFS=$'\x10'

echo
echo "░██████╗████████╗░█████╗░░█████╗░██╗░░██╗  ████████╗███████╗░██████╗████████╗"
echo "██╔════╝╚══██╔══╝██╔══██╗██╔══██╗██║░██╔╝  ╚══██╔══╝██╔════╝██╔════╝╚══██╔══╝"
echo "╚█████╗░░░░██║░░░███████║██║░░╚═╝█████═╝░  ░░░██║░░░█████╗░░╚█████╗░░░░██║░░░"
echo "░╚═══██╗░░░██║░░░██╔══██║██║░░██╗██╔═██╗░  ░░░██║░░░██╔══╝░░░╚═══██╗░░░██║░░░"
echo "██████╔╝░░░██║░░░██║░░██║╚█████╔╝██║░╚██╗  ░░░██║░░░███████╗██████╔╝░░░██║░░░"
echo "╚═════╝░░░░╚═╝░░░╚═╝░░╚═╝░╚════╝░╚═╝░░╚═╝  ░░░╚═╝░░░╚══════╝╚═════╝░░░░╚═╝░░░"
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

# Блок для того, чтобы можно было запустить все тесты, когда скрипт запускается без аргументов
if [[ "$1" == "" ]]; then
	temp="ALL"
else
	temp=$1
fi

#=========================================================================================
#==============================Member functions===========================================
#=========================================================================================
if [[ "$1" == "" ]] || [[ "$1" == "Member" ]]; then
	printf "$PURPLE Member functions $DEFAULT\n"
fi

# 6 тестов
check_test $temp	"ALL"	"Member"	"empty"			"Test empty"		"test_stack/stack_member/stack_member_empty.cpp"
check_test $temp	"ALL"	"Member"	"size"			"Test size"			"test_stack/stack_member/stack_member_size.cpp"
check_test $temp	"ALL"	"Member"	"top"			"Test top"			"test_stack/stack_member/stack_member_top.cpp"
check_test $temp	"ALL"	"Member"	"top_const"		"Test top const"	"test_stack/stack_member/stack_member_top_const.cpp"
check_test $temp	"ALL"	"Member"	"push"			"Test push"			"test_stack/stack_member/stack_member_push.cpp"
check_test $temp	"ALL"	"Member"	"pop"			"Test pop"			"test_stack/stack_member/stack_member_pop.cpp"

#=========================================================================================
#============================Non-member function overloads================================
#=========================================================================================
if [[ "$1" == "" ]] || [[ "$1" == "Non" ]]; then
	printf "$PURPLE operator $DEFAULT \n"
fi
# 1 тест
check_test $temp	"ALL"	"Non"		"operator"		"Test operator"		"test_stack/stack_operator/stack_operator_all.cpp"

#=========================================================================================
# Всего тестов 7
echo "-------------------------------------"
printf "$PURPLE Finish\n $point/$all $DEFAULT \n"
