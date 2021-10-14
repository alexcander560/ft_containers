#include "../test_utility_stack.cpp"

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

	std::stack<int> orig_4;
	ft::stack<int> my_4;

	init_stack(&orig_1, &my_1, 0);
	init_stack(&orig_2, &my_2, 1);
	init_stack(&orig_3, &my_3, 10);
	init_stack(&orig_4, &my_4, 100000);

	//=============================================================
	std::cout << "size=0\n";
	temp_orig = "", temp_my = "";

	time_orig = clock();
	temp_orig += std::to_string(orig_1.size());
	temp_orig += std::to_string(orig_1.size());
	time_orig = clock() - time_orig;

	time_my = clock();
	temp_my += std::to_string(my_1.size());
	temp_my += std::to_string(my_1.size());
	time_my = clock() - time_my;
	//temp_my += " ";

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);

	//=============================================================
	std::cout << "size=1\n";
	temp_orig = "", temp_my = "";

	time_orig = clock();
	temp_orig += std::to_string(orig_2.size());
	temp_orig += std::to_string(orig_2.size());
	time_orig = clock() - time_orig;

	time_my = clock();
	temp_my += std::to_string(my_2.size());
	temp_my += std::to_string(my_2.size());
	time_my = clock() - time_my;
	//temp_my += " ";

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);

	//=============================================================
	std::cout << "size=10\n";
	temp_orig = "", temp_my = "";

	time_orig = clock();
	temp_orig += std::to_string(orig_3.size());
	temp_orig += std::to_string(orig_3.size());
	time_orig = clock() - time_orig;

	time_my = clock();
	temp_my += std::to_string(my_3.size());
	temp_my += std::to_string(my_3.size());
	time_my = clock() - time_my;
	//temp_my += " ";

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);

	//=============================================================
	std::cout << "size=100000\n";
	temp_orig = "", temp_my = "";

	time_orig = clock();
	temp_orig += std::to_string(orig_4.size());
	temp_orig += std::to_string(orig_4.size());
	time_orig = clock() - time_orig;

	time_my = clock();
	temp_my += std::to_string(my_4.size());
	temp_my += std::to_string(my_4.size());
	time_my = clock() - time_my;
	//temp_my += " ";

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);

	//=============================================================

	return (!rez);
}
