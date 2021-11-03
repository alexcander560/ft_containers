#include "../test_utility_map.cpp"
#include <vector>

#define	TEST 0
#define	LEAK 0

int	test(int size, string test, bool random = false)
{
	string	temp_orig = "", temp_my = "";
	unsigned int time_orig = 0, time_my = 0, rez = 0;
	std::map<int, string> orig;
	std::map<int, string>::iterator it_orig;
	ft::map<int, string> my;
	ft::map<int, string>::iterator it_my;

	std::vector<int> base;
	if (random)
	{
		for (size_t i = 0; i < size; i++)
			base.push_back(rand());
	}

	cout << test << endl;
	//===========================ORIG==============================
	time_orig = clock();
	temp_orig += to_string(orig.size()) + " ";
	
	for (size_t i = 0; i < size; i++)
	{
		if (random)
			it_orig = orig.insert(orig.end(), std::pair<int, string>(base[i], to_string(base[i]) + "_"));
		else
			it_orig = orig.insert(orig.end(), std::pair<int, string>(i, to_string(i) + "_"));

		temp_orig += to_string(it_orig->first) + it_orig->second;
	}

	temp_orig += "size=" + to_string(orig.size());
	time_orig = clock() - time_orig;
	//============================MY===============================
	time_my = clock();
	temp_my += to_string(my.size()) + " ";
	
	for (size_t i = 0; i < size; i++)
	{
		if (random)
			it_my = my.insert(my.end(), ft::pair<int, string>(base[i], to_string(base[i]) + "_"));
		else
			it_my = my.insert(my.end(), ft::pair<int, string>(i, to_string(i) + "_"));

		temp_my += to_string(it_my->first) + it_my->second;
	}

	temp_my += "size=" + to_string(my.size());
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

	srand(time(NULL));
	//=============================================================
	rez += test(SIZE_1, "Test 1");
	rez += test(SIZE_1, "Test 2", true);
	rez += test(SIZE_100, "Test 3");
	rez += test(SIZE_100, "Test 4", true);
	rez += test(SIZE_10K, "Test 5");
	rez += test(SIZE_10K, "Test 6", true);
	rez += test(SIZE_100K, "Test 7");
	rez += test(SIZE_100K, "Test 8", true);
	// rez += test(SIZE_1M, "Test 9");
	// rez += test(SIZE_1M, "Test 10", true);

	//=============================================================
	if (LEAK)
		cin >> str_leaks;
	return (!rez);
}
