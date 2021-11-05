#include "../test_utility_map.cpp"

#define	TEST 0
#define	LEAK 0

int	test(int size, string test)
{
	string					temp_orig = "", temp_my = "", num_str = "";
	unsigned int			time_orig = 0, time_my = 0, rez = 0;
	std::map<int, string>	orig;
	ft::map<int, string>	my;
	std::pair<std::map<int, string>::const_iterator, std::map<int, string>::const_iterator>	orig_pair;
	ft::pair<ft::map<int, string>::const_iterator, ft::map<int, string>::const_iterator>	my_pair;

	for (int i = 2; i <= size; i = i + 2)
	{
		num_str = to_string(i) + "_";
		orig.insert(std::pair<int, string>(i, num_str));
		my.insert(ft::pair<int, string>(i, num_str));		
	}

	cout << test << endl;
	//===========================ORIG==============================
	time_orig = clock();

	orig_pair = orig.equal_range(-size);
	temp_orig += orig_pair.first->second + orig_pair.second->second + "|";

	for (int i = 0; i < size; i++)
	{
		orig_pair = orig.equal_range(i);
		temp_orig += orig_pair.first->second + orig_pair.second->second + "|";
	}

	time_orig = clock() - time_orig;
	//============================MY===============================
	time_my = clock();
	
	my_pair = my.equal_range(-size);
	temp_my += my_pair.first->second + my_pair.second->second + "|";

	for (int i = 0; i < size; i++)
	{
		my_pair = my.equal_range(i);
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
	rez += test(SIZE_2, "Test 1/4");
	rez += test(SIZE_200, "Test 2/4");
	rez += test(SIZE_20K, "Test 3/4");
	rez += test(SIZE_200K, "Test 4/4");
	//rez += test(SIZE_2M, "Test 5");
	//=============================================================
	if (LEAK)
		cin >> str_leaks;
	return (!rez);
}
