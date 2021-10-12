#include "../test_utility.cpp"

int	main ()
{
	std::string	temp_orig = "", temp_my = "";
	unsigned int time_orig = 0, time_my = 0, rez = 0;

	std::vector<int> orig_base(SIZE_100K);
	ft::vector<int> my_base(SIZE_100K);
	
	const std::vector<int> orig(orig_base);
	const ft::vector<int> my(my_base);

	init_vector_all(&orig_base, &my_base);

	//=============================================================

	time_orig = clock();
	for (size_t i = 0; i < SIZE_100K; i++)
		temp_orig += std::to_string(orig[i]) + " ";
	time_orig = clock() - time_orig;

	time_my = clock();
	for (size_t i = 0; i < SIZE_100K; i++)
		temp_my += std::to_string(my[i]) + " ";
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);

	//=============================================================

	return (!rez);
}
