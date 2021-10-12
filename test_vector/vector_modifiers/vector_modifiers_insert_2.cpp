#include "../test_utility.cpp"

int	main ()
{
	std::string	temp_orig = "", temp_my = "";
	unsigned int time_orig = 0, time_my = 0, rez = 0;

	std::vector<int> orig_1(0);
	ft::vector<int> my_1(0);
	std::vector<int> orig_2(SIZE_10);
	ft::vector<int> my_2(SIZE_10);

	init_vector_all(&orig_1, &my_1);
	init_vector_all(&orig_2, &my_2);

	//=============================================================
	std::cout << "size=0 insert(begin(), 0 , 42)" << std::endl;
	temp_orig = "", temp_my = "";
	time_orig = clock();

	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_1);
	orig_1.insert(orig_1.begin(), (size_t)0, 42);
	temp_orig += vektor_base_test(&orig_1);

	time_orig = clock() - time_orig;

	time_my = clock();
	
	//действия c собственной копией
	temp_my += vektor_base_test(&my_1);
	my_1.insert(my_1.begin(), (size_t)0, 42);
	temp_my += vektor_base_test(&my_1);
	//temp_my += " ";
	
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "size=0 insert(begin(), 1 , 42)" << std::endl;
	temp_orig = "", temp_my = "";
	time_orig = clock();

	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_1);
	orig_1.insert(orig_1.begin(), (size_t)1, 42);
	temp_orig += vektor_base_test(&orig_1);

	time_orig = clock() - time_orig;

	time_my = clock();
	
	//действия c собственной копией
	temp_my += vektor_base_test(&my_1);
	my_1.insert(my_1.begin(), (size_t)1, 42);
	temp_my += vektor_base_test(&my_1);
	//temp_my += " ";
	
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "size=1 insert(begin(), 0 , 42)" << std::endl;
	temp_orig = "", temp_my = "";
	time_orig = clock();

	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_1);
	orig_1.insert(orig_1.begin(), (size_t)0, 42);
	temp_orig += vektor_base_test(&orig_1);

	time_orig = clock() - time_orig;

	time_my = clock();
	
	//действия c собственной копией
	temp_my += vektor_base_test(&my_1);
	my_1.insert(my_1.begin(), (size_t)0, 42);
	temp_my += vektor_base_test(&my_1);
	//temp_my += " ";
	
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "size=1 insert(begin(), 100.000 , 42)" << std::endl;
	temp_orig = "", temp_my = "";
	time_orig = clock();

	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_1);
	orig_1.insert(orig_1.begin(), (size_t)SIZE_10, 42);
	temp_orig += vektor_base_test(&orig_1);

	time_orig = clock() - time_orig;

	time_my = clock();
	
	//действия c собственной копией
	temp_my += vektor_base_test(&my_1);
	my_1.insert(my_1.begin(), (size_t)SIZE_10, 42);
	temp_my += vektor_base_test(&my_1);
	//temp_my += " ";
	
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "size=100.001 insert(end(), 0, 21)" << std::endl;
	temp_orig = "", temp_my = "";
	time_orig = clock();

	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_1);
	orig_1.insert(orig_1.end(), (size_t)0, 21);
	temp_orig += vektor_base_test(&orig_1);

	time_orig = clock() - time_orig;

	time_my = clock();
	
	//действия c собственной копией
	temp_my += vektor_base_test(&my_1);
	my_1.insert(my_1.end(), (size_t)0, 21);
	temp_my += vektor_base_test(&my_1);
	//temp_my += " ";
	
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);

	//=============================================================
	std::cout << "size=100.001 insert(end(), 1, 21)" << std::endl;
	temp_orig = "", temp_my = "";
	time_orig = clock();

	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_1);
	orig_1.insert(orig_1.end(), (size_t)1, 21);
	temp_orig += vektor_base_test(&orig_1);

	time_orig = clock() - time_orig;

	time_my = clock();
	
	//действия c собственной копией
	temp_my += vektor_base_test(&my_1);
	my_1.insert(my_1.end(), (size_t)1, 21);
	temp_my += vektor_base_test(&my_1);
	//temp_my += " ";
	
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "size=100.002 insert(end(), 100.000, 21)" << std::endl;
	temp_orig = "", temp_my = "";
	time_orig = clock();

	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_1);
	orig_1.insert(orig_1.end(), (size_t)SIZE_10, 21);
	temp_orig += vektor_base_test(&orig_1);

	time_orig = clock() - time_orig;

	time_my = clock();
	
	//действия c собственной копией
	temp_my += vektor_base_test(&my_1);
	my_1.insert(my_1.end(), (size_t)SIZE_10, 21);
	temp_my += vektor_base_test(&my_1);
	//temp_my += " ";
	
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);

	//=============================================================
	std::cout << "size=200.002 capacity 250.000 insert(end(), 100.000, 13)" << std::endl;
	temp_orig = "", temp_my = "";
	time_orig = clock();

	orig_1.reserve(250000);
	my_1.reserve(250000);

	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_1);
	orig_1.insert(orig_1.end(), (size_t)SIZE_10, 13);
	temp_orig += vektor_base_test(&orig_1);

	time_orig = clock() - time_orig;

	time_my = clock();
	
	//действия c собственной копией
	temp_my += vektor_base_test(&my_1);
	my_1.insert(my_1.end(), (size_t)SIZE_10, 13);
	temp_my += vektor_base_test(&my_1);
	//temp_my += " ";
	
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);

	//=============================================================
	std::cout << "size=300.002 insert(begin() + 100.000, 50.000, 7)" << std::endl;
	temp_orig = "", temp_my = "";
	time_orig = clock();

	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_1);
	orig_1.insert(orig_1.begin() + SIZE_10, (size_t)SIZE_50K, 7);
	temp_orig += vektor_base_test(&orig_1);

	time_orig = clock() - time_orig;

	time_my = clock();
	
	//действия c собственной копией
	temp_my += vektor_base_test(&my_1);
	my_1.insert(my_1.begin() + SIZE_10, (size_t)SIZE_50K, 7);
	temp_my += vektor_base_test(&my_1);
	//temp_my += " ";
	
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "size=300.002 insert(begin() + 174, 100, 4)" << std::endl;
	temp_orig = "", temp_my = "";
	time_orig = clock();

	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_1);
	orig_1.insert(orig_1.begin() + 174, (size_t)100, 4);
	temp_orig += vektor_base_test(&orig_1);

	time_orig = clock() - time_orig;

	time_my = clock();
	
	//действия c собственной копией
	temp_my += vektor_base_test(&my_1);
	my_1.insert(my_1.begin() + 174, (size_t)100, 4);
	temp_my += vektor_base_test(&my_1);
	//temp_my += " ";
	
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================

	return (!rez);
}

