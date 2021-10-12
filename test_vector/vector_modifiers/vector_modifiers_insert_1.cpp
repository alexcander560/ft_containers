#include "../test_utility.cpp"

int	main ()
{
	std::string	temp_orig = "", temp_my = "";
	unsigned int time_orig = 0, time_my = 0, rez = 0;

	std::vector<int> orig_1(0);
	ft::vector<int> my_1(0);
	std::vector<int> orig_2(SIZE_100K);
	ft::vector<int> my_2(SIZE_100K);
	std::vector<int> orig_3(SIZE_10);
	ft::vector<int> my_3(SIZE_10);
	std::vector<int> orig_4(0);
	ft::vector<int> my_4(0);

	init_vector_all(&orig_1, &my_1);
	init_vector_all(&orig_2, &my_2);
	init_vector_all(&orig_3, &my_3);

	//=============================================================
	std::cout << "size=0 insert(begin(), 42)" << std::endl;
	temp_orig = "", temp_my = "";
	time_orig = clock();

	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_1);
	temp_orig += " iter=" + std::to_string (*orig_1.insert(orig_1.begin(), 42));
	temp_orig += vektor_base_test(&orig_1);

	time_orig = clock() - time_orig;

	time_my = clock();
	
	//действия c собственной копией
	temp_my += vektor_base_test(&my_1);
	temp_my += " iter=" + std::to_string (*my_1.insert(my_1.begin(), 42));
	temp_my += vektor_base_test(&my_1);
	//temp_my += " ";
	
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "size=1 insert(end(), 42)" << std::endl;
	temp_orig = "", temp_my = "";
	time_orig = clock();

	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_1);
	temp_orig += " iter=" + std::to_string (*orig_1.insert(orig_1.end(), 42));
	temp_orig += vektor_base_test(&orig_1);

	time_orig = clock() - time_orig;

	time_my = clock();
	
	//действия c собственной копией
	temp_my += vektor_base_test(&my_1);
	temp_my += " iter=" + std::to_string (*my_1.insert(my_1.end(), 42));
	temp_my += vektor_base_test(&my_1);
	//temp_my += " ";
	
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "size=2 capacity=3 insert(end(), 668)" << std::endl;
	temp_orig = "", temp_my = "";
	orig_1.reserve(3);
	my_1.reserve(3);

	time_orig = clock();

	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_1);
	temp_orig += " iter=" + std::to_string (*orig_1.insert(orig_1.end(), 668));
	//orig_1.insert(orig_1.end(), 668);
	temp_orig += vektor_base_test(&orig_1);

	time_orig = clock() - time_orig;

	time_my = clock();
	
	//действия c собственной копией
	temp_my += vektor_base_test(&my_1);
	temp_my += " iter=" + std::to_string (*my_1.insert(my_1.end(), 668));
	//my_1.insert(my_1.end(), 668);
	temp_my += vektor_base_test(&my_1);
	//temp_my += " ";
	
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "start size=100.000\ninsert(begin() + 1, 42)" << std::endl;
	std::cout << "insert(begin() + 50.000, 42)" << std::endl;
	std::cout << "insert(end() - 50.000, 42)" << std::endl;
	std::cout << "insert(end() - 1, 42)" << std::endl;
	temp_orig = "", temp_my = "";
	time_orig = clock();

	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_2);
	temp_orig += " iter=" + std::to_string (*orig_2.insert(orig_2.begin() + 1, 42));
	temp_orig += " iter=" + std::to_string (*orig_2.insert(orig_2.begin() + SIZE_50K, 42));
	temp_orig += " iter=" + std::to_string (*orig_2.insert(orig_2.end() - SIZE_50K, 42));
	temp_orig += " iter=" + std::to_string (*orig_2.insert(orig_2.end() - 1, 42));
	temp_orig += vektor_base_test(&orig_2);

	time_orig = clock() - time_orig;

	time_my = clock();
	
	//действия c собственной копией
	temp_my += vektor_base_test(&my_2);
	temp_my += " iter=" + std::to_string (*my_2.insert(my_2.begin() + 1, 42));
	temp_my += " iter=" + std::to_string (*my_2.insert(my_2.begin() + SIZE_50K, 42));
	temp_my += " iter=" + std::to_string (*my_2.insert(my_2.end() - SIZE_50K, 42));
	temp_my += " iter=" + std::to_string (*my_2.insert(my_2.end() - 1, 42));
	temp_my += vektor_base_test(&my_2);
	//temp_my += " ";
	
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "start size=10 capacity=11\ninsert(begin() + 1, 1000000) (2 use)" << std::endl;
	orig_3.reserve(11);
	my_3.reserve(11);
	temp_orig = "", temp_my = "";
	time_orig = clock();

	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_3);
	temp_orig += " iter=" + std::to_string (*orig_3.insert(orig_3.begin() + 1, 1000000));
	temp_orig += " iter=" + std::to_string (*orig_3.insert(orig_3.begin() + 1, 1000000));
	temp_orig += vektor_base_test(&orig_3);

	time_orig = clock() - time_orig;

	time_my = clock();
	
	//действия c собственной копией
	temp_my += vektor_base_test(&my_3);
	temp_my += " iter=" + std::to_string (*my_3.insert(my_3.begin() + 1, 1000000));
	temp_my += " iter=" + std::to_string (*my_3.insert(my_3.begin() + 1, 1000000));
	temp_my += vektor_base_test(&my_3);
	//temp_my += " ";
	
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "start size=11 capacity=11\ninsert(end(), 777) (2 use)" << std::endl;
	orig_3.reserve(12);
	my_3.reserve(12);
	temp_orig = "", temp_my = "";
	time_orig = clock();

	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_3);
	temp_orig += " iter=" + std::to_string (*orig_3.insert(orig_3.end(), 777));
	temp_orig += " iter=" + std::to_string (*orig_3.insert(orig_3.end(), 777));
	temp_orig += vektor_base_test(&orig_3);

	time_orig = clock() - time_orig;

	time_my = clock();
	
	//действия c собственной копией
	temp_my += vektor_base_test(&my_3);
	temp_my += " iter=" + std::to_string (*my_3.insert(my_3.end(), 777));
	temp_my += " iter=" + std::to_string (*my_3.insert(my_3.end(), 777));
	temp_my += vektor_base_test(&my_3);
	//temp_my += " ";
	
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "start size=0 capacity=1\ninsert(end(), 666)" << std::endl;
	orig_4.reserve(1);
	my_4.reserve(1);
	temp_orig = "", temp_my = "";
	time_orig = clock();

	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_4);
	temp_orig += " iter=" + std::to_string (*orig_4.insert(orig_4.end(), 777));
	temp_orig += " iter=" + std::to_string (*orig_4.insert(orig_4.end(), 777));
	temp_orig += vektor_base_test(&orig_4);

	time_orig = clock() - time_orig;

	time_my = clock();
	
	//действия c собственной копией
	temp_my += vektor_base_test(&my_4);
	temp_my += " iter=" + std::to_string (*my_4.insert(my_4.end(), 777));
	temp_my += " iter=" + std::to_string (*my_4.insert(my_4.end(), 777));
	temp_my += vektor_base_test(&my_4);
	//temp_my += " ";
	
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================

	return (!rez);
}
