#include "../test_utility_map.cpp"
#include <vector>

#define	TEST 0
#define	LEAK 0

int	test(int size, string test, bool random = false)
{
	string	temp_orig = "", temp_my = "";
	unsigned int time_orig = 0, time_my = 0, rez = 0, rand_elem = 0;
	std::map<int, string> orig;
	ft::map<int, string> my;

	std::map<int, string> base_orig;
	ft::map<int, string> base_my;

	if (random)
	{
		for (size_t i = 0; i < size; i++)
		{
			rand_elem = rand();
			base_orig.insert(std::pair<int, string>(rand_elem, to_string(rand_elem) + "_"));
			base_my.insert(ft::pair<int, string>(rand_elem, to_string(rand_elem) + "_"));
		}
	}
	else
	{
		for (size_t i = 0; i < size; i++)
		{
			base_orig.insert(std::pair<int, string>(i, to_string(i) + "_"));
			base_my.insert(ft::pair<int, string>(i, to_string(i) + "_"));
		}
	}

	cout << test << endl;
	//===========================ORIG==============================
	time_orig = clock();
	temp_orig += to_string(orig.size()) + " ";
	
	orig.insert(orig.begin(), orig.begin());
	temp_orig += to_string(orig.size()) + " ";

	orig.insert(orig.end(), orig.end());
	temp_orig += to_string(orig.size()) + " ";

	orig.insert(orig.begin(), orig.end());
	temp_orig += to_string(orig.size()) + " ";

	orig.insert(base_orig.begin(), base_orig.begin());
	temp_orig += to_string(orig.size()) + " ";

	orig.insert(base_orig.end(), base_orig.end());
	temp_orig += to_string(orig.size()) + " ";

	orig.insert(base_orig.begin(), base_orig.end());
	temp_orig += to_string(orig.size()) + " ";
	for (std::map<int, string>::iterator it = orig.begin(); it != orig.end(); it++)
		temp_orig += to_string(it->first) + it->second;

	temp_orig += "size=" + to_string(orig.size());
	time_orig = clock() - time_orig;
	//============================MY===============================
	time_my = clock();
	temp_my += to_string(my.size()) + " ";
	
	my.insert(my.begin(), my.begin());
	temp_my += to_string(my.size()) + " ";

	my.insert(my.end(), my.end());
	temp_my += to_string(my.size()) + " ";

	my.insert(my.begin(), my.end());
	temp_my += to_string(my.size()) + " ";

	my.insert(base_my.begin(), base_my.begin());
	temp_my += to_string(my.size()) + " ";

	my.insert(base_my.end(), base_my.end());
	temp_my += to_string(my.size()) + " ";

	my.insert(base_my.begin(), base_my.end());
	temp_my += to_string(my.size()) + " ";
	for (ft::map<int, string>::iterator it = my.begin(); it != my.end(); it++)
		temp_my += to_string(it->first) + it->second;

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
	rez += test(SIZE_0, "Test 1/8");
	rez += test(SIZE_0, "Test 2/8", true);
	rez += test(SIZE_1, "Test 1/8");
	rez += test(SIZE_1, "Test 2/8", true);
	rez += test(SIZE_100, "Test 3/8");
	rez += test(SIZE_100, "Test 4/8", true);
	rez += test(SIZE_10K, "Test 5/8");
	rez += test(SIZE_10K, "Test 6/8", true);
	rez += test(SIZE_100K, "Test 7/8");
	rez += test(SIZE_100K, "Test 8/8", true);
	// rez += test(SIZE_1M, "Test 9");
	// rez += test(SIZE_1M, "Test 10", true);

	//=============================================================
	if (LEAK)
		cin >> str_leaks;
	return (!rez);
}
