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

#=========================================================================================
#==============================Member functions===========================================
#=========================================================================================
if [[ "$1" == "" ]] || [[ "$1" == "Member" ]]; then
	printf "$PURPLE Member functions $DEFAULT\n"
fi
# 1
if [[ "$1" == "" ]] || [[ "$1" == "Member" ]] || [[ "$1" == "empty" ]]; then
	printf "$YELLOW Test empty $DEFAULT \n"
	clang++	-Wall -Wextra -Werror	test_stack/stack_member/stack_member_empty.cpp -o stack_prog
	TEST_OUTPUT=$(./stack_prog)
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
	rm -rf stack_prog
fi
# 2
if [[ "$1" == "" ]] || [[ "$1" == "Member" ]] || [[ "$1" == "size" ]]; then
	printf "$YELLOW Test size $DEFAULT \n"
	clang++	-Wall -Wextra -Werror	test_stack/stack_member/stack_member_size.cpp -o stack_prog
	TEST_OUTPUT=$(./stack_prog)
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
	rm -rf stack_prog
fi
# 3
if [[ "$1" == "" ]] || [[ "$1" == "Member" ]] || [[ "$1" == "top" ]]; then
	printf "$YELLOW Test top $DEFAULT \n"
	clang++	-Wall -Wextra -Werror	test_stack/stack_member/stack_member_top.cpp -o stack_prog
	TEST_OUTPUT=$(./stack_prog)
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
	rm -rf stack_prog
fi
# 4
if [[ "$1" == "" ]] || [[ "$1" == "Member" ]] || [[ "$1" == "top_const" ]]; then
	printf "$YELLOW Test top const $DEFAULT \n"
	clang++	-Wall -Wextra -Werror	test_stack/stack_member/stack_member_top_const.cpp -o stack_prog
	TEST_OUTPUT=$(./stack_prog)
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
	rm -rf stack_prog
fi
# 5
if [[ "$1" == "" ]] || [[ "$1" == "Member" ]] || [[ "$1" == "push" ]]; then
	printf "$YELLOW Test push $DEFAULT \n"
	clang++	-Wall -Wextra -Werror	test_stack/stack_member/stack_member_push.cpp -o stack_prog
	TEST_OUTPUT=$(./stack_prog)
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
	rm -rf stack_prog
fi
# 6
if [[ "$1" == "" ]] || [[ "$1" == "Member" ]] || [[ "$1" == "pop" ]]; then
	printf "$YELLOW Test pop $DEFAULT \n"
	clang++	-Wall -Wextra -Werror	test_stack/stack_member/stack_member_pop.cpp -o stack_prog
	TEST_OUTPUT=$(./stack_prog)
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
	rm -rf stack_prog
fi
#=========================================================================================
#============================Non-member function overloads================================
#=========================================================================================
if [[ "$1" == "" ]] || [[ "$1" == "Non" ]]; then
	printf "$PURPLE operator $DEFAULT \n"
fi
#1
if [[ "$1" == "" ]] || [[ "$1" == "Non" ]] || [[ "$1" == "operator" ]]; then
	printf "$YELLOW Test operator $DEFAULT \n"
	clang++	-Wall -Wextra -Werror	test_stack/stack_operator/stack_operator_all.cpp -o stack_prog
	TEST_OUTPUT=$(./stack_prog)
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
	rm -rf stack_prog
fi
#rez
echo "-------------------------------------"
printf "$PURPLE Finish\n $point/$all $DEFAULT \n"
