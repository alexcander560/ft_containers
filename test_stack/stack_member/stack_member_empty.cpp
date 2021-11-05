#include "../test_utility_stack.cpp"

#define	TEST 0
#define	LEAK 0

#include <vector>

int	test(int size, string test)
{
	string			temp_orig = "", temp_my = "";
	unsigned int	time_orig = 0, time_my = 0, rez = 0;
	std::stack<int>	orig;
	ft::stack<int>	my;

	init_stack(&orig, &my, size);

	cout << test << endl;
	//===========================ORIG==============================
	time_orig = clock();

	temp_orig += std::to_string(orig.empty());
	temp_orig += std::to_string(orig.empty());

	time_orig = clock() - time_orig;
	//============================MY===============================
	time_my = clock();

	temp_my += std::to_string(my.empty());
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
	rez += test(SIZE_0, "Test 1/3");
	rez += test(SIZE_1, "Test 2/3");
	rez += test(SIZE_10, "Test 3/3");
	//=============================================================
	if (LEAK)
		cin >> str_leaks;
	return (!rez);
}
