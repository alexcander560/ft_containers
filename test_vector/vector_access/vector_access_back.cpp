#include "../test_utility.cpp"

#define	TEST 0
#define	LEAK 0

int	test(int size, string test)
{
	string				temp_orig = "", temp_my = "";
	unsigned int		time_orig = 0, time_my = 0, rez = 0;
	std::vector<int>	orig(size);
	ft::vector<int>		my(size);

	init_vector_all(&orig, &my);

	cout << test << endl;
	//===========================ORIG==============================
	time_orig = clock();

	for (int i = 0; i < size; i++)
		temp_orig += std::to_string(orig.back()) + " ";

	time_orig = clock() - time_orig;
	//============================MY===============================
	time_my = clock();

	for (int i = 0; i < size; i++)
		temp_my += std::to_string(my.back()) + " ";

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
	rez += test(SIZE_1, "Test 1/4");
	rez += test(SIZE_100, "Test 2/4");
	rez += test(SIZE_10K, "Test 3/4");
	rez += test(SIZE_100K, "Test 4/4");
	//=============================================================
	if (LEAK)
		cin >> str_leaks;
	return (!rez);
}
