#include "../test_utility_map.cpp"

#define	TEST 0
#define	LEAK 0

int	test_1()
{
	string	temp_orig = "", temp_my = "";
	unsigned int time_orig = 0, time_my = 0, rez = 0;
	std::map<int, string> orig;
	ft::map<int, string> my;

	cout << "Test 1" << endl;
	//===========================ORIG==============================
	time_orig = clock();
	temp_orig += std::to_string(orig.empty());
	time_orig = clock() - time_orig;
	//============================MY===============================
	time_my = clock();
	temp_my += std::to_string(my.empty());
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
	string	temp_orig = "", temp_my = "";
	unsigned int time_orig = 0, time_my = 0, rez = 0;
	std::map<int, string> orig;
	ft::map<int, string> my;

	orig.insert(std::pair<int, string>(42, "school"));
	my.insert(ft::pair<int, string>(42, "school"));

	cout << "Test 2" << endl;
	//===========================ORIG==============================
	time_orig = clock();
	temp_orig += std::to_string(orig.empty());
	time_orig = clock() - time_orig;
	//============================MY===============================
	time_my = clock();
	temp_my += std::to_string(my.empty());
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
	string	temp_orig = "", temp_my = "";
	unsigned int time_orig = 0, time_my = 0, rez = 0;
	std::map<int, string> orig;
	ft::map<int, string> my;

	for (size_t i = 0; i < SIZE_100K; i++)
	{
		orig.insert(std::pair<int, string>(i, "school"));
		my.insert(ft::pair<int, string>(i, "school"));
	}

	cout << "Test 3" << endl;
	//===========================ORIG==============================
	time_orig = clock();
	temp_orig += std::to_string(orig.empty());
	time_orig = clock() - time_orig;
	//============================MY===============================
	time_my = clock();
	temp_my += std::to_string(my.empty());
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
	//=============================================================
	if (LEAK)
		cin >> str_leaks;
	return (!rez);
}
