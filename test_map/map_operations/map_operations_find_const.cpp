#include "../test_utility_map.cpp"

#define	TEST 0
#define	LEAK 0

int	test_1()
{
	string	temp_orig = "", temp_my = "";
	unsigned int time_orig = 0, time_my = 0, rez = 0;
	std::map<int, string> orig;
	ft::map<int, string> my;

	orig.insert(std::pair<int, string>(42, "school"));
	my.insert(ft::pair<int, string>(42, "school"));

	std::map<int, string> const orig_const(orig);
	ft::map<int, string> const my_const(my);

	cout << "Test 1 (1 elem, 1 call)" << endl;
	//===========================ORIG==============================
	time_orig = clock();
	temp_orig += orig_const.find(42)->second;
	time_orig = clock() - time_orig;
	//============================MY===============================
	time_my = clock();
	temp_my += my_const.find(42)->second;
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
	ft::map<int, string> my;

	for (size_t i = 0; i < SIZE_100; i++)
	{
		num_str = to_string(i) + "_";
		orig.insert(std::pair<int, string>(i, num_str));
		my.insert(ft::pair<int, string>(i, num_str));
	}

	std::map<int, string> const orig_const(orig);
	ft::map<int, string> const my_const(my);

	cout << "Test 2 (100 elem, 100 cal)" << endl;
	//===========================ORIG==============================
	time_orig = clock();
	for (size_t i = 0; i < SIZE_100; i++)
		temp_orig += orig_const.find(i)->second;
	time_orig = clock() - time_orig;
	//============================MY===============================
	time_my = clock();
	for (size_t i = 0; i < SIZE_100; i++)
		temp_my += my_const.find(i)->second;
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
	ft::map<int, string> my;

	for (size_t i = 0; i < SIZE_10K; i++)
	{
		num_str = to_string(i) + "_";
		orig.insert(std::pair<int, string>(i, num_str));
		my.insert(ft::pair<int, string>(i, num_str));
	}

	std::map<int, string> const orig_const(orig);
	ft::map<int, string> const my_const(my);

	cout << "Test 3 (10.000 elem, 10.000 cal)" << endl;
	//===========================ORIG==============================
	time_orig = clock();
	for (size_t i = 0; i < SIZE_10K; i++)
		temp_orig += orig_const.find(i)->second;
	time_orig = clock() - time_orig;
	//============================MY===============================
	time_my = clock();
	for (size_t i = 0; i < SIZE_10K; i++)
		temp_my += my_const.find(i)->second;
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
	ft::map<int, string> my;

	for (size_t i = 0; i < SIZE_1M; i++)
	{
		num_str = to_string(i) + "_";
		orig.insert(std::pair<int, string>(i, num_str));
		my.insert(ft::pair<int, string>(i, num_str));
	}

	std::map<int, string> const orig_const(orig);
	ft::map<int, string> const my_const(my);


	cout << "Test 4 (1.000.000 elem, 1.000.000 cal)" << endl;
	//===========================ORIG==============================
	time_orig = clock();
	for (size_t i = 0; i < SIZE_1M; i++)
		temp_orig += orig_const.find(i)->second;
	time_orig = clock() - time_orig;
	//============================MY===============================
	time_my = clock();
	for (size_t i = 0; i < SIZE_1M; i++)
		temp_my += my_const.find(i)->second;
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
