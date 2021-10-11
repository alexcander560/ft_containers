#include "../test_utility.cpp"

int	main ()
{
	std::string	temp_orig = "", temp_my = "";
	unsigned int time_orig = 0, time_my = 0, rez = 0;

	std::vector<int> orig_1(0);
	ft::vector<int> my_1(0);
	init_vector_all(&orig_1, &my_1);

	//=============================================================
	std::cout << "size=0 assign (0, 42)" << std::endl;
	temp_orig = "", temp_my = "";

	time_orig = clock();
	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_1);
	orig_1.assign((size_t)0, 42);
	temp_orig += vektor_base_test(&orig_1);
	
	time_orig = clock() - time_orig;

	//----------------------------------------
	time_my = clock();
	//действия мои
	
	temp_my += vektor_base_test(&my_1);
	my_1.assign((size_t)0, 42);
	temp_my += vektor_base_test(&my_1);
	//temp_my += " ";

	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "size=0 assign (1, 42)" << std::endl;
	temp_orig = "", temp_my = "";

	time_orig = clock();
	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_1);
	orig_1.assign((size_t)1, 42);
	temp_orig += vektor_base_test(&orig_1);
	
	time_orig = clock() - time_orig;

	//----------------------------------------
	time_my = clock();
	//действия мои
	
	temp_my += vektor_base_test(&my_1);
	my_1.assign((size_t)1, 42);
	temp_my += vektor_base_test(&my_1);
	//temp_my += " ";

	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "size=1 assign (100.000, 42)" << std::endl;
	temp_orig = "", temp_my = "";

	time_orig = clock();
	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_1);
	orig_1.assign((size_t)100000, 42);
	temp_orig += vektor_base_test(&orig_1);
	
	time_orig = clock() - time_orig;

	//----------------------------------------
	time_my = clock();
	//действия мои
	
	temp_my += vektor_base_test(&my_1);
	my_1.assign((size_t)100000, 42);
	temp_my += vektor_base_test(&my_1);
	//temp_my += " ";

	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "size=100.000 assign (1, 42)" << std::endl;
	temp_orig = "", temp_my = "";

	time_orig = clock();
	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_1);
	orig_1.assign((size_t)1, 42);
	temp_orig += vektor_base_test(&orig_1);
	
	time_orig = clock() - time_orig;

	//----------------------------------------
	time_my = clock();
	//действия мои
	
	temp_my += vektor_base_test(&my_1);
	my_1.assign((size_t)1, 42);
	temp_my += vektor_base_test(&my_1);
	//temp_my += " ";

	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "size=1 assign (0, 42)" << std::endl;
	temp_orig = "", temp_my = "";

	time_orig = clock();
	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_1);
	orig_1.assign((size_t)0, 42);
	temp_orig += vektor_base_test(&orig_1);
	
	time_orig = clock() - time_orig;

	//----------------------------------------
	time_my = clock();
	//действия мои
	
	temp_my += vektor_base_test(&my_1);
	my_1.assign((size_t)0, 42);
	temp_my += vektor_base_test(&my_1);
	//temp_my += " ";

	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================

	return (!rez);
}

