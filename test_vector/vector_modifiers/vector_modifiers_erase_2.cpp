#include "../test_utility.cpp"

int	main ()
{
	std::string	temp_orig = "", temp_my = "";
	unsigned int time_orig = 0, time_my = 0, rez = 0;

	std::vector<int> orig_1(1);
	ft::vector<int> my_1(1);
	init_vector_all(&orig_1, &my_1);

	std::vector<int> orig_2(SIZE_100K);
	ft::vector<int> my_2(SIZE_100K);
	init_vector_all(&orig_2, &my_2);

	std::vector<int> orig_3(SIZE_100K);
	ft::vector<int> my_3(SIZE_100K);
	init_vector_all(&orig_3, &my_3);

	//=============================================================
	std::cout << "erase(begin(), begin()) size=1" << std::endl;
	temp_orig = "", temp_my = "";
	time_orig = clock();
	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_1);
	temp_orig += " iter=" + std::to_string (*orig_1.erase(orig_1.begin(), orig_1.begin()));
	temp_orig += vektor_base_test(&orig_1);
	time_orig = clock() - time_orig;

	time_my = clock();
	//действия c собственной копией
	temp_my += vektor_base_test(&my_1);
	temp_my += " iter=" + std::to_string (*my_1.erase(my_1.begin(), my_1.begin()));
	temp_my += vektor_base_test(&my_1);
	//temp_my += " ";
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "erase(begin(), end()) size=1" << std::endl;
	temp_orig = "", temp_my = "";
	time_orig = clock();
	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_1);
	temp_orig += " iter=" + std::to_string (*orig_1.erase(orig_1.begin(), orig_1.end()));
	temp_orig += vektor_base_test(&orig_1);
	time_orig = clock() - time_orig;

	time_my = clock();
	//действия c собственной копией
	temp_my += vektor_base_test(&my_1);
	temp_my += " iter=" + std::to_string (*my_1.erase(my_1.begin(), my_1.end()));
	temp_my += vektor_base_test(&my_1);
	//temp_my += " ";
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "erase(begin(), begin()) size=100.000" << std::endl;
	temp_orig = "", temp_my = "";
	time_orig = clock();
	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_2);
	temp_orig += " iter=" + std::to_string (*orig_2.erase(orig_2.begin(), orig_2.begin()));
	temp_orig += vektor_base_test(&orig_2);
	time_orig = clock() - time_orig;

	time_my = clock();
	//действия c собственной копией
	temp_my += vektor_base_test(&my_2);
	temp_my += " iter=" + std::to_string (*my_2.erase(my_2.begin(), my_2.begin()));
	temp_my += vektor_base_test(&my_2);
	//temp_my += " ";
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "erase(begin(), end()) size=100.000" << std::endl;
	temp_orig = "", temp_my = "";
	time_orig = clock();
	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_2);
	temp_orig += " iter=" + std::to_string (*orig_2.erase(orig_2.begin(), orig_2.end()));
	temp_orig += vektor_base_test(&orig_2);
	time_orig = clock() - time_orig;

	time_my = clock();
	//действия c собственной копией
	temp_my += vektor_base_test(&my_2);
	temp_my += " iter=" + std::to_string (*my_2.erase(my_2.begin(), my_2.end()));
	temp_my += vektor_base_test(&my_2);
	//temp_my += " ";
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "(start size=100.000)\nerase(begin(), begin() + 1)" << std::endl;
	std::cout << "erase(begin() + 10.000, begin() + 50.000)" << std::endl;
	std::cout << "erase(end() - 1, end())" << std::endl;
	std::cout << "erase(end() - 30.000, end() - 10.000)" << std::endl;
	temp_orig = "", temp_my = "";
	time_orig = clock();
	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_3);

	temp_orig += " iter=" + std::to_string (*orig_3.erase(orig_3.begin(), orig_3.begin() + 1));
	temp_orig += " iter=" + std::to_string (*orig_3.erase(orig_3.begin() + 10000, orig_3.begin() + 50000));
	temp_orig += " iter=" + std::to_string (*orig_3.erase(orig_3.end() - 1, orig_3.end()));
	temp_orig += " iter=" + std::to_string (*orig_3.erase(orig_3.end() - 30000, orig_3.end() - 10000));

	temp_orig += vektor_base_test(&orig_3);
	time_orig = clock() - time_orig;

	time_my = clock();
	//действия c собственной копией
	temp_my += vektor_base_test(&my_3);

	temp_my += " iter=" + std::to_string (*my_3.erase(my_3.begin(), my_3.begin() + 1));
	temp_my += " iter=" + std::to_string (*my_3.erase(my_3.begin() + 10000, my_3.begin() + 50000));
	temp_my += " iter=" + std::to_string (*my_3.erase(my_3.end() - 1, my_3.end()));
	temp_my += " iter=" + std::to_string (*my_3.erase(my_3.end() - 30000, my_3.end() - 10000));

	temp_my += vektor_base_test(&my_3);
	//temp_my += " ";
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "(start size=39998)\nerase(begin(), end())" << std::endl;
	temp_orig = "", temp_my = "";
	time_orig = clock();
	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_3);
	temp_orig += " iter=" + std::to_string (*orig_3.erase(orig_3.begin(), orig_3.end()));
	temp_orig += vektor_base_test(&orig_3);
	time_orig = clock() - time_orig;

	time_my = clock();
	//действия c собственной копией
	temp_my += vektor_base_test(&my_3);
	temp_my += " iter=" + std::to_string (*my_3.erase(my_3.begin(), my_3.end()));
	temp_my += vektor_base_test(&my_3);
	//temp_my += " ";
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================

	return (!rez);
}
