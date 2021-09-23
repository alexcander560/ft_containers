#include "../test_utility.cpp"

int	main ()
{
	std::string	temp_orig = "", temp_my = "";
	unsigned int time_orig = 0, time_my = 0, rez = 0;

	std::vector<int> orig_1;
	ft::vector<int> my_1;

	std::vector<int> orig_2(SIZE_100K);
	ft::vector<int> my_2(SIZE_100K);

	std::vector<int> orig_3(orig_2);
	ft::vector<int> my_3(my_2);

	init_vector_all(&orig_3, &my_3);
	std::vector<int> orig_4(orig_3.begin() + 13, orig_3.end() - 42);
	ft::vector<int> my_4(my_3.begin() + 13, my_3.end() - 42);

	std::cout << "empty = 0\n";
	time_orig = clock();
	temp_orig = std::to_string(orig_1.empty());
	time_orig = clock() - time_orig;

	time_my = clock();
	temp_my = std::to_string(my_1.empty());
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);

	//=============================================================
	std::cout << "empty = 100K\n";
	time_orig = clock();
	temp_orig = std::to_string(orig_2.empty());
	time_orig = clock() - time_orig;

	time_my = clock();
	temp_my = std::to_string(my_2.empty());
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);

	//=============================================================
	std::cout << "empty = 100K copy\n";
	time_orig = clock();
	temp_orig = std::to_string(orig_3.empty());
	time_orig = clock() - time_orig;

	time_my = clock();
	temp_my = std::to_string(my_3.empty());
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);

	//=============================================================
	std::cout << "empty = 100K iter(99945)\n";
	time_orig = clock();
	temp_orig = std::to_string(orig_4.empty());
	time_orig = clock() - time_orig;

	time_my = clock();
	temp_my = std::to_string(my_4.empty());
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);

	return (rez);
}
