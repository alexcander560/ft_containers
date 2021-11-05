#include "../test_utility.cpp"

int	main ()
{
	std::string			temp_orig = "", temp_my = "";
	unsigned int		time_orig = 0, time_my = 0, rez = 0;
	std::vector<int>	orig_1;
	ft::vector<int>		my_1;

	init_vector_all(&orig_1, &my_1);
	//=============================================================
	std::cout << "Test 1/6 (size = 0 resize(0))\n";

	time_orig = clock();
	orig_1.resize(0);
	temp_orig = "size=" + std::to_string(orig_1.size()) + "capacity=" + std::to_string(orig_1.capacity()) + "elem=";
	time_orig = clock() - time_orig;

	time_my = clock();
	my_1.resize(0);
	temp_my = "size=" + std::to_string(my_1.size()) + "capacity=" + std::to_string(my_1.capacity()) + "elem=";
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "Test 2/6 (size = 0 resize(1000))\n";

	time_orig = clock();
	orig_1.resize(SIZE_1K);
	temp_orig = "size=" + std::to_string(orig_1.size()) + "capacity=" + std::to_string(orig_1.capacity()) + "elem=";
	for (size_t i = 0; i < SIZE_1K; i++)
		temp_orig += std::to_string(orig_1[i]) + " ";
	time_orig = clock() - time_orig;

	time_my = clock();
	my_1.resize(SIZE_1K);
	temp_my = "size=" + std::to_string(my_1.size()) + "capacity=" + std::to_string(my_1.capacity()) + "elem=";
	for (size_t i = 0; i < SIZE_1K; i++)
		temp_my += std::to_string(my_1[i]) + " ";
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "Test 3/6 (size = 1000 resize(100))\n";

	time_orig = clock();
	orig_1.resize(SIZE_100);
	temp_orig = "size=" + std::to_string(orig_1.size()) + "capacity=" + std::to_string(orig_1.capacity()) + "elem=";
	for (size_t i = 0; i < SIZE_100; i++)
		temp_orig += std::to_string(orig_1[i]) + " ";

	time_orig = clock() - time_orig;

	time_my = clock();
	my_1.resize(SIZE_100);
	temp_my = "size=" + std::to_string(my_1.size()) + "capacity=" + std::to_string(my_1.capacity()) + "elem=";
	for (size_t i = 0; i < SIZE_100; i++)
		temp_my += std::to_string(my_1[i]) + " ";
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	//=============================================================
	//=============================================================
	std::cout << "Test 4/6 (size = 100 resize(0, 42))\n";

	time_orig = clock();
	orig_1.resize(0, 42);
	temp_orig = "size=" + std::to_string(orig_1.size()) + "capacity=" + std::to_string(orig_1.capacity()) + "elem=";
	time_orig = clock() - time_orig;

	time_my = clock();
	my_1.resize(0, 42);
	temp_my = "size=" + std::to_string(my_1.size()) + "capacity=" + std::to_string(my_1.capacity()) + "elem=";
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "Test 5/6 (size = 0 resize(1000, 42))\n";

	time_orig = clock();
	orig_1.resize(SIZE_1K, 42);
	temp_orig = "size=" + std::to_string(orig_1.size()) + "capacity=" + std::to_string(orig_1.capacity()) + "elem=";
	for (size_t i = 0; i < SIZE_1K; i++)
		temp_orig += std::to_string(orig_1[i]) + " ";
	time_orig = clock() - time_orig;

	time_my = clock();
	my_1.resize(SIZE_1K, 42);
	temp_my = "size=" + std::to_string(my_1.size()) + "capacity=" + std::to_string(my_1.capacity()) + "elem=";
	for (size_t i = 0; i < SIZE_1K; i++)
		temp_my += std::to_string(my_1[i]) + " ";
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "Test 6/6 (size = 1000 resize(100, 42))\n";

	time_orig = clock();
	orig_1.resize(SIZE_100, 42);
	temp_orig = "size=" + std::to_string(orig_1.size()) + "capacity=" + std::to_string(orig_1.capacity()) + "elem=";
	for (size_t i = 0; i < SIZE_100; i++)
		temp_orig += std::to_string(orig_1[i]) + " ";
	time_orig = clock() - time_orig;

	time_my = clock();
	my_1.resize(SIZE_100, 42);
	temp_my = "size=" + std::to_string(my_1.size()) + "capacity=" + std::to_string(my_1.capacity()) + "elem=";
	for (size_t i = 0; i < SIZE_100; i++)
		temp_my += std::to_string(my_1[i]) + " ";
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	return (!rez);
}
