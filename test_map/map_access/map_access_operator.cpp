#include "../test_utility_map.cpp"

#define	TEST 0
#define	LEAK 0

int	test(int size, string test)
{
	string	temp_orig = "", temp_my = "";
	unsigned int time_orig = 0, time_my = 0, rez = 0;
	std::map<int, string> orig;
	ft::map<int, string> my;

	for (size_t i = 0; i < size; i++)
	{
		orig.insert(std::pair<int, string>(i, to_string(i) + "_"));
		my.insert(ft::pair<int, string>(i, to_string(i) + "_"));
	}

	cout << test << endl;
	//===========================ORIG==============================
	time_orig = clock();
	for (int i = -1; i < size; i++)
		temp_orig += orig[i];
	time_orig = clock() - time_orig;
	//============================MY===============================
	time_my = clock();
	for (int i = -1; i < size; i++)
		temp_my += my[i];
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
	rez += test(SIZE_0, "Test 1");
	rez += test(SIZE_1, "Test 2");
	rez += test(SIZE_100, "Test 3");
	rez += test(SIZE_10K, "Test 4");
	rez += test(SIZE_100K, "Test 5");
	//rez += test(SIZE_1M, "Test 6");
	//=============================================================
	if (LEAK)
		cin >> str_leaks;
	return (!rez);
}
