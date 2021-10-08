DEFAULT="\033[0m"
REVERS="\033[7m"
RED="\033[31m"
GREEN="\033[32m"
YELLOW="\033[33m"
PURPLE="\033[35m"

IFS=$'\x10'

echo "-----------------------------------------------------------------------------------"
echo "-----------------------------ft_containers TEST------------------------------------"
echo "-----------------------------------------------------------------------------------"

declare -i point=0
declare -i all=0
declare -i rez=0

#=========================================================================================
#==============================Element access=============================================
#=========================================================================================
: '
printf "$PURPLE Element access $DEFAULT\n"
# 1
printf "$YELLOW Test [] $DEFAULT \n"
clang++	-Wall -Wextra -Werror	test_vector/vector_access/vector_access_operator.cpp -o vector_prog
TEST_OUTPUT=$(./vector_prog)
rez=$?
all=all+1
if [[ "$TEST_OUTPUT" == "" ]]; then
	printf "$RED does not compile $DEFAULT \n"
else
	echo $TEST_OUTPUT
	point=point+rez
fi
rm -rf vector_prog
# 2
printf "$YELLOW Test [] const $DEFAULT \n"
clang++	-Wall -Wextra -Werror	test_vector/vector_access/vector_access_operator_const.cpp -o vector_prog
TEST_OUTPUT=$(./vector_prog)
rez=$?
all=all+1
if [[ "$TEST_OUTPUT" == "" ]]; then
	printf "$RED does not compile $DEFAULT \n"
else
	echo $TEST_OUTPUT
	point=point+rez
fi
rm -rf vector_prog
# 3
printf "$YELLOW Test at $DEFAULT \n"
echo $TEST_OUTPUT
clang++	-Wall -Wextra -Werror	test_vector/vector_access/vector_access_at.cpp -o vector_prog
TEST_OUTPUT=$(./vector_prog)
rez=$?
all=all+1
if [[ "$TEST_OUTPUT" == "" ]]; then
	printf "$RED does not compile $DEFAULT \n"
else
	echo $TEST_OUTPUT
	point=point+rez
fi
rm -rf vector_prog
# 4
printf "$YELLOW Test at const $DEFAULT \n"
clang++	-Wall -Wextra -Werror	test_vector/vector_access/vector_access_at_const.cpp -o vector_prog
TEST_OUTPUT=$(./vector_prog)
rez=$?
all=all+1
if [[ "$TEST_OUTPUT" == "" ]]; then
	printf "$RED does not compile $DEFAULT \n"
else
	echo $TEST_OUTPUT
	point=point+rez
fi
rm -rf vector_prog
# 5
printf "$YELLOW Test front $DEFAULT \n"
clang++	-Wall -Wextra -Werror	test_vector/vector_access/vector_access_front.cpp -o vector_prog
TEST_OUTPUT=$(./vector_prog)
rez=$?
all=all+1
if [[ "$TEST_OUTPUT" == "" ]]; then
	printf "$RED does not compile $DEFAULT \n"
else
	echo $TEST_OUTPUT
	point=point+rez
fi
rm -rf vector_prog
# 6
printf "$YELLOW Test front const $DEFAULT \n"
clang++	-Wall -Wextra -Werror	test_vector/vector_access/vector_access_front_const.cpp -o vector_prog
TEST_OUTPUT=$(./vector_prog)
rez=$?
all=all+1
if [[ "$TEST_OUTPUT" == "" ]]; then
	printf "$RED does not compile $DEFAULT \n"
else
	echo $TEST_OUTPUT
	point=point+rez
fi
rm -rf vector_prog
# 7
printf "$YELLOW Test back $DEFAULT \n"
clang++	-Wall -Wextra -Werror	test_vector/vector_access/vector_access_back.cpp -o vector_prog
TEST_OUTPUT=$(./vector_prog)
rez=$?
all=all+1
if [[ "$TEST_OUTPUT" == "" ]]; then
	printf "$RED does not compile $DEFAULT \n"
else
	echo $TEST_OUTPUT
	point=point+rez
fi
rm -rf vector_prog
# 8
printf "$YELLOW Test back const $DEFAULT \n"
clang++	-Wall -Wextra -Werror	test_vector/vector_access/vector_access_back_const.cpp -o vector_prog
TEST_OUTPUT=$(./vector_prog)
rez=$?
all=all+1
if [[ "$TEST_OUTPUT" == "" ]]; then
	printf "$RED does not compile $DEFAULT \n"
else
	echo $TEST_OUTPUT
	point=point+rez
fi
rm -rf vector_prog
#=========================================================================================
#====================================Capacity=============================================
#=========================================================================================
printf "$PURPLE Capacity $DEFAULT\n"
# 1
printf "$YELLOW Test size $DEFAULT \n"
clang++	-Wall -Wextra -Werror	test_vector/vector_capacity/vector_capacity_size.cpp -o vector_prog
TEST_OUTPUT=$(./vector_prog)
rez=$?
all=all+1
if [[ "$TEST_OUTPUT" == "" ]]; then
	printf "$RED does not compile $DEFAULT \n"
else
	echo $TEST_OUTPUT
	point=point+rez
fi
rm -rf vector_prog
# 2
printf "$YELLOW Test max_size $DEFAULT \n"
clang++	-Wall -Wextra -Werror	test_vector/vector_capacity/vector_capacity_max_size.cpp -o vector_prog
TEST_OUTPUT=$(./vector_prog)
rez=$?
all=all+1
if [[ "$TEST_OUTPUT" == "" ]]; then
	printf "$RED does not compile $DEFAULT \n"
else
	echo $TEST_OUTPUT
	point=point+rez
fi
rm -rf vector_prog
# 3
printf "$YELLOW Test capacity $DEFAULT \n"
clang++	-Wall -Wextra -Werror	test_vector/vector_capacity/vector_capacity_capacity.cpp -o vector_prog
TEST_OUTPUT=$(./vector_prog)
rez=$?
all=all+1
if [[ "$TEST_OUTPUT" == "" ]]; then
	printf "$RED does not compile $DEFAULT \n"
else
	echo $TEST_OUTPUT
	point=point+rez
fi
rm -rf vector_prog
# 4
printf "$YELLOW Test reserve $DEFAULT \n"
clang++	-Wall -Wextra -Werror	test_vector/vector_capacity/vector_capacity_reserve.cpp -o vector_prog
TEST_OUTPUT=$(./vector_prog)
rez=$?
all=all+1
if [[ "$TEST_OUTPUT" == "" ]]; then
	printf "$RED does not compile $DEFAULT \n"
else
	echo $TEST_OUTPUT
	point=point+rez
fi
rm -rf vector_prog
# 5
printf "$YELLOW Test empty $DEFAULT \n"
clang++	-Wall -Wextra -Werror	test_vector/vector_capacity/vector_capacity_empty.cpp -o vector_prog
TEST_OUTPUT=$(./vector_prog)
rez=$?
all=all+1
if [[ "$TEST_OUTPUT" == "" ]]; then
	printf "$RED does not compile $DEFAULT \n"
else
	echo $TEST_OUTPUT
	point=point+rez
fi
rm -rf vector_prog
# 6
printf "$YELLOW Test resize $DEFAULT \n"
clang++	-Wall -Wextra -Werror	test_vector/vector_capacity/vector_capacity_resize.cpp -o vector_prog
TEST_OUTPUT=$(./vector_prog)
rez=$?
all=all+1
if [[ "$TEST_OUTPUT" == "" ]]; then
	printf "$RED does not compile $DEFAULT \n"
else
	echo $TEST_OUTPUT
	point=point+rez
fi
rm -rf vector_prog

#=========================================================================================
#====================================Allocator============================================
#=========================================================================================
printf "$PURPLE allocator $DEFAULT\n"
# 1
printf "$YELLOW Test get_allocator $DEFAULT \n"
clang++	-Wall -Wextra -Werror	test_vector/vector_allocator/vector_allocator_get.cpp -o vector_prog
TEST_OUTPUT=$(./vector_prog)
rez=$?
all=all+1
if [[ "$TEST_OUTPUT" == "" ]]; then
	printf "$RED does not compile $DEFAULT \n"
else
	echo $TEST_OUTPUT
	point=point+rez
fi
rm -rf vector_prog

#=========================================================================================
#====================================Iterators============================================
#=========================================================================================
printf "$PURPLE iterators $DEFAULT\n"
# 1
printf "$YELLOW Test iterators $DEFAULT \n"
clang++	-Wall -Wextra -Werror	test_vector/vector_iterators/vector_iterators_iterator.cpp -o vector_prog
TEST_OUTPUT=$(./vector_prog)
rez=$?
all=all+1
if [[ "$TEST_OUTPUT" == "" ]]; then
	printf "$RED does not compile $DEFAULT \n"
else
	echo $TEST_OUTPUT
	point=point+rez
fi
rm -rf vector_prog
# 2
printf "$YELLOW Test iterators const $DEFAULT \n"
clang++	-Wall -Wextra -Werror	test_vector/vector_iterators/vector_iterators_iterator_const.cpp -o vector_prog
TEST_OUTPUT=$(./vector_prog)
rez=$?
all=all+1
if [[ "$TEST_OUTPUT" == "" ]]; then
	printf "$RED does not compile $DEFAULT \n"
else
	echo $TEST_OUTPUT
	point=point+rez
fi
rm -rf vector_prog
# 3
printf "$YELLOW Test reverse_iterators $DEFAULT \n"
clang++	-Wall -Wextra -Werror	test_vector/vector_iterators/vector_iterators_r_iterator.cpp -o vector_prog
TEST_OUTPUT=$(./vector_prog)
rez=$?
all=all+1
if [[ "$TEST_OUTPUT" == "" ]]; then
	printf "$RED does not compile $DEFAULT \n"
else
	echo $TEST_OUTPUT
	point=point+rez
fi
rm -rf vector_prog
# 4
printf "$YELLOW Test reverse_iterators const $DEFAULT \n"
clang++	-Wall -Wextra -Werror	test_vector/vector_iterators/vector_iterators_r_iterator_const.cpp -o vector_prog
TEST_OUTPUT=$(./vector_prog)
rez=$?
all=all+1
if [[ "$TEST_OUTPUT" == "" ]]; then
	printf "$RED does not compile $DEFAULT \n"
else
	echo $TEST_OUTPUT
	point=point+rez
fi
rm -rf vector_prog
'
#=========================================================================================
#============================Non-member function overloads================================
#=========================================================================================
printf "$PURPLE operator $DEFAULT \n"
#1
if [[ "$1" == "" ]] || [[ "$1" == "Non" ]] || [[ "$1" == "operator" ]]; then
	printf "$YELLOW Test operator $DEFAULT \n"
	clang++	-Wall -Wextra -Werror	test_vector/vector_operator/vector_operator_all.cpp -o vector_prog
	TEST_OUTPUT=$(./vector_prog)
	rez=$?
	all=all+1
	if [[ "$TEST_OUTPUT" == "" ]]; then
		printf "$RED does not compile $DEFAULT \n"
	else
		echo $TEST_OUTPUT
		point=point+rez
	fi
	rm -rf vector_prog
fi
#2
if [[ "$1" == "" ]] || [[ "$1" == "Non" ]] || [[ "$1" == "swap" ]] || [[ "$1" == "Non_swap" ]]; then
	printf "$YELLOW Test swap $DEFAULT \n"
	clang++	-Wall -Wextra -Werror	test_vector/vector_operator/vector_operator_swap.cpp -o vector_prog
	TEST_OUTPUT=$(./vector_prog)
	rez=$?
	all=all+1
	if [[ "$TEST_OUTPUT" == "" ]]; then
		printf "$RED does not compile $DEFAULT \n"
	else
		echo $TEST_OUTPUT
		point=point+rez
	fi
	rm -rf vector_prog
fi
#=========================================================================================
#===================================Modifiers=============================================
#=========================================================================================
printf "$PURPLE Modifiers $DEFAULT \n"
#1
if [[ "$1" == "" ]] || [[ "$1" == "Mod" ]] || [[ "$1" == "assign" ]]; then
	printf "$YELLOW Test assign $DEFAULT \n"
	clang++	-Wall -Wextra -Werror	test_vector/vector_modifiers/vector_modifiers_assign.cpp -o vector_prog
	TEST_OUTPUT=$(./vector_prog)
	rez=$?
	all=all+1
	if [[ "$TEST_OUTPUT" == "" ]]; then
		printf "$RED does not compile $DEFAULT \n"
	else
		echo $TEST_OUTPUT
		point=point+rez
	fi
	rm -rf vector_prog
fi
#2
if [[ "$1" == "" ]] || [[ "$1" == "Mod" ]] || [[ "$1" == "push_back" ]]; then
	printf "$YELLOW Test push_back $DEFAULT \n"
	clang++	-Wall -Wextra -Werror	test_vector/vector_modifiers/vector_modifiers_push_back.cpp -o vector_prog
	TEST_OUTPUT=$(./vector_prog)
	rez=$?
	all=all+1
	if [[ "$TEST_OUTPUT" == "" ]]; then
		printf "$RED does not compile $DEFAULT \n"
	else
		echo $TEST_OUTPUT
		point=point+rez
	fi
	rm -rf vector_prog
fi
#3
if [[ "$1" == "" ]] || [[ "$1" == "Mod" ]] || [[ "$1" == "pop_back" ]]; then
	printf "$YELLOW Test pop_back $DEFAULT \n"
	clang++	-Wall -Wextra -Werror	test_vector/vector_modifiers/vector_modifiers_pop_back.cpp -o vector_prog
	TEST_OUTPUT=$(./vector_prog)
	rez=$?
	all=all+1
	if [[ "$TEST_OUTPUT" == "" ]]; then
		printf "$RED does not compile $DEFAULT \n"
	else
		echo $TEST_OUTPUT
		point=point+rez
	fi
	rm -rf vector_prog
fi
#4.1
if [[ "$1" == "" ]] || [[ "$1" == "Mod" ]] || [[ "$1" == "insert" ]] || [[ "$1" == "insert_1" ]]; then
	printf "$YELLOW Test insert(iterator position, const value_type& val) $DEFAULT \n"
	clang++	-Wall -Wextra -Werror	test_vector/vector_modifiers/vector_modifiers_insert_1.cpp -o vector_prog
	TEST_OUTPUT=$(./vector_prog)
	rez=$?
	all=all+1
	if [[ "$TEST_OUTPUT" == "" ]]; then
		printf "$RED does not compile $DEFAULT \n"
	else
		echo $TEST_OUTPUT
		point=point+rez
	fi
	rm -rf vector_prog
fi
#4.2
if [[ "$1" == "" ]] || [[ "$1" == "Mod" ]] || [[ "$1" == "insert" ]] || [[ "$1" == "insert_2" ]]; then
	printf "$YELLOW Test insert(iterator position, size_type n, const value_type& val) $DEFAULT \n"
	clang++	-Wall -Wextra -Werror	test_vector/vector_modifiers/vector_modifiers_insert_2.cpp -o vector_prog
	TEST_OUTPUT=$(./vector_prog)
	rez=$?
	all=all+1
	if [[ "$TEST_OUTPUT" == "" ]]; then
		printf "$RED does not compile $DEFAULT \n"
	else
		echo $TEST_OUTPUT
		point=point+rez
	fi
	rm -rf vector_prog
fi
#4.3
if [[ "$1" == "" ]] || [[ "$1" == "Mod" ]] || [[ "$1" == "insert" ]] || [[ "$1" == "insert_3" ]]; then
	printf "$YELLOW Test insert(???) $DEFAULT \n"
	clang++	-Wall -Wextra -Werror	test_vector/vector_modifiers/vector_modifiers_insert_3.cpp -o vector_prog
	TEST_OUTPUT=$(./vector_prog)
	rez=$?
	all=all+1
	if [[ "$TEST_OUTPUT" == "" ]]; then
		printf "$RED does not compile $DEFAULT \n"
	else
		echo $TEST_OUTPUT
		point=point+rez
	fi
	rm -rf vector_prog
fi
#5.1
if [[ "$1" == "" ]] || [[ "$1" == "Mod" ]] || [[ "$1" == "erase" ]] || [[ "$1" == "erase_1" ]]; then
	printf "$YELLOW Test erase (1 arg) $DEFAULT \n"
	clang++	-Wall -Wextra -Werror	test_vector/vector_modifiers/vector_modifiers_erase_1.cpp -o vector_prog
	TEST_OUTPUT=$(./vector_prog)
	rez=$?
	all=all+1
	if [[ "$TEST_OUTPUT" == "" ]]; then
		printf "$RED does not compile $DEFAULT \n"
	else
		echo $TEST_OUTPUT
		point=point+rez
	fi
	rm -rf vector_prog
fi
#5.2
if [[ "$1" == "" ]] || [[ "$1" == "Mod" ]] || [[ "$1" == "erase" ]] || [[ "$1" == "erase_2" ]]; then
	printf "$YELLOW Test erase (2 arg) $DEFAULT \n"
	clang++	-Wall -Wextra -Werror	test_vector/vector_modifiers/vector_modifiers_erase_2.cpp -o vector_prog
	TEST_OUTPUT=$(./vector_prog)
	rez=$?
	all=all+1
	if [[ "$TEST_OUTPUT" == "" ]]; then
		printf "$RED does not compile $DEFAULT \n"
	else
		echo $TEST_OUTPUT
		point=point+rez
	fi
	rm -rf vector_prog
fi
#6
if [[ "$1" == "" ]] || [[ "$1" == "Mod" ]] || [[ "$1" == "swap" ]] || [[ "$1" == "Mod_swap" ]]; then
	printf "$YELLOW Test swap $DEFAULT \n"
	clang++	-Wall -Wextra -Werror	test_vector/vector_modifiers/vector_modifiers_swap.cpp -o vector_prog
	TEST_OUTPUT=$(./vector_prog)
	rez=$?
	all=all+1
	if [[ "$TEST_OUTPUT" == "" ]]; then
		printf "$RED does not compile $DEFAULT \n"
	else
		echo $TEST_OUTPUT
		point=point+rez
	fi
	rm -rf vector_prog
fi
#7
if [[ "$1" == "" ]] || [[ "$1" == "Mod" ]] || [[ "$1" == "clear" ]]; then
	printf "$YELLOW Test clear $DEFAULT \n"
	clang++	-Wall -Wextra -Werror	test_vector/vector_modifiers/vector_modifiers_clear.cpp -o vector_prog
	TEST_OUTPUT=$(./vector_prog)
	rez=$?
	all=all+1
	if [[ "$TEST_OUTPUT" == "" ]]; then
		printf "$RED does not compile $DEFAULT \n"
	else
		echo $TEST_OUTPUT
		point=point+rez
	fi
	rm -rf vector_prog
fi
#rez
echo "-------------------------------------"
printf "$PURPLE Finish\n $point/$all $DEFAULT \n"
