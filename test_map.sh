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

#=========================================================================================
#==============================Element access=============================================
#=========================================================================================
if [[ "$1" == "" ]] || [[ "$1" == "Acc" ]]; then
	printf "$PURPLE Element access $DEFAULT\n"
fi
# 1
if [[ "$1" == "" ]] || [[ "$1" == "Acc" ]] || [[ "$1" == "acc" ]]; then
	printf "$YELLOW Test [] $DEFAULT \n"
	clang++	test_map/map_access/map_access_operator.cpp -o map_prog
	TEST_OUTPUT=$(./map_prog)
	rez=$?
	all=all+1
	if [[ "$TEST_OUTPUT" == "" ]]; then
		printf "$RED does not compile $DEFAULT \n"
	else
		echo $TEST_OUTPUT
		point=point+rez
	fi
	rm -rf map_prog
fi
#=========================================================================================
#====================================Capacity=============================================
#=========================================================================================
if [[ "$1" == "" ]] || [[ "$1" == "Cap" ]]; then
	printf "$PURPLE Capacity $DEFAULT\n"
fi
# 1
if [[ "$1" == "" ]] || [[ "$1" == "Cap" ]] || [[ "$1" == "size" ]]; then
	printf "$YELLOW Test size $DEFAULT \n"
	clang++	test_map/map_capacity/map_capacity_size.cpp -o map_prog
	TEST_OUTPUT=$(./map_prog)
	rez=$?
	all=all+1
	if [[ "$TEST_OUTPUT" == "" ]]; then
		printf "$RED does not compile $DEFAULT \n"
	else
		echo $TEST_OUTPUT
		point=point+rez
	fi
	rm -rf map_prog
fi
# 2
if [[ "$1" == "" ]] || [[ "$1" == "Cap" ]] || [[ "$1" == "max_size" ]]; then
	printf "$YELLOW Test max_size $DEFAULT \n"
	clang++	test_map/map_capacity/map_capacity_max_size.cpp -o map_prog
	TEST_OUTPUT=$(./map_prog)
	rez=$?
	all=all+1
	if [[ "$TEST_OUTPUT" == "" ]]; then
		printf "$RED does not compile $DEFAULT \n"
	else
		echo $TEST_OUTPUT
		point=point+rez
	fi
	rm -rf map_prog
fi
# 3
if [[ "$1" == "" ]] || [[ "$1" == "Cap" ]] || [[ "$1" == "empty" ]]; then
	printf "$YELLOW Test empty $DEFAULT \n"
	clang++	test_map/map_capacity/map_capacity_empty.cpp -o map_prog
	TEST_OUTPUT=$(./map_prog)
	rez=$?
	all=all+1
	if [[ "$TEST_OUTPUT" == "" ]]; then
		printf "$RED does not compile $DEFAULT \n"
	else
		echo $TEST_OUTPUT
		point=point+rez
	fi
	rm -rf map_prog
fi
#=========================================================================================
#====================================Allocator============================================
#=========================================================================================
if [[ "$1" == "" ]] || [[ "$1" == "Alloc" ]]; then
	printf "$PURPLE allocator $DEFAULT\n"
fi
# 1
if [[ "$1" == "" ]] || [[ "$1" == "Alloc" ]] || [[ "$1" == "get_allocator" ]]; then
	printf "$YELLOW Test get_allocator $DEFAULT \n"
	clang++	test_map/map_allocator/map_allocator_get.cpp -o map_prog
	TEST_OUTPUT=$(./map_prog)
	rez=$?
	all=all+1
	if [[ "$TEST_OUTPUT" == "" ]]; then
		printf "$RED does not compile $DEFAULT \n"
	else
		echo $TEST_OUTPUT
		point=point+rez
	fi
	rm -rf map_prog
fi
#=========================================================================================
#====================================Iterators============================================
#=========================================================================================
if [[ "$1" == "" ]] || [[ "$1" == "Iter" ]]; then
	printf "$PURPLE iterators $DEFAULT\n"
fi
# 1
if [[ "$1" == "" ]] || [[ "$1" == "Iter" ]] || [[ "$1" == "iterator" ]]; then
	printf "$YELLOW Test iterators $DEFAULT \n"
	clang++	test_map/map_iterators/map_iterators_iterator.cpp -o map_prog
	TEST_OUTPUT=$(./map_prog)
	rez=$?
	all=all+1
	if [[ "$TEST_OUTPUT" == "" ]]; then
		printf "$RED does not compile $DEFAULT \n"
	else
		echo $TEST_OUTPUT
		point=point+rez
	fi
	rm -rf map_prog
fi
# 2
if [[ "$1" == "" ]] || [[ "$1" == "Iter" ]] || [[ "$1" == "iterator_const" ]]; then
	printf "$YELLOW Test iterators const $DEFAULT \n"
	clang++	test_map/map_iterators/map_iterators_iterator_const.cpp -o map_prog
	TEST_OUTPUT=$(./map_prog)
	rez=$?
	all=all+1
	if [[ "$TEST_OUTPUT" == "" ]]; then
		printf "$RED does not compile $DEFAULT \n"
	else
		echo $TEST_OUTPUT
		point=point+rez
	fi
	rm -rf map_prog
fi
# 3
if [[ "$1" == "" ]] || [[ "$1" == "Iter" ]] || [[ "$1" == "r_iterator" ]]; then
	printf "$YELLOW Test reverse_iterators $DEFAULT \n"
	clang++	test_map/map_iterators/map_iterators_r_iterator.cpp -o map_prog
	TEST_OUTPUT=$(./map_prog)
	rez=$?
	all=all+1
	if [[ "$TEST_OUTPUT" == "" ]]; then
		printf "$RED does not compile $DEFAULT \n"
	else
		echo $TEST_OUTPUT
		point=point+rez
	fi
	rm -rf map_prog
fi
# 4
if [[ "$1" == "" ]] || [[ "$1" == "Iter" ]] || [[ "$1" == "r_iterator_const" ]]; then
	printf "$YELLOW Test reverse_iterators const $DEFAULT \n"
	clang++	test_map/map_iterators/map_iterators_r_iterator_const.cpp -o map_prog
	TEST_OUTPUT=$(./map_prog)
	rez=$?
	all=all+1
	if [[ "$TEST_OUTPUT" == "" ]]; then
		printf "$RED does not compile $DEFAULT \n"
	else
		echo $TEST_OUTPUT
		point=point+rez
	fi
	rm -rf map_prog
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
	clang++	test_map/map_operator/map_operator_all.cpp -o map_prog
	TEST_OUTPUT=$(./map_prog)
	rez=$?
	all=all+1
	if [[ "$TEST_OUTPUT" == "" ]]; then
		printf "$RED does not compile $DEFAULT \n"
	else
		echo $TEST_OUTPUT
		point=point+rez
	fi
	rm -rf map_prog
fi
#2
if [[ "$1" == "" ]] || [[ "$1" == "Non" ]] || [[ "$1" == "swap" ]] || [[ "$1" == "Non_swap" ]]; then
	printf "$YELLOW Test swap $DEFAULT \n"
	clang++	test_map/map_operator/map_operator_swap.cpp -o map_prog
	TEST_OUTPUT=$(./map_prog)
	rez=$?
	all=all+1
	if [[ "$TEST_OUTPUT" == "" ]]; then
		printf "$RED does not compile $DEFAULT \n"
	else
		echo $TEST_OUTPUT
		point=point+rez
	fi
	rm -rf map_prog
fi
#=========================================================================================
#===================================Modifiers=============================================
#=========================================================================================
if [[ "$1" == "" ]] || [[ "$1" == "Mod" ]]; then
	printf "$PURPLE Modifiers $DEFAULT \n"
fi
#1
if [[ "$1" == "" ]] || [[ "$1" == "Mod" ]] || [[ "$1" == "insert" ]] || [[ "$1" == "insert_1" ]]; then
	printf "$YELLOW Test insert(const value_type& val) $DEFAULT \n"
	clang++	test_map/map_modifiers/map_modifiers_insert_1.cpp -o map_prog
	TEST_OUTPUT=$(./map_prog)
	rez=$?
	all=all+1
	if [[ "$TEST_OUTPUT" == "" ]]; then
		printf "$RED does not compile $DEFAULT \n"
	else
		echo $TEST_OUTPUT
		point=point+rez
	fi
	rm -rf map_prog
fi
#1.2
if [[ "$1" == "" ]] || [[ "$1" == "Mod" ]] || [[ "$1" == "insert" ]] || [[ "$1" == "insert_2" ]]; then
	printf "$YELLOW Test insert(iterator position, const value_type& val) $DEFAULT \n"
	clang++	test_map/map_modifiers/map_modifiers_insert_2.cpp -o map_prog
	TEST_OUTPUT=$(./map_prog)
	rez=$?
	all=all+1
	if [[ "$TEST_OUTPUT" == "" ]]; then
		printf "$RED does not compile $DEFAULT \n"
	else
		echo $TEST_OUTPUT
		point=point+rez
	fi
	rm -rf map_prog
fi
#1.3
if [[ "$1" == "" ]] || [[ "$1" == "Mod" ]] || [[ "$1" == "insert" ]] || [[ "$1" == "insert_3" ]]; then
	printf "$YELLOW Test insert(InputIterator first, InputIterator last, typename enable_if<is_iterator<InputIterator>::value>::type* = 0) $DEFAULT \n"
	clang++	test_map/map_modifiers/map_modifiers_insert_3.cpp -o map_prog
	TEST_OUTPUT=$(./map_prog)
	rez=$?
	all=all+1
	if [[ "$TEST_OUTPUT" == "" ]]; then
		printf "$RED does not compile $DEFAULT \n"
	else
		echo $TEST_OUTPUT
		point=point+rez
	fi
	rm -rf map_prog
fi
#2.1
if [[ "$1" == "" ]] || [[ "$1" == "Mod" ]] || [[ "$1" == "erase" ]] || [[ "$1" == "erase_1" ]]; then
	printf "$YELLOW Test erase(iterator position) $DEFAULT \n"
	clang++	test_map/map_modifiers/map_modifiers_erase_1.cpp -o map_prog
	TEST_OUTPUT=$(./map_prog)
	rez=$?
	all=all+1
	if [[ "$TEST_OUTPUT" == "" ]]; then
		printf "$RED does not compile $DEFAULT \n"
	else
		echo $TEST_OUTPUT
		point=point+rez
	fi
	rm -rf map_prog
fi
#2.2
if [[ "$1" == "" ]] || [[ "$1" == "Mod" ]] || [[ "$1" == "erase" ]] || [[ "$1" == "erase_2" ]]; then
	printf "$YELLOW Test erase(const key_type& k) $DEFAULT \n"
	clang++	test_map/map_modifiers/map_modifiers_erase_2.cpp -o map_prog
	TEST_OUTPUT=$(./map_prog)
	rez=$?
	all=all+1
	if [[ "$TEST_OUTPUT" == "" ]]; then
		printf "$RED does not compile $DEFAULT \n"
	else
		echo $TEST_OUTPUT
		point=point+rez
	fi
	rm -rf map_prog
fi
#2.3
if [[ "$1" == "" ]] || [[ "$1" == "Mod" ]] || [[ "$1" == "erase" ]] || [[ "$1" == "erase_3" ]]; then
	printf "$YELLOW Test erase(iterator first, iterator last) $DEFAULT \n"
	clang++	test_map/map_modifiers/map_modifiers_erase_2.cpp -o map_prog
	TEST_OUTPUT=$(./map_prog)
	rez=$?
	all=all+1
	if [[ "$TEST_OUTPUT" == "" ]]; then
		printf "$RED does not compile $DEFAULT \n"
	else
		echo $TEST_OUTPUT
		point=point+rez
	fi
	rm -rf map_prog
fi
#3
if [[ "$1" == "" ]] || [[ "$1" == "Mod" ]] || [[ "$1" == "swap" ]] || [[ "$1" == "Mod_swap" ]]; then
	printf "$YELLOW Test swap $DEFAULT \n"
	clang++	test_map/map_modifiers/map_modifiers_swap.cpp -o map_prog
	TEST_OUTPUT=$(./map_prog)
	rez=$?
	all=all+1
	if [[ "$TEST_OUTPUT" == "" ]]; then
		printf "$RED does not compile $DEFAULT \n"
	else
		echo $TEST_OUTPUT
		point=point+rez
	fi
	rm -rf map_prog
fi
#4
if [[ "$1" == "" ]] || [[ "$1" == "Mod" ]] || [[ "$1" == "clear" ]]; then
	printf "$YELLOW Test clear $DEFAULT \n"
	clang++	test_map/map_modifiers/map_modifiers_clear.cpp -o map_prog
	TEST_OUTPUT=$(./map_prog)
	rez=$?
	all=all+1
	if [[ "$TEST_OUTPUT" == "" ]]; then
		printf "$RED does not compile $DEFAULT \n"
	else
		echo $TEST_OUTPUT
		point=point+rez
	fi
	rm -rf map_prog
fi
#=========================================================================================
#===================================Operations============================================
#=========================================================================================
if [[ "$1" == "" ]] || [[ "$1" == "Oper" ]]; then
	printf "$PURPLE Operations $DEFAULT\n"
fi
#1
if [[ "$1" == "" ]] || [[ "$1" == "Oper" ]] || [[ "$1" == "count" ]]; then
	printf "$YELLOW Test count $DEFAULT \n"
	clang++	test_map/map_operations/map_operations_count.cpp -o map_prog
	TEST_OUTPUT=$(./map_prog)
	rez=$?
	all=all+1
	if [[ "$TEST_OUTPUT" == "" ]]; then
		printf "$RED does not compile $DEFAULT \n"
	else
		echo $TEST_OUTPUT
		point=point+rez
	fi
	rm -rf map_prog
fi
#2
if [[ "$1" == "" ]] || [[ "$1" == "Oper" ]] || [[ "$1" == "equal_range" ]]; then
	printf "$YELLOW Test equal_range $DEFAULT \n"
	clang++	test_map/map_operations/map_operations_equal_range.cpp -o map_prog
	TEST_OUTPUT=$(./map_prog)
	rez=$?
	all=all+1
	if [[ "$TEST_OUTPUT" == "" ]]; then
		printf "$RED does not compile $DEFAULT \n"
	else
		echo $TEST_OUTPUT
		point=point+rez
	fi
	rm -rf map_prog
fi
#3
if [[ "$1" == "" ]] || [[ "$1" == "Oper" ]] || [[ "$1" == "equal_range_const" ]]; then
	printf "$YELLOW Test equal_range const $DEFAULT \n"
	clang++	test_map/map_operations/map_operations_equal_range_const.cpp -o map_prog
	TEST_OUTPUT=$(./map_prog)
	rez=$?
	all=all+1
	if [[ "$TEST_OUTPUT" == "" ]]; then
		printf "$RED does not compile $DEFAULT \n"
	else
		echo $TEST_OUTPUT
		point=point+rez
	fi
	rm -rf map_prog
fi
#4
if [[ "$1" == "" ]] || [[ "$1" == "Oper" ]] || [[ "$1" == "find" ]]; then
	printf "$YELLOW Test find $DEFAULT \n"
	clang++	test_map/map_operations/map_operations_find.cpp -o map_prog
	TEST_OUTPUT=$(./map_prog)
	rez=$?
	all=all+1
	if [[ "$TEST_OUTPUT" == "" ]]; then
		printf "$RED does not compile $DEFAULT \n"
	else
		echo $TEST_OUTPUT
		point=point+rez
	fi
	rm -rf map_prog
fi
#5
if [[ "$1" == "" ]] || [[ "$1" == "Oper" ]] || [[ "$1" == "find_const" ]]; then
	printf "$YELLOW Test find const $DEFAULT \n"
	clang++	test_map/map_operations/map_operations_find_const.cpp -o map_prog
	TEST_OUTPUT=$(./map_prog)
	rez=$?
	all=all+1
	if [[ "$TEST_OUTPUT" == "" ]]; then
		printf "$RED does not compile $DEFAULT \n"
	else
		echo $TEST_OUTPUT
		point=point+rez
	fi
	rm -rf map_prog
fi
#6
if [[ "$1" == "" ]] || [[ "$1" == "Oper" ]] || [[ "$1" == "lower_bound" ]]; then
	printf "$YELLOW Test lower_bound $DEFAULT \n"
	clang++	test_map/map_operations/map_operations_lower_bound.cpp -o map_prog
	TEST_OUTPUT=$(./map_prog)
	rez=$?
	all=all+1
	if [[ "$TEST_OUTPUT" == "" ]]; then
		printf "$RED does not compile $DEFAULT \n"
	else
		echo $TEST_OUTPUT
		point=point+rez
	fi
	rm -rf map_prog
fi
#7
if [[ "$1" == "" ]] || [[ "$1" == "Oper" ]] || [[ "$1" == "lower_bound_const" ]]; then
	printf "$YELLOW Test lower_bound const $DEFAULT \n"
	clang++	test_map/map_operations/map_operations_lower_bound_const.cpp -o map_prog
	TEST_OUTPUT=$(./map_prog)
	rez=$?
	all=all+1
	if [[ "$TEST_OUTPUT" == "" ]]; then
		printf "$RED does not compile $DEFAULT \n"
	else
		echo $TEST_OUTPUT
		point=point+rez
	fi
	rm -rf map_prog
fi
#8
if [[ "$1" == "" ]] || [[ "$1" == "Oper" ]] || [[ "$1" == "upper_bound" ]]; then
	printf "$YELLOW Test upper_bound $DEFAULT \n"
	clang++	test_map/map_operations/map_operations_upper_bound.cpp -o map_prog
	TEST_OUTPUT=$(./map_prog)
	rez=$?
	all=all+1
	if [[ "$TEST_OUTPUT" == "" ]]; then
		printf "$RED does not compile $DEFAULT \n"
	else
		echo $TEST_OUTPUT
		point=point+rez
	fi
	rm -rf map_prog
fi
#9
if [[ "$1" == "" ]] || [[ "$1" == "Oper" ]] || [[ "$1" == "upper_bound_const" ]]; then
	printf "$YELLOW Test upper_bound const $DEFAULT \n"
	clang++	test_map/map_operations/map_operations_upper_bound_const.cpp -o map_prog
	TEST_OUTPUT=$(./map_prog)
	rez=$?
	all=all+1
	if [[ "$TEST_OUTPUT" == "" ]]; then
		printf "$RED does not compile $DEFAULT \n"
	else
		echo $TEST_OUTPUT
		point=point+rez
	fi
	rm -rf map_prog
fi

#rez
echo "-------------------------------------"
printf "$PURPLE Finish\n $point/$all $DEFAULT \n"
