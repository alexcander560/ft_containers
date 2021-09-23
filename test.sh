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

#=========================================================================================
#==============================Element access=============================================
#=========================================================================================
#: '
printf "$PURPLE Element access $DEFAULT\n"
# 1
printf "$YELLOW Test [] $DEFAULT \n"
clang++	-Wall -Wextra -Werror	test_funk/test_access/test_access_operator.cpp -o test_prog
TEST_OUTPUT=$(./test_prog)
all=all+1
if [[ "$TEST_OUTPUT" == "$TEST_COMP" ]]; then
	printf "$RED does not compile $DEFAULT \n"
else
	echo $TEST_OUTPUT
	point=point+1
fi
rm -rf test_prog
# 2
printf "$YELLOW Test [] const $DEFAULT \n"
clang++	-Wall -Wextra -Werror	test_funk/test_access/test_access_operator_const.cpp -o test_prog
TEST_OUTPUT=$(./test_prog)
all=all+1
if [[ "$TEST_OUTPUT" == "$TEST_COMP" ]]; then
	printf "$RED does not compile $DEFAULT \n"
else
	echo $TEST_OUTPUT
	point=point+1
fi
rm -rf test_prog
# 3
printf "$YELLOW Test at $DEFAULT \n"
echo $TEST_OUTPUT
clang++	-Wall -Wextra -Werror	test_funk/test_access/test_access_at.cpp -o test_prog
TEST_OUTPUT=$(./test_prog)
all=all+1
if [[ "$TEST_OUTPUT" == "$TEST_COMP" ]]; then
	printf "$RED does not compile $DEFAULT \n"
else
	echo $TEST_OUTPUT
	point=point+1
fi
rm -rf test_prog
# 4
printf "$YELLOW Test at const $DEFAULT \n"
clang++	-Wall -Wextra -Werror	test_funk/test_access/test_access_at_const.cpp -o test_prog
TEST_OUTPUT=$(./test_prog)
all=all+1
if [[ "$TEST_OUTPUT" == "$TEST_COMP" ]]; then
	printf "$RED does not compile $DEFAULT \n"
else
	echo $TEST_OUTPUT
	point=point+1
fi
rm -rf test_prog
# 5
printf "$YELLOW Test front $DEFAULT \n"
clang++	-Wall -Wextra -Werror	test_funk/test_access/test_access_front.cpp -o test_prog
TEST_OUTPUT=$(./test_prog)
all=all+1
if [[ "$TEST_OUTPUT" == "$TEST_COMP" ]]; then
	printf "$RED does not compile $DEFAULT \n"
else
	echo $TEST_OUTPUT
	point=point+1
fi
rm -rf test_prog
# 6
printf "$YELLOW Test front const $DEFAULT \n"
clang++	-Wall -Wextra -Werror	test_funk/test_access/test_access_front_const.cpp -o test_prog
TEST_OUTPUT=$(./test_prog)
all=all+1
if [[ "$TEST_OUTPUT" == "$TEST_COMP" ]]; then
	printf "$RED does not compile $DEFAULT \n"
else
	echo $TEST_OUTPUT
	point=point+1
fi
rm -rf test_prog
# 7
printf "$YELLOW Test back $DEFAULT \n"
clang++	-Wall -Wextra -Werror	test_funk/test_access/test_access_back.cpp -o test_prog
TEST_OUTPUT=$(./test_prog)
all=all+1
if [[ "$TEST_OUTPUT" == "$TEST_COMP" ]]; then
	printf "$RED does not compile $DEFAULT \n"
else
	echo $TEST_OUTPUT
	point=point+1
fi
rm -rf test_prog
# 8
printf "$YELLOW Test back const $DEFAULT \n"
clang++	-Wall -Wextra -Werror	test_funk/test_access/test_access_back_const.cpp -o test_prog
TEST_OUTPUT=$(./test_prog)
all=all+1
if [[ "$TEST_OUTPUT" == "$TEST_COMP" ]]; then
	printf "$RED does not compile $DEFAULT \n"
else
	echo $TEST_OUTPUT
	point=point+1
fi
rm -rf test_prog
#=========================================================================================
#====================================Capacity=============================================
#=========================================================================================
printf "$PURPLE Capacity $DEFAULT\n"
# 1
printf "$YELLOW Test size $DEFAULT \n"
clang++	-Wall -Wextra -Werror	test_funk/test_capacity/test_capacity_size.cpp -o test_prog
TEST_OUTPUT=$(./test_prog)
all=all+1
if [[ "$TEST_OUTPUT" == "$TEST_COMP" ]]; then
	printf "$RED does not compile $DEFAULT \n"
else
	echo $TEST_OUTPUT
	point=point+1
fi
rm -rf test_prog
# 2
printf "$YELLOW Test max_size $DEFAULT \n"
clang++	-Wall -Wextra -Werror	test_funk/test_capacity/test_capacity_max_size.cpp -o test_prog
TEST_OUTPUT=$(./test_prog)
all=all+1
if [[ "$TEST_OUTPUT" == "$TEST_COMP" ]]; then
	printf "$RED does not compile $DEFAULT \n"
else
	echo $TEST_OUTPUT
	point=point+1
fi
rm -rf test_prog
# 3
printf "$YELLOW Test capacity $DEFAULT \n"
clang++	-Wall -Wextra -Werror	test_funk/test_capacity/test_capacity_capacity.cpp -o test_prog
TEST_OUTPUT=$(./test_prog)
all=all+1
if [[ "$TEST_OUTPUT" == "$TEST_COMP" ]]; then
	printf "$RED does not compile $DEFAULT \n"
else
	echo $TEST_OUTPUT
	point=point+1
fi
rm -rf test_prog
# 4
printf "$YELLOW Test reserve $DEFAULT \n"
clang++	-Wall -Wextra -Werror	test_funk/test_capacity/test_capacity_reserve.cpp -o test_prog
TEST_OUTPUT=$(./test_prog)
all=all+1
if [[ "$TEST_OUTPUT" == "$TEST_COMP" ]]; then
	printf "$RED does not compile $DEFAULT \n"
else
	echo $TEST_OUTPUT
	point=point+1
fi
rm -rf test_prog
# 5
printf "$YELLOW Test empty $DEFAULT \n"
clang++	-Wall -Wextra -Werror	test_funk/test_capacity/test_capacity_empty.cpp -o test_prog
TEST_OUTPUT=$(./test_prog)
all=all+1
if [[ "$TEST_OUTPUT" == "$TEST_COMP" ]]; then
	printf "$RED does not compile $DEFAULT \n"
else
	echo $TEST_OUTPUT
	point=point+1
fi
rm -rf test_prog
# 6
printf "$YELLOW Test resize $DEFAULT \n"
clang++	-Wall -Wextra -Werror	test_funk/test_capacity/test_capacity_resize.cpp -o test_prog
TEST_OUTPUT=$(./test_prog)
all=all+1
if [[ "$TEST_OUTPUT" == "$TEST_COMP" ]]; then
	printf "$RED does not compile $DEFAULT \n"
else
	echo $TEST_OUTPUT
	point=point+1
fi
rm -rf test_prog

#=========================================================================================
#====================================Allocator============================================
#=========================================================================================
# 1
printf "$PURPLE allocator $DEFAULT\n"
printf "$YELLOW Test get_allocator $DEFAULT \n"
clang++	-Wall -Wextra -Werror	test_funk/test_allocator/test_allocator_get.cpp -o test_prog
TEST_OUTPUT=$(./test_prog)
all=all+1
if [[ "$TEST_OUTPUT" == "$TEST_COMP" ]]; then
	printf "$RED does not compile $DEFAULT \n"
else
	echo $TEST_OUTPUT
	point=point+1
fi
rm -rf test_prog

#=========================================================================================
#====================================Iterators============================================
#=========================================================================================
# 1
printf "$YELLOW Test iterators $DEFAULT \n"
clang++	-Wall -Wextra -Werror	test_funk/test_iterators/test_iterators_iterator.cpp -o test_prog
TEST_OUTPUT=$(./test_prog)
all=all+1
if [[ "$TEST_OUTPUT" == "$TEST_COMP" ]]; then
	printf "$RED does not compile $DEFAULT \n"
else
	echo $TEST_OUTPUT
	point=point+1
fi
rm -rf test_prog
# 2
printf "$YELLOW Test iterators const $DEFAULT \n"
clang++	-Wall -Wextra -Werror	test_funk/test_iterators/test_iterators_iterator_const.cpp -o test_prog
TEST_OUTPUT=$(./test_prog)
all=all+1
if [[ "$TEST_OUTPUT" == "$TEST_COMP" ]]; then
	printf "$RED does not compile $DEFAULT \n"
else
	echo $TEST_OUTPUT
	point=point+1
fi
rm -rf test_prog
# 3
printf "$YELLOW Test reverse_iterators const $DEFAULT \n"
clang++	-Wall -Wextra -Werror	test_funk/test_iterators/test_iterators_r_iterator.cpp -o test_prog
TEST_OUTPUT=$(./test_prog)
all=all+1
if [[ "$TEST_OUTPUT" == "$TEST_COMP" ]]; then
	printf "$RED does not compile $DEFAULT \n"
else
	echo $TEST_OUTPUT
	point=point+1
fi
rm -rf test_prog
# 4
printf "$YELLOW Test reverse_iterators const $DEFAULT \n"
clang++	-Wall -Wextra -Werror	test_funk/test_iterators/test_iterators_r_iterator_const.cpp -o test_prog
TEST_OUTPUT=$(./test_prog)
all=all+1
if [[ "$TEST_OUTPUT" == "$TEST_COMP" ]]; then
	printf "$RED does not compile $DEFAULT \n"
else
	echo $TEST_OUTPUT
	point=point+1
fi
rm -rf test_prog
#'
#=========================================================================================
#============================Non-member function overloads================================
#=========================================================================================
#1
printf "$YELLOW Test operator $DEFAULT \n"
clang++	-Wall -Wextra -Werror	test_funk/test_operator/test_operator_all.cpp -o test_prog
TEST_OUTPUT=$(./test_prog)
all=all+1
if [[ "$TEST_OUTPUT" == "$TEST_COMP" ]]; then
	printf "$RED does not compile $DEFAULT \n"
else
	echo $TEST_OUTPUT
	point=point+1
fi
rm -rf test_prog
#2
printf "$YELLOW Test swap $DEFAULT \n"
clang++	-Wall -Wextra -Werror	test_funk/test_operator/test_operator_swap.cpp -o test_prog
TEST_OUTPUT=$(./test_prog)
all=all+1
if [[ "$TEST_OUTPUT" == "$TEST_COMP" ]]; then
	printf "$RED does not compile $DEFAULT \n"
else
	echo $TEST_OUTPUT
	point=point+1
fi
rm -rf test_prog

#rez
echo "-------------------------------------"
printf "$PURPLE Finish\n $point/$all $DEFAULT \n"
