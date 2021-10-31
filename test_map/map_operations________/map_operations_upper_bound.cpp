#include "../test_utility_map.cpp"

#define	TEST 0
#define	LEAK 0

int	test_1()
{
	string	temp_orig = "", temp_my = "";
	unsigned int time_orig = 0, time_my = 0, rez = 0;
	std::map<int, string> orig;
	std::map<int, string>::iterator orig_it;
	ft::map<int, string> my;
	ft::map<int, string>::iterator my_it;

	orig.insert(std::pair<int, string>(42, "school_"));
	my.insert(ft::pair<int, string>(42, "school_"));

	cout << "Test 1 (1 elem, 3 call)" << endl;
	//===========================ORIG==============================
	time_orig = clock();
	temp_orig += orig.upper_bound(21)->second;
	orig_it = --orig.upper_bound(42);
	temp_orig += orig_it->second;
	orig_it = --orig.upper_bound(100);
	temp_orig += orig_it->second;

	time_orig = clock() - time_orig;
	//============================MY===============================
	time_my = clock();
	temp_my += my.upper_bound(21)->second;
	my_it = --my.upper_bound(42);
	temp_my += my_it->second;
	my_it = --my.upper_bound(100);
	temp_my += my_it->second;
	if (TEST)
		temp_my += " ";
	time_my = clock() - time_my;
	//=============================================================
	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	return (!rez);
}

int	test_2()
{
	string	temp_orig = "", temp_my = "", num_str = "";
	unsigned int time_orig = 0, time_my = 0, rez = 0;
	std::map<int, string> orig;
	std::map<int, string>::iterator orig_it;
	ft::map<int, string> my;
	ft::map<int, string>::iterator my_it;

	for (size_t i = 2; i <= SIZE_200; i = i + 2)
	{
		num_str = to_string(i) + "_";
		orig.insert(std::pair<int, string>(i, num_str));
		my.insert(ft::pair<int, string>(i, num_str));		
	}

	cout << "Test 2 (100 elem, 202 call)" << endl;
	//===========================ORIG==============================
	time_orig = clock();

	temp_orig += orig.upper_bound(-420)->second;

	for (int i = 0; i < SIZE_200; i++)
		temp_orig += orig.upper_bound(i)->second;

	orig_it = --orig.upper_bound(420);
	temp_orig += orig_it->second;

	time_orig = clock() - time_orig;
	//============================MY===============================
	time_my = clock();
	
	temp_my += my.upper_bound(-420)->second;

	for (int i = 0; i < SIZE_200; i++)
		temp_my += my.upper_bound(i)->second;

	my_it = --my.upper_bound(420);
	temp_my += my_it->second;

	if (TEST)
		temp_my += " ";
	time_my = clock() - time_my;
	//=============================================================
	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	return (!rez);
}

int	test_3()
{
	string	temp_orig = "", temp_my = "", num_str = "";
	unsigned int time_orig = 0, time_my = 0, rez = 0;
	std::map<int, string> orig;
	std::map<int, string>::iterator orig_it;
	ft::map<int, string> my;
	ft::map<int, string>::iterator my_it;

	for (size_t i = 2; i <= SIZE_20K; i = i + 2)
	{
		num_str = to_string(i) + "_";
		orig.insert(std::pair<int, string>(i, num_str));
		my.insert(ft::pair<int, string>(i, num_str));		
	}

	cout << "Test 3 (10.000 elem, 20.002 call)" << endl;
	//===========================ORIG==============================
	time_orig = clock();

	temp_orig += orig.upper_bound(-42000)->second;

	for (int i = 0; i < SIZE_20K; i++)
		temp_orig += orig.upper_bound(i)->second;

	orig_it = --orig.upper_bound(42000);
	temp_orig += orig_it->second;

	time_orig = clock() - time_orig;
	//============================MY===============================
	time_my = clock();
	
	temp_my += my.upper_bound(-42000)->second;

	for (int i = 0; i < SIZE_20K; i++)
		temp_my += my.upper_bound(i)->second;

	my_it = --my.upper_bound(42000);
	temp_my += my_it->second;

	if (TEST)
		temp_my += " ";
	time_my = clock() - time_my;
	//=============================================================
	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	return (!rez);
}

int	test_4()
{
	string	temp_orig = "", temp_my = "", num_str = "";
	unsigned int time_orig = 0, time_my = 0, rez = 0;
	std::map<int, string> orig;
	std::map<int, string>::iterator orig_it;
	ft::map<int, string> my;
	ft::map<int, string>::iterator my_it;

	for (size_t i = 2; i <= SIZE_2M; i = i + 2)
	{
		num_str = to_string(i) + "_";
		orig.insert(std::pair<int, string>(i, num_str));
		my.insert(ft::pair<int, string>(i, num_str));		
	}

	cout << "Test 4 (1.000.000 elem, 2.000.002 call)" << endl;
	//===========================ORIG==============================
	time_orig = clock();

	temp_orig += orig.upper_bound(-4200000)->second;

	for (int i = 0; i < SIZE_2M; i++)
		temp_orig += orig.upper_bound(i)->second;

	orig_it = --orig.upper_bound(4200000);
	temp_orig += orig_it->second;

	time_orig = clock() - time_orig;
	//============================MY===============================
	time_my = clock();
	
	temp_my += my.upper_bound(-4200000)->second;

	for (int i = 0; i < SIZE_2M; i++)
		temp_my += my.upper_bound(i)->second;

	my_it = --my.upper_bound(4200000);
	temp_my += my_it->second;

	if (TEST)
		temp_my += " ";
	time_my = clock() - time_my;
	//=============================================================
	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	return (!rez);
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
