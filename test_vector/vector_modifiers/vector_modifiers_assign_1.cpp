#include "../test_utility.cpp"

int	main ()
{
	std::string	temp_orig = "", temp_my = "";
	unsigned int time_orig = 0, time_my = 0, rez = 0;

	std::vector<int> orig_1(0);
	ft::vector<int> my_1(0);
	init_vector_all(&orig_1, &my_1);

	std::vector<int> orig_2(1);
	ft::vector<int> my_2(1);
	init_vector_all(&orig_2, &my_2);

	std::vector<int> orig_3(SIZE_100K);
	ft::vector<int> my_3(SIZE_100K);
	init_vector_all(&orig_3, &my_3);

	//=============================================================
	std::cout << "size=0 assign (begin(), end())" << std::endl;
	temp_orig = "", temp_my = "";

	time_orig = clock();
	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_1);
	orig_1.assign(orig_1.begin(),orig_1.end());
	temp_orig += vektor_base_test(&orig_1);
	
	time_orig = clock() - time_orig;

	//----------------------------------------
	time_my = clock();
	//действия мои
	
	temp_my += vektor_base_test(&my_1);
	my_1.assign(my_1.begin(), my_1.end());
	temp_my += vektor_base_test(&my_1);
	//temp_my += " ";

	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "size=0 assign (begin(), end())" << std::endl;
	temp_orig = "", temp_my = "";

	time_orig = clock();
	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_1);
	orig_1.assign(orig_2.begin(),orig_2.end());
	temp_orig += vektor_base_test(&orig_1);
	
	time_orig = clock() - time_orig;

	//----------------------------------------
	time_my = clock();
	//действия мои
	
	temp_my += vektor_base_test(&my_1);
	my_1.assign(my_2.begin(), my_2.end());
	temp_my += vektor_base_test(&my_1);
	//temp_my += " ";

	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "size=1 assign (begin(), end())" << std::endl;
	temp_orig = "", temp_my = "";

	time_orig = clock();
	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_1);
	orig_1.assign(orig_3.begin(),orig_3.end());
	temp_orig += vektor_base_test(&orig_1);
	
	time_orig = clock() - time_orig;

	//----------------------------------------
	time_my = clock();
	//действия мои
	
	temp_my += vektor_base_test(&my_1);
	my_1.assign(my_3.begin(), my_3.end());
	temp_my += vektor_base_test(&my_1);
	//temp_my += " ";

	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "size=100.000 assign (begin() + 30, end() - 50)" << std::endl;
	temp_orig = "", temp_my = "";

	time_orig = clock();
	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_1);
	orig_1.assign(orig_1.begin() + 30, orig_1.end() - 50);
	temp_orig += vektor_base_test(&orig_1);
	
	time_orig = clock() - time_orig;

	//----------------------------------------
	time_my = clock();
	//действия мои
	
	temp_my += vektor_base_test(&my_1);
	my_1.assign(my_1.begin() + 30, my_1.end() - 50);
	temp_my += vektor_base_test(&my_1);
	//temp_my += " ";

	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);

	//=============================================================
	std::cout << "size=99.920 assign (begin(), end())" << std::endl;
	temp_orig = "", temp_my = "";

	time_orig = clock();
	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_1);
	orig_1.assign(orig_3.begin(), orig_3.end());
	temp_orig += vektor_base_test(&orig_1);
	
	time_orig = clock() - time_orig;

	//----------------------------------------
	time_my = clock();
	//действия мои
	
	temp_my += vektor_base_test(&my_1);
	my_1.assign(my_3.begin(), my_3.end());
	temp_my += vektor_base_test(&my_1);
	//temp_my += " ";

	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "size=100.000 assign (begin() + 71832, begin() + 71833)" << std::endl;
	temp_orig = "", temp_my = "";

	time_orig = clock();
	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_1);
	orig_1.assign(orig_3.begin() + 71832, orig_3.begin() + 71833);
	temp_orig += vektor_base_test(&orig_1);
	
	time_orig = clock() - time_orig;

	//----------------------------------------
	time_my = clock();
	//действия мои
	
	temp_my += vektor_base_test(&my_1);
	my_1.assign(my_3.begin() + 71832, my_3.begin() + 71833);
	temp_my += vektor_base_test(&my_1);
	//temp_my += " ";

	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "size=1 assign (begin(), begin())" << std::endl;
	temp_orig = "", temp_my = "";

	time_orig = clock();
	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_1);
	orig_1.assign(orig_1.begin(), orig_1.begin());
	temp_orig += vektor_base_test(&orig_1);
	
	time_orig = clock() - time_orig;

	//----------------------------------------
	time_my = clock();
	//действия мои
	
	temp_my += vektor_base_test(&my_1);
	my_1.assign(my_1.begin(), my_1.begin());
	temp_my += vektor_base_test(&my_1);
	//temp_my += " ";

	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//============================================================
	//std::string str_leaks; std::cin >> str_leaks;

	return (!rez);
}
