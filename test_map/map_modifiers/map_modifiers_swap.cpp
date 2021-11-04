#include "../test_utility_map.cpp"

#define	TEST 0
#define	LEAK 0

int	test(std::map<int, string> orig_1, std::map<int, string> orig_2, ft::map<int, string> my_1, ft::map<int, string> my_2, string test)
{
	string	temp_orig = "", temp_my = "";
	unsigned int time_orig = 0, time_my = 0, rez = 0;

	cout << test << endl;
	//===========================ORIG==============================
	time_orig = clock();

	temp_orig += map_base_test(&orig_1);
	temp_orig += map_base_test(&orig_2);
	orig_1.swap(orig_1);
	orig_1.swap(orig_2);
	temp_orig += map_base_test(&orig_1);
	temp_orig += map_base_test(&orig_2);
	
	time_orig = clock() - time_orig;
	//============================MY===============================
	time_my = clock();
	
	temp_my += map_base_test(&my_1);
	temp_my += map_base_test(&my_2);
	my_1.swap(my_1);
	my_1.swap(my_2);
	temp_my += map_base_test(&my_1);
	temp_my += map_base_test(&my_2);

	if (TEST)
		temp_my += " ";

	time_my = clock() - time_my;
	//=============================================================
	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	return (rez);
}

int	main()
{
	string	str_leaks = "";
	int		rez = 0;

	//===========================ORIG==============================
	std::map<int, string> orig_0;
	std::map<int, string> orig_1;

	for (size_t i = 0; i < SIZE_10K; i++)
		orig_1.insert(std::pair<int, string>(i, to_string(i) + "_"));

	std::map<int, string> orig_2(orig_1);
	std::map<int, string> orig_3(orig_1);

	orig_1.insert(std::pair<int, string>(108, to_string(108) + "_"));
	orig_2.insert(std::pair<int, string>(107, to_string(107) + "_"));
	orig_3.insert(std::pair<int, string>(109, to_string(109) + "_"));

	std::map<int, string> orig_4(orig_1);
	std::map<int, string> orig_5(orig_2);
	std::map<int, string> orig_6(orig_3);

	orig_4.insert(std::pair<int, string>(103, to_string(103) + "_"));
	orig_5.insert(std::pair<int, string>(103, to_string(103) + "_"));
	orig_6.insert(std::pair<int, string>(103, to_string(103) + "_"));

	//============================MY===============================
	ft::map<int, string> my_0;
	ft::map<int, string> my_1;

	for (size_t i = 0; i < SIZE_10K; i++)
		my_1.insert(ft::pair<int, string>(i, to_string(i) + "_"));

	ft::map<int, string> my_2(my_1);
	ft::map<int, string> my_3(my_1);

	my_1.insert(ft::pair<int, string>(108, to_string(108) + "_"));
	my_2.insert(ft::pair<int, string>(107, to_string(107) + "_"));
	my_3.insert(ft::pair<int, string>(109, to_string(109) + "_"));

	ft::map<int, string> my_4(my_1);
	ft::map<int, string> my_5(my_2);
	ft::map<int, string> my_6(my_3);

	my_4.insert(ft::pair<int, string>(103, to_string(103) + "_"));
	my_5.insert(ft::pair<int, string>(103, to_string(103) + "_"));
	my_6.insert(ft::pair<int, string>(103, to_string(103) + "_"));
	//=============================================================

	// my_0.print_tree();
	// my_1.print_tree();
	// my_2.print_tree();
	// my_3.print_tree();
	// my_4.print_tree();
	// my_5.print_tree();
	// my_6.print_tree();

	rez += test(orig_1, orig_0, my_1, my_0, "Test 1/7");
	rez += test(orig_1, orig_1, my_1, my_1, "Test 2/7");
	rez += test(orig_1, orig_2, my_1, my_2, "Test 3/7");
	rez += test(orig_1, orig_3, my_1, my_3, "Test 4/7");
	rez += test(orig_1, orig_4, my_1, my_4, "Test 5/7");
	rez += test(orig_1, orig_5, my_1, my_5, "Test 6/7");
	rez += test(orig_1, orig_6, my_1, my_6, "Test 7/7");
	//=============================================================
	if (LEAK)
		cin >> str_leaks;
	return (!rez);
}
