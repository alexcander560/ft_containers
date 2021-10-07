#include "../test_utility.cpp"

int	main ()
{
	std::string	temp_orig = "", temp_my = "";
	unsigned int time_orig = 0, time_my = 0, rez = 0;

	std::vector<int> orig_1;
	ft::vector<int> my_1;
	init_vector_all(&orig_1, &my_1);

	std::cout << "size = 0 reserve(0)\n";
	time_orig = clock();
	orig_1.reserve(0);
	temp_orig = "size=" + std::to_string(orig_1.size()) + "capacity=" + std::to_string(orig_1.capacity());
	time_orig = clock() - time_orig;
	my_1.reserve(0);
	time_my = clock();
	temp_my = "size=" + std::to_string(my_1.size()) + "capacity=" + std::to_string(my_1.capacity());
	time_my = clock() - time_my;
	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "size = 0 reserve(1000)\n";
	time_orig = clock();
	orig_1.reserve(SIZE_1K);
	temp_orig = "size=" + std::to_string(orig_1.size()) + "capacity=" + std::to_string(orig_1.capacity());
	// for (size_t i = 0; i < SIZE_1K; i++)
	// 	temp_orig += std::to_string(orig_1[i]) + " ";
	time_orig = clock() - time_orig;
	my_1.reserve(SIZE_1K);
	time_my = clock();
	temp_my = "size=" + std::to_string(my_1.size()) + "capacity=" + std::to_string(my_1.capacity());
	// for (size_t i = 0; i < SIZE_1K; i++)
	// 	temp_my += std::to_string(my_1[i]) + " ";
	time_my = clock() - time_my;
	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "size = 1000 reserve(100)\n";
	time_orig = clock();
	orig_1.reserve(SIZE_100);
	temp_orig = "size=" + std::to_string(orig_1.size()) + "capacity=" + std::to_string(orig_1.capacity());
	// for (size_t i = 0; i < SIZE_100; i++)
	// 	temp_orig += std::to_string(orig_1[i]) + " ";
	time_orig = clock() - time_orig;
	my_1.reserve(SIZE_100);
	time_my = clock();
	temp_my = "size=" + std::to_string(my_1.size()) + "capacity=" + std::to_string(my_1.capacity());
	// for (size_t i = 0; i < SIZE_100; i++)
	// 	temp_my += std::to_string(my_1[i]) + " ";
	time_my = clock() - time_my;
	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);

	return (!rez);
}
