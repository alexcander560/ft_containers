#include "../test_utility.cpp"

int	main ()
{
	std::string		temp_orig = "", temp_my = "";
	unsigned int	time_orig = 0, time_my = 0, rez = 0;

	//=============================================================

	std::cout << "Test 1/2" << std::endl;
	temp_orig = "", temp_my = "";
	std::vector<int> orig_1_base(1);
	ft::vector<int> my_1_base(1);
	init_vector_all(&orig_1_base, &my_1_base);

	const std::vector<int> orig_1(orig_1_base);
	const ft::vector<int> my_1(my_1_base);

	time_orig = clock();
	temp_orig += std::to_string(orig_1.front()) + " ";
	time_orig = clock() - time_orig;

	time_my = clock();
	temp_my += std::to_string(my_1.front()) + " ";
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);

	//=============================================================

	std::cout << "Test 2/2" << std::endl;
	std::vector<int> orig_base(SIZE_100K);
	ft::vector<int> my_base(SIZE_100K);
	init_vector_all(&orig_base, &my_base);

	const std::vector<int> orig(orig_1_base);
	const ft::vector<int> my(my_1_base);

	time_orig = clock();
	for (size_t i = 0; i < SIZE_100K; i++)
		temp_orig += std::to_string(orig.front()) + " ";
	time_orig = clock() - time_orig;

	time_my = clock();
	for (size_t i = 0; i < SIZE_100K; i++)
		temp_my += std::to_string(my.front()) + " ";
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);

	//=============================================================

	return (!rez);
}
