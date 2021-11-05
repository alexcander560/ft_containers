#include "../test_utility.cpp"

int	main ()
{
	std::string			temp_orig = "", temp_my = "";
	unsigned int		time_orig = 0, time_my = 0, rez = 0;
	std::vector<int>	orig_1(0);
	ft::vector<int>		my_1(0);
	std::vector<int>	orig_2(SIZE_100K);
	ft::vector<int>		my_2(SIZE_100K);

	orig_2.reserve(SIZE_1M);
	my_2.reserve(SIZE_1M);
	init_vector_all(&orig_1, &my_1);
	init_vector_all(&orig_2, &my_2);

	std::cout << "Test 1/3 (size = 0 (1 use))" << std::endl;
	time_orig = clock();
	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_1);
	orig_1.push_back(42);
	temp_orig += vektor_base_test(&orig_1);

	time_orig = clock() - time_orig;

	time_my = clock();
	//действия c собственной копией
	temp_my += vektor_base_test(&my_1);
	my_1.push_back(42);
	temp_my += vektor_base_test(&my_1);
	//temp_my += " ";
	
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	// //=============================================================
	std::cout << "Test 2/3 (size = 1 (100.000 use))" << std::endl;
	temp_orig = "", temp_my = "";
	time_orig = clock();
	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_1);
	for (size_t i = 0; i < SIZE_100K; i++)
		orig_1.push_back(666);
	temp_orig += vektor_base_test(&orig_1);

	time_orig = clock() - time_orig;

	time_my = clock();
	//действия c собственной копией
	temp_my += vektor_base_test(&my_1);
	for (size_t i = 0; i < SIZE_100K; i++)
		my_1.push_back(666);
	temp_my += vektor_base_test(&my_1);
	//temp_my += " ";
	
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "Test 3/3 (size = 100.000 capacity 1.000.000 (100.000 use))" << std::endl;
	temp_orig = "", temp_my = "";
	time_orig = clock();
	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_2);
	for (size_t i = 0; i < SIZE_100K; i++)
		orig_2.push_back(7);
	temp_orig += vektor_base_test(&orig_2);

	time_orig = clock() - time_orig;

	time_my = clock();
	//действия c собственной копией
	temp_my += vektor_base_test(&my_2);
	for (size_t i = 0; i < SIZE_100K; i++)
		my_2.push_back(7);
	temp_my += vektor_base_test(&my_2);
	//temp_my += " ";
	
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	return (!rez);
}
