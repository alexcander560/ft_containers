#include "../test_utility.cpp"

int	main ()
{
	std::string			temp_orig = "", temp_my = "";
	unsigned int		time_orig = 0, time_my = 0, rez = 0;
	std::vector<int>	orig_1;
	ft::vector<int>		my_1;
	std::vector<int>	orig_2(SIZE_100K);
	ft::vector<int>		my_2(SIZE_100K);
	std::vector<int>	orig_3(orig_2);
	ft::vector<int>		my_3(my_2);

	init_vector_all(&orig_3, &my_3);
	std::vector<int>	orig_4(orig_3.begin() + 13, orig_3.end() - 42);
	ft::vector<int>		my_4(my_3.begin() + 13, my_3.end() - 42);

	//=============================================================
	std::cout << "Test 1/4 (size = 0)\n";

	time_orig = clock();
	temp_orig = std::to_string(orig_1.size());
	time_orig = clock() - time_orig;

	time_my = clock();
	temp_my = std::to_string(my_1.size());
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);

	//=============================================================
	std::cout << "Test 2/4 (size = 100K)\n";

	time_orig = clock();
	temp_orig = std::to_string(orig_2.size());
	time_orig = clock() - time_orig;

	time_my = clock();
	temp_my = std::to_string(my_2.size());
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);

	//=============================================================
	std::cout << "Test 3/4 (size = 100K copy)\n";

	time_orig = clock();
	temp_orig = std::to_string(orig_3.size());
	time_orig = clock() - time_orig;

	time_my = clock();
	temp_my = std::to_string(my_3.size());
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);

	//=============================================================
	std::cout << "Test 4/4 (size = 100K iter(99945))\n";

	time_orig = clock();
	temp_orig = std::to_string(orig_4.size());
	time_orig = clock() - time_orig;

	time_my = clock();
	temp_my = std::to_string(my_4.size());
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);

	//=============================================================

	return (!rez);
}
