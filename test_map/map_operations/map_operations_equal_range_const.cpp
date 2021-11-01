#include "../test_utility_map.cpp"

#define	TEST 0
#define	LEAK 0

int	test_1()
{
	string	temp_orig = "", temp_my = "";
	unsigned int time_orig = 0, time_my = 0, rez = 0;
	std::map<int, string> orig;
	std::pair<std::map<int, string>::const_iterator, std::map<int, string>::const_iterator> orig_pair;
	ft::map<int, string> my;
	ft::pair<ft::map<int, string>::const_iterator, ft::map<int, string>::const_iterator> my_pair;

	orig.insert(std::pair<int, string>(42, "school_"));
	my.insert(ft::pair<int, string>(42, "school_"));

	std::map<int, string> const orig_const(orig);
	ft::map<int, string> const my_const(my);

	cout << "Test 1 (1 elem, 1 call)" << endl;
	//===========================ORIG==============================
	time_orig = clock();
	orig_pair = orig_const.equal_range(21);
	temp_orig += orig_pair.first->second + orig_pair.second->second + "|";

	time_orig = clock() - time_orig;
	//============================MY===============================
	time_my = clock();
	my_pair = my_const.equal_range(21);
	temp_my += my_pair.first->second + my_pair.second->second + "|";

	if (TEST)
		temp_my += " ";
	time_my = clock() - time_my;
	//=============================================================
	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	return (rez);
}

int	test_2()
{
	string	temp_orig = "", temp_my = "", num_str = "";
	unsigned int time_orig = 0, time_my = 0, rez = 0;
	std::map<int, string> orig;
	std::pair<std::map<int, string>::const_iterator, std::map<int, string>::const_iterator> orig_pair;
	ft::map<int, string> my;
	ft::pair<ft::map<int, string>::const_iterator, ft::map<int, string>::const_iterator> my_pair;

	for (size_t i = 2; i <= SIZE_200; i = i + 2)
	{
		num_str = to_string(i) + "_";
		orig.insert(std::pair<int, string>(i, num_str));
		my.insert(ft::pair<int, string>(i, num_str));
	}

	std::map<int, string> const orig_const(orig);
	ft::map<int, string> const my_const(my);

	cout << "Test 2 (100 elem, 201 call)" << endl;
	//===========================ORIG==============================
	time_orig = clock();

	orig_pair = orig_const.equal_range(-420);
	temp_orig += orig_pair.first->second + orig_pair.second->second + "|";

	for (int i = 0; i < SIZE_200; i++)
	{
		orig_pair = orig_const.equal_range(i);
		temp_orig += orig_pair.first->second + orig_pair.second->second + "|";
	}

	time_orig = clock() - time_orig;
	//============================MY===============================
	time_my = clock();
	
	my_pair = my_const.equal_range(-420);
	temp_my += my_pair.first->second + my_pair.second->second + "|";

	for (int i = 0; i < SIZE_200; i++)
	{
		my_pair = my_const.equal_range(i);
		temp_my += my_pair.first->second + my_pair.second->second + "|";
	}

	if (TEST)
		temp_my += " ";
	time_my = clock() - time_my;
	//=============================================================
	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	return (rez);
}

int	test_3()
{
	string	temp_orig = "", temp_my = "", num_str = "";
	unsigned int time_orig = 0, time_my = 0, rez = 0;
	std::map<int, string> orig;
	std::pair<std::map<int, string>::const_iterator, std::map<int, string>::const_iterator> orig_pair;
	ft::map<int, string> my;
	ft::pair<ft::map<int, string>::const_iterator, ft::map<int, string>::const_iterator> my_pair;

	for (size_t i = 2; i <= SIZE_20K; i = i + 2)
	{
		num_str = to_string(i) + "_";
		orig.insert(std::pair<int, string>(i, num_str));
		my.insert(ft::pair<int, string>(i, num_str));		
	}

	std::map<int, string> const orig_const(orig);
	ft::map<int, string> const my_const(my);

	cout << "Test 3 (10.000 elem, 20.001 call)" << endl;
	//===========================ORIG==============================
	time_orig = clock();

	orig_pair = orig_const.equal_range(-42000);
	temp_orig += orig_pair.first->second + orig_pair.second->second + "|";

	for (int i = 0; i < SIZE_20K; i++)
	{
		orig_pair = orig_const.equal_range(i);
		temp_orig += orig_pair.first->second + orig_pair.second->second + "|";
	}

	time_orig = clock() - time_orig;
	//============================MY===============================
	time_my = clock();
	
	my_pair = my_const.equal_range(-42000);
	temp_my += my_pair.first->second + my_pair.second->second + "|";

	for (int i = 0; i < SIZE_20K; i++)
	{
		my_pair = my_const.equal_range(i);
		temp_my += my_pair.first->second + my_pair.second->second + "|";
	}

	if (TEST)
		temp_my += " ";
	time_my = clock() - time_my;
	//=============================================================
	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	return (rez);
}

int	test_4()
{
	string	temp_orig = "", temp_my = "", num_str = "";
	unsigned int time_orig = 0, time_my = 0, rez = 0;
	std::map<int, string> orig;
	std::pair<std::map<int, string>::const_iterator, std::map<int, string>::const_iterator> orig_pair;
	ft::map<int, string> my;
	ft::pair<ft::map<int, string>::const_iterator, ft::map<int, string>::const_iterator> my_pair;

	for (size_t i = 2; i <= SIZE_2M; i = i + 2)
	{
		num_str = to_string(i) + "_";
		orig.insert(std::pair<int, string>(i, num_str));
		my.insert(ft::pair<int, string>(i, num_str));		
	}

	std::map<int, string> const orig_const(orig);
	ft::map<int, string> const my_const(my);

	cout << "Test 4 (1.000.000 elem, 2.000.001 call)" << endl;
	//===========================ORIG==============================
	time_orig = clock();

	orig_pair = orig_const.equal_range(-4200000);
	temp_orig += orig_pair.first->second + orig_pair.second->second + "|";

	for (int i = 0; i < SIZE_2M; i++)
	{
		orig_pair = orig_const.equal_range(i);
		temp_orig += orig_pair.first->second + orig_pair.second->second + "|";
	}

	time_orig = clock() - time_orig;
	//============================MY===============================
	time_my = clock();
	
	my_pair = my_const.equal_range(-4200000);
	temp_my += my_pair.first->second + my_pair.second->second + "|";

	for (int i = 0; i < SIZE_2M; i++)
	{
		my_pair = my_const.equal_range(i);
		temp_my += my_pair.first->second + my_pair.second->second + "|";
	}

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

	//=============================================================
	rez += test_1();
	rez += test_2();
	rez += test_3();
	rez += test_4();
	//=============================================================
	if (LEAK)
		cin >> str_leaks;
	return (!rez);
}
