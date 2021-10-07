#include "../test_utility.cpp"

int	main ()
{
	std::string	temp_orig = "", temp_my = "";
	unsigned int time_orig = 0, time_my = 0, rez = 0;

	std::cout << "Test 1" << std::endl;
	temp_orig = "", temp_my = "";
	std::vector<int> orig_1(1);
	ft::vector<int> my_1(1);
	init_vector_all(&orig_1, &my_1);

	time_orig = clock();
	temp_orig += std::to_string(orig_1.back()) + " ";
	time_orig = clock() - time_orig;

	time_my = clock();
	temp_my += std::to_string(my_1.back()) + " ";
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);

	//=============================================================

	std::cout << "Test 100K" << std::endl;
	std::vector<int> orig(SIZE_100K);
	ft::vector<int> my(SIZE_100K);
	init_vector_all(&orig, &my);

	time_orig = clock();
	for (size_t i = 0; i < SIZE_100K; i++)
		temp_orig += std::to_string(orig.back()) + " ";
	time_orig = clock() - time_orig;

	time_my = clock();
	for (size_t i = 0; i < SIZE_100K; i++)
		temp_my += std::to_string(my.back()) + " ";
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);

	return (!rez);
}
