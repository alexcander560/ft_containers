#include "../test_utility_stack.cpp"

int	main ()
{
	std::string	temp_orig = "", temp_my = "";
	unsigned int time_orig = 0, time_my = 0, rez = 0;
	size_t size = 100, size_pred = size - 1;

	std::stack<int> orig_1;
	ft::stack<int> my_1;

	init_stack(&orig_1, &my_1, 100);
	
	//=============================================================
	std::cout << "Test 1/1\n";
	temp_orig = "", temp_my = "";

	time_orig = clock();
	for (size_t i = 0; i < size_pred; i++)
	{
		temp_orig += stack_base_test(&orig_1);
		orig_1.pop();
		temp_orig += stack_base_test(&orig_1);
	}
	orig_1.pop();
	temp_orig += " size=" + std::to_string(orig_1.size());

	time_orig = clock() - time_orig;

	time_my = clock();
	for (size_t i = 0; i < size_pred; i++)
	{
		temp_my += stack_base_test(&my_1);
		my_1.pop();
		temp_my += stack_base_test(&my_1);
	}
	my_1.pop();
	temp_my += " size=" + std::to_string(my_1.size());
	time_my = clock() - time_my;
	//temp_my += " ";

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);

	//=============================================================

	return (!rez);
}
