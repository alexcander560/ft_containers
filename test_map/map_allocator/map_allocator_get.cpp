#include "../test_utility_map.cpp"

#define	TEST 0
#define	LEAK 0

int	test(string test)
{
	string					temp_orig = "", temp_my = "";
	unsigned int			time_orig = 0, time_my = 0, rez = 0;
	std::map<int, string>	orig;
	ft::map<int, string>	my;

	//orig.insert(std::pair<int, string>(42, "school"));

	cout << test << endl;
	//===========================ORIG==============================
	time_orig = clock();

	std::map<int, string> orig_copy;

	if (orig.get_allocator() == orig_copy.get_allocator())
		temp_orig += "(yes)";
	else
		temp_orig += "(no)";

	orig.insert(std::pair<int, string>(42, "school"));

	if (orig.get_allocator() == orig_copy.get_allocator())
		temp_orig += "(yes)";
	else
		temp_orig += "(no)";

	time_orig = clock() - time_orig;
	//============================MY===============================
	time_my = clock();

	ft::map<int, string> my_copy;

	if (my.get_allocator() == my_copy.get_allocator())
		temp_my += "(yes)";
	else
		temp_my += "(no)";

	my.insert(ft::pair<int, string>(42, "school"));

	if (my.get_allocator() == my_copy.get_allocator())
		temp_my += "(yes)";
	else
		temp_my += "(no)";

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
	rez += test("Test 1/1");
	//=============================================================
	if (LEAK)
		cin >> str_leaks;
	return (!rez);
}
