#include "../test_utility.cpp"

int	main ()
{
	int new_size = SIZE_100 + 10;

	//=============================================================
	std::string	temp_orig = "", temp_my = "";
	unsigned int time_orig = 0, time_my = 0, rez = 0;
	std::vector<int> orig_base(SIZE_100);
	ft::vector<int> my_base(SIZE_100);

	init_vector_all(&orig_base, &my_base);
	const std::vector<int> orig(orig_base);
	const ft::vector<int> my(my_base);

	time_orig = clock();
	for (int i = -10; i < new_size; i++)
	{
		try { temp_orig += std::to_string(orig.at(i)) + " "; }
		catch(const std::exception& e) { temp_orig += e.what(); }
	}
	time_orig = clock() - time_orig;
	time_my = clock();
	for (int i = -10; i < new_size; i++)
	{
		try { temp_my += std::to_string(my.at(i)) + " "; }
		catch(const std::exception& e) {temp_my += e.what(); }
	}
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================

	return (!rez);
}
