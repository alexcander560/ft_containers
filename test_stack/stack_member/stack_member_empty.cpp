#include "../test_utility_stack.cpp"

#include <vector>

int	main ()
{
	std::string	temp_orig = "", temp_my = "";
	unsigned int time_orig = 0, time_my = 0, rez = 0;

	std::stack<int> orig_1;
	ft::stack<int> my_1;

	std::stack<int> orig_2;
	ft::stack<int> my_2;

	std::stack<int> orig_3;
	ft::stack<int> my_3;

	init_stack(&orig_1, &my_1, 0);
	init_stack(&orig_2, &my_2, 1);
	init_stack(&orig_3, &my_3, 10);

	//=============================================================
	std::cout << "empty size=0\n";
	temp_orig = "", temp_my = "";

	time_orig = clock();
	temp_orig += std::to_string(orig_1.empty());
	temp_orig += std::to_string(orig_1.empty());
	time_orig = clock() - time_orig;

	time_my = clock();
	temp_my += std::to_string(my_1.empty());
	temp_my += std::to_string(my_1.empty());
	time_my = clock() - time_my;
	//temp_my += " ";

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);

	//=============================================================
	std::cout << "empty size=1\n";
	temp_orig = "", temp_my = "";

	time_orig = clock();
	temp_orig += std::to_string(orig_2.empty());
	temp_orig += std::to_string(orig_2.empty());
	time_orig = clock() - time_orig;

	time_my = clock();
	temp_my += std::to_string(my_2.empty());
	temp_my += std::to_string(my_2.empty());
	time_my = clock() - time_my;
	//temp_my += " ";

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);

	//=============================================================
	std::cout << "empty size=10\n";
	temp_orig = "", temp_my = "";

	time_orig = clock();
	temp_orig += std::to_string(orig_3.empty());
	temp_orig += std::to_string(orig_3.empty());
	time_orig = clock() - time_orig;

	time_my = clock();
	temp_my += std::to_string(my_3.empty());
	temp_my += std::to_string(my_3.empty());
	time_my = clock() - time_my;
	//temp_my += " ";

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);

	//=============================================================

	return (!rez);
}
