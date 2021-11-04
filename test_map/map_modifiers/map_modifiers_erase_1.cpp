#include "../test_utility_map.cpp"
#include <vector>

#define	TEST 0
#define	LEAK 0

int	test(int size, string test, bool random = false)
{
	string	temp_orig = "", temp_my = "";
	unsigned int time_orig = 0, time_my = 0, rez = 0, random_elem = 0, size_more = size * 10;
	std::map<int, string> orig;
	ft::map<int, string> my;
	ft::map<int, string>::iterator it_my;

	std::vector<int> base;
	if (random)
	{
		for (size_t i = 0; i < size; i++)
			base.push_back(rand() % size_more);
	}
	for (size_t i = 0; i < size; i++)
	{
		if (random)
		{
			orig.insert(std::pair<int, string>(base[i], to_string(base[i]) + "_"));
			my.insert(ft::pair<int, string>(base[i], to_string(base[i]) + "_"));
		}
		else
		{
			orig.insert(std::pair<int, string>(i, to_string(i) + "_"));
			my.insert(ft::pair<int, string>(i, to_string(i) + "_"));
		}
	}

	std::vector<int> vec_erase;
	for (size_t i = 0; i < size_more; i++)
		vec_erase.push_back(rand() % size_more);
	

	cout << test << endl;
	//===========================ORIG==============================
	time_orig = clock();
	
	temp_orig += "size=" + to_string(orig.size()) + " ";
	for (std::map<int, string>::iterator it = orig.begin(); it != orig.end(); it++)
		temp_orig += to_string(it->first) + it->second;

	for (size_t i = 0; i < size_more; i++)
	{
		if (orig.count(vec_erase[i]))
			orig.erase(orig.find(vec_erase[i]));
	}

	temp_orig += "size=" + to_string(orig.size()) + " ";
	for (std::map<int, string>::iterator it = orig.begin(); it != orig.end(); it++)
		temp_orig += to_string(it->first) + it->second;

	time_orig = clock() - time_orig;
	//============================MY===============================
	time_my = clock();

	temp_my += "size=" + to_string(my.size()) + " ";
	for (ft::map<int, string>::iterator it = my.begin(); it != my.end(); it++)
		temp_my += to_string(it->first) + it->second;

	for (size_t i = 0; i < size_more; i++)
	{
		if (my.count(vec_erase[i]))
			my.erase(my.find(vec_erase[i]));
	}
	
	temp_my += "size=" + to_string(my.size()) + " ";
	for (ft::map<int, string>::iterator it = my.begin(); it != my.end(); it++)
		temp_my += to_string(it->first) + it->second;

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
