#include "../test_utility_stack.cpp"

int	main ()
{
	std::string	temp_orig = "", temp_my = "";
	unsigned int time_orig = 0, time_my = 0, rez = 0;

	std::stack<int> orig_0;
	std::stack<int> orig_1;
	std::stack<int> orig_2;
	std::stack<int> orig_3;
	std::stack<int> orig_4;
	std::stack<int> orig_5;
	std::stack<int> orig_6;

	ft::stack<int> my_0;
	ft::stack<int> my_1;
	ft::stack<int> my_2;
	ft::stack<int> my_3;
	ft::stack<int> my_4;
	ft::stack<int> my_5;
	ft::stack<int> my_6;

	init_stack(&orig_0, &my_0, 0);
	init_stack(&orig_1, &my_1, 3 + SIZE_100K);
	init_stack(&orig_2, &my_2, 3 + SIZE_100K);
	init_stack(&orig_3, &my_3, 3 + SIZE_100K);
	init_stack(&orig_4, &my_4, 4 + SIZE_100K);
	init_stack(&orig_5, &my_5, 4 + SIZE_100K);
	init_stack(&orig_6, &my_6, 4 + SIZE_100K);

	orig_1.push(7); orig_1.push(2); orig_1.push(8);
	orig_2.push(7); orig_2.push(2); orig_2.push(7);
	orig_3.push(7); orig_3.push(2); orig_3.push(9);

	orig_4.push(7); orig_4.push(2); orig_4.push(8); orig_4.push(3);
	orig_5.push(7); orig_5.push(2); orig_5.push(7); orig_5.push(3);
	orig_6.push(7); orig_6.push(2); orig_6.push(9); orig_6.push(3);

	my_1.push(7); my_1.push(2); my_1.push(8);
	my_2.push(7); my_2.push(2); my_2.push(7);
	my_3.push(7); my_3.push(2); my_3.push(9);

	my_4.push(7); my_4.push(2); my_4.push(8); my_4.push(3);
	my_5.push(7); my_5.push(2); my_5.push(7); my_5.push(3);
	my_6.push(7); my_6.push(2); my_6.push(9); my_6.push(3);

	//=============================================================

	std::cout << "Test 1/6 (==)\n";
	temp_orig = "", temp_my = "";
	time_orig = clock();
	temp_orig += std::to_string(orig_1 == orig_0) + " ";
	temp_orig += std::to_string(orig_1 == orig_1) + " ";
	temp_orig += std::to_string(orig_1 == orig_2) + " ";
	temp_orig += std::to_string(orig_1 == orig_3) + " ";
	temp_orig += std::to_string(orig_1 == orig_4) + " ";
	temp_orig += std::to_string(orig_1 == orig_5) + " ";
	temp_orig += std::to_string(orig_1 == orig_6) + " ";
	//temp_orig += " or";
	time_orig = clock() - time_orig;
	time_my = clock();
	// code my
	temp_my += std::to_string(my_1 == my_0) + " ";
	temp_my += std::to_string(my_1 == my_1) + " ";
	temp_my += std::to_string(my_1 == my_2) + " ";
	temp_my += std::to_string(my_1 == my_3) + " ";
	temp_my += std::to_string(my_1 == my_4) + " ";
	temp_my += std::to_string(my_1 == my_5) + " ";
	temp_my += std::to_string(my_1 == my_6) + " ";
	//temp_my += " my";
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "Test 2/6 (!=)\n";
	temp_orig = "", temp_my = "";
	time_orig = clock();
	// code orig
	temp_orig += std::to_string(orig_1 != orig_0) + " ";
	temp_orig += std::to_string(orig_1 != orig_1) + " ";
	temp_orig += std::to_string(orig_1 != orig_2) + " ";
	temp_orig += std::to_string(orig_1 != orig_3) + " ";
	temp_orig += std::to_string(orig_1 != orig_4) + " ";
	temp_orig += std::to_string(orig_1 != orig_5) + " ";
	temp_orig += std::to_string(orig_1 != orig_6) + " ";
	//temp_orig += " or";
	time_orig = clock() - time_orig;
	time_my = clock();
	// code my
	temp_my += std::to_string(my_1 != my_0) + " ";
	temp_my += std::to_string(my_1 != my_1) + " ";
	temp_my += std::to_string(my_1 != my_2) + " ";
	temp_my += std::to_string(my_1 != my_3) + " ";
	temp_my += std::to_string(my_1 != my_4) + " ";
	temp_my += std::to_string(my_1 != my_5) + " ";
	temp_my += std::to_string(my_1 != my_6) + " ";
	//temp_my += " my";
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "Test 3/6 (<)\n";
	temp_orig = "", temp_my = "";
	time_orig = clock();
	// code orig
	temp_orig += std::to_string(orig_1 < orig_0) + " ";
	temp_orig += std::to_string(orig_1 < orig_1) + " ";
	temp_orig += std::to_string(orig_1 < orig_2) + " ";
	temp_orig += std::to_string(orig_1 < orig_3) + " ";
	temp_orig += std::to_string(orig_1 < orig_4) + " ";
	temp_orig += std::to_string(orig_1 < orig_5) + " ";
	temp_orig += std::to_string(orig_1 < orig_6) + " ";
	time_orig = clock() - time_orig;
	//temp_orig += " or";
	time_my = clock();
	// code my
	temp_my += std::to_string(my_1 < my_0) + " ";
	temp_my += std::to_string(my_1 < my_1) + " ";
	temp_my += std::to_string(my_1 < my_2) + " ";
	temp_my += std::to_string(my_1 < my_3) + " ";
	temp_my += std::to_string(my_1 < my_4) + " ";
	temp_my += std::to_string(my_1 < my_5) + " ";
	temp_my += std::to_string(my_1 < my_6) + " ";
	//temp_my += " my";
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "Test 4/6 (<=)\n";
	temp_orig = "", temp_my = "";
	time_orig = clock();
	// code orig
	temp_orig += std::to_string(orig_1 <= orig_0) + " ";
	temp_orig += std::to_string(orig_1 <= orig_1) + " ";
	temp_orig += std::to_string(orig_1 <= orig_2) + " ";
	temp_orig += std::to_string(orig_1 <= orig_3) + " ";
	temp_orig += std::to_string(orig_1 <= orig_4) + " ";
	temp_orig += std::to_string(orig_1 <= orig_5) + " ";
	temp_orig += std::to_string(orig_1 <= orig_6) + " ";
	//temp_orig += " or";
	time_orig = clock() - time_orig;
	time_my = clock();
	// code my
	temp_my += std::to_string(my_1 <= my_0) + " ";
	temp_my += std::to_string(my_1 <= my_1) + " ";
	temp_my += std::to_string(my_1 <= my_2) + " ";
	temp_my += std::to_string(my_1 <= my_3) + " ";
	temp_my += std::to_string(my_1 <= my_4) + " ";
	temp_my += std::to_string(my_1 <= my_5) + " ";
	temp_my += std::to_string(my_1 <= my_6) + " ";
	//temp_my += " my";
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "Test 5/6 (>)\n";
	temp_orig = "", temp_my = "";
	time_orig = clock();
	// code orig
	temp_orig += std::to_string(orig_1 > orig_0) + " ";
	temp_orig += std::to_string(orig_1 > orig_1) + " ";
	temp_orig += std::to_string(orig_1 > orig_2) + " ";
	temp_orig += std::to_string(orig_1 > orig_3) + " ";
	temp_orig += std::to_string(orig_1 > orig_4) + " ";
	temp_orig += std::to_string(orig_1 > orig_5) + " ";
	temp_orig += std::to_string(orig_1 > orig_6) + " ";
	//temp_orig += " or";
	time_orig = clock() - time_orig;
	time_my = clock();
	// code my
	temp_my += std::to_string(my_1 > my_0) + " ";
	temp_my += std::to_string(my_1 > my_1) + " ";
	temp_my += std::to_string(my_1 > my_2) + " ";
	temp_my += std::to_string(my_1 > my_3) + " ";
	temp_my += std::to_string(my_1 > my_4) + " ";
	temp_my += std::to_string(my_1 > my_5) + " ";
	temp_my += std::to_string(my_1 > my_6) + " ";
	//temp_my += " my";
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "Test 6/6 (>=)\n";
	temp_orig = "", temp_my = "";
	time_orig = clock();
	// code orig
	temp_orig += std::to_string(orig_1 >= orig_0) + " ";
	temp_orig += std::to_string(orig_1 >= orig_1) + " ";
	temp_orig += std::to_string(orig_1 >= orig_2) + " ";
	temp_orig += std::to_string(orig_1 >= orig_3) + " ";
	temp_orig += std::to_string(orig_1 >= orig_4) + " ";
	temp_orig += std::to_string(orig_1 >= orig_5) + " ";
	temp_orig += std::to_string(orig_1 >= orig_6) + " ";
	//temp_orig += " or";
	time_orig = clock() - time_orig;
	time_my = clock();
	// code my
	temp_my += std::to_string(my_1 >= my_0) + " ";
	temp_my += std::to_string(my_1 >= my_1) + " ";
	temp_my += std::to_string(my_1 >= my_2) + " ";
	temp_my += std::to_string(my_1 >= my_3) + " ";
	temp_my += std::to_string(my_1 >= my_4) + " ";
	temp_my += std::to_string(my_1 >= my_5) + " ";
	temp_my += std::to_string(my_1 >= my_6) + " ";
	//temp_my += " my";
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	
	//=============================================================

	return (!rez);
}
