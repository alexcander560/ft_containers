#include "../test_utility_map.cpp"

#define	TEST 0
#define	LEAK 0

int	test_oper(int size, string test)
{
	string	temp_orig = "", temp_my = "";
	unsigned int time_orig = 0, time_my = 0, rez = 0;
	std::map<int, string> orig;
	std::map<int, string>::const_reverse_iterator it_1_orig;
	std::map<int, string>::const_reverse_iterator it_2_orig;
	std::pair<int, string> pair_orig;

	ft::map<int, string> my;
	ft::map<int, string>::const_reverse_iterator it_1_my;
	ft::map<int, string>::const_reverse_iterator it_2_my;
	ft::pair<int, string> pair_my;

	for (size_t i = 0; i < size; i++)
	{
		orig.insert(std::pair<int, string>(i, to_string(i) + "_"));
		my.insert(ft::pair<int, string>(i, to_string(i) + "_"));
	}

	std::map<int, string> const orig_const(orig);
	ft::map<int, string> const my_const(my);

	cout << test << endl;
	//===========================ORIG==============================
	time_orig = clock();
	orig_const.rbegin() == orig_const.rend() ? temp_orig += "NO" : temp_orig += "YES";
	orig_const.rbegin() != orig_const.rend() ? temp_orig += "NO" : temp_orig += "YES";

	it_1_orig = orig_const.rbegin();
	it_2_orig = orig_const.rend();
	
	for (; it_1_orig != it_2_orig; it_1_orig++)
	{
		it_1_orig++;
		it_1_orig--;

		++it_1_orig;
		--it_1_orig;

		temp_orig += to_string(it_1_orig->first);
		temp_orig += it_1_orig->second;
		pair_orig = *it_1_orig;
		temp_orig += "(" + to_string(pair_orig.first) + "," + pair_orig.second + ")";
	}

	time_orig = clock() - time_orig;
	//============================MY===============================
	time_my = clock();
	my_const.rbegin() == my_const.rend() ? temp_my += "NO" : temp_my += "YES";
	my_const.rbegin() != my_const.rend() ? temp_my += "NO" : temp_my += "YES";

	it_1_my = my_const.rbegin();
	it_2_my = my_const.rend();

	for (; it_1_my != it_2_my; it_1_my++)
	{
		it_1_my++;
		it_1_my--;

		++it_1_my;
		--it_1_my;

		temp_my += to_string(it_1_my->first);
		temp_my += it_1_my->second;
		pair_my = *it_1_my;
		temp_my += "(" + to_string(pair_my.first) + "," + pair_my.second + ")";
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

	rez += test_oper(SIZE_1, "Test 1/3");
	rez += test_oper(SIZE_100, "Test 2/3");
	rez += test_oper(SIZE_10K, "Test 3/3");
	//rez += test_oper(SIZE_1M, "Test 4");

	if (LEAK)
		cin >> str_leaks;
	return (!rez);
}
