#include "../test_utility.cpp"

int	main ()
{
	std::string			temp_orig = "", temp_my = "";
	unsigned int		time_orig = 0, time_my = 0, rez = 0;
	std::vector<int>	orig_1(0);
	ft::vector<int>		my_1(0);
	std::vector<int>	orig_0(0);
	ft::vector<int>		my_0(0);
	std::vector<int>	orig_2(SIZE_100);
	ft::vector<int>		my_2(SIZE_100);
	std::vector<int>	orig_3(SIZE_100);
	ft::vector<int>		my_3(SIZE_100);

	init_vector_all(&orig_1, &my_1);
	init_vector_all(&orig_0, &my_0);
	init_vector_all(&orig_2, &my_2);
	//std::cout << "2: " << orig_2[0] << std::endl;
	init_vector_all(&orig_3, &my_3);
	//std::cout << "3: " << orig_3[0] << std::endl; 
	//=============================================================
	//=========================self size=0 ========================
	//=============================================================
	std::cout << "Test 1/12 (self size=0 insert(begin(), begin() , begin()))" << std::endl;
	temp_orig = "", temp_my = "";
	time_orig = clock();

	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_1);
	orig_1.insert(orig_1.begin(), orig_1.begin(), orig_1.begin());
	temp_orig += vektor_base_test(&orig_1);

	time_orig = clock() - time_orig;

	time_my = clock();
	
	//действия c собственной копией
	temp_my += vektor_base_test(&my_1);
	my_1.insert(my_1.begin(), my_1.begin(), my_1.begin());
	temp_my += vektor_base_test(&my_1);
	//temp_my += " ";
	
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);

	//=============================================================
	std::cout << "Test 2/12 (self size=0 insert(begin(), begin() , end()))" << std::endl;
	temp_orig = "", temp_my = "";
	time_orig = clock();

	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_1);
	orig_1.insert(orig_1.begin(), orig_1.begin(), orig_1.end());
	temp_orig += vektor_base_test(&orig_1);

	time_orig = clock() - time_orig;

	time_my = clock();
	
	//действия c собственной копией
	temp_my += vektor_base_test(&my_1);
	my_1.insert(my_1.begin(), my_1.begin(), my_1.end());
	temp_my += vektor_base_test(&my_1);
	//temp_my += " ";
	
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	//=========================other size=0========================
	//=============================================================
	std::cout << "Test 3/12 (other size=0 insert(begin(), begin(), begin()))" << std::endl;
	temp_orig = "", temp_my = "";
	time_orig = clock();

	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_1);
	orig_1.insert(orig_1.begin(), orig_0.begin(), orig_0.begin());
	temp_orig += vektor_base_test(&orig_1);

	time_orig = clock() - time_orig;

	time_my = clock();
	
	//действия c собственной копией
	temp_my += vektor_base_test(&my_1);
	my_1.insert(my_1.begin(), my_0.begin(), my_0.begin());
	temp_my += vektor_base_test(&my_1);
	//temp_my += " ";
	
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);

	//=============================================================
	std::cout << "Test 4/12 (other size=0 insert(begin(), begin(), end()))" << std::endl;
	temp_orig = "", temp_my = "";
	time_orig = clock();

	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_1);
	orig_1.insert(orig_1.begin(), orig_0.begin(), orig_0.end());
	temp_orig += vektor_base_test(&orig_1);

	time_orig = clock() - time_orig;

	time_my = clock();
	
	//действия c собственной копией
	temp_my += vektor_base_test(&my_1);
	my_1.insert(my_1.begin(), my_1.begin(), my_1.end());
	temp_my += vektor_base_test(&my_1);
	//temp_my += " ";
	
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);

	//=============================================================
	//=========================self size=100=======================
	//=============================================================
	std::cout << "Test 5/12 (self size=100 insert(begin(), begin(), begin()))" << std::endl;
	temp_orig = "", temp_my = "";
	time_orig = clock();

	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_2);
	orig_2.insert(orig_2.begin(), orig_2.begin(), orig_2.begin());
	temp_orig += vektor_base_test(&orig_2);

	time_orig = clock() - time_orig;

	time_my = clock();
	
	//действия c собственной копией
	temp_my += vektor_base_test(&my_2);
	my_2.insert(my_2.begin(), my_2.begin(), my_2.begin());
	temp_my += vektor_base_test(&my_2);
	//temp_my += "!";
	
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);

	//=============================================================
	std::cout << "Test 6/12 (self size=100 insert(begin(), begin(), end()))" << std::endl;
	temp_orig = "", temp_my = "";
	time_orig = clock();

	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_2);
	orig_2.insert(orig_2.begin(), orig_2.begin(), orig_2.end());
	temp_orig += vektor_base_test(&orig_2);

	time_orig = clock() - time_orig;

	time_my = clock();
	
	//действия c собственной копией
	temp_my += vektor_base_test(&my_2);
	my_2.insert(my_2.begin(), my_2.begin(), my_2.end());
	temp_my += vektor_base_test(&my_2);
	//temp_my += " ";
	
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);

	//=============================================================
	//=========================other size=200======================
	//=============================================================
	std::cout << "Test 7/12 (self size=200 insert(begin() + 70, begin(), begin()))" << std::endl;
	temp_orig = "", temp_my = "";
	time_orig = clock();

	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_2);
	orig_2.insert(orig_2.begin() + 70, orig_3.begin(), orig_3.begin());
	temp_orig += vektor_base_test(&orig_2);

	time_orig = clock() - time_orig;

	time_my = clock();
	
	//действия c собственной копией
	temp_my += vektor_base_test(&my_2);
	my_2.insert(my_2.begin() + 70, my_3.begin(), my_3.begin());
	temp_my += vektor_base_test(&my_2);
	//temp_my += " ";
	
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);

	//=============================================================
	std::cout << "Test 8/12 (self size=200 insert(begin(), begin(), end()))" << std::endl;
	temp_orig = "", temp_my = "";
	time_orig = clock();

	//действия c оригиналом
	temp_orig += vektor_base_test(&orig_2);
	orig_2.insert(orig_2.begin(), orig_3.begin(), orig_3.end());
	temp_orig += vektor_base_test(&orig_2);

	time_orig = clock() - time_orig;

	time_my = clock();
	
	//действия c собственной копией
	temp_my += vektor_base_test(&my_2);
	my_2.insert(my_2.begin(), my_3.begin(), my_3.end());
	temp_my += vektor_base_test(&my_2);
	//temp_my += " ";
	
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	//=========================self size=300=======================
	//=============================================================
	std::cout << "Test 9/12 (self size=300 insert(end() - 170, begin() + 10, end() - 170))" << std::endl;
	temp_orig = "", temp_my = "";

	//действия c оригиналом
	time_orig = clock();

	temp_orig += vektor_base_test(&orig_2);
	orig_2.insert(orig_2.end() - 170, orig_2.begin() + 10, orig_2.end() - 170);
	temp_orig += vektor_base_test(&orig_2);

	time_orig = clock() - time_orig;

	//действия c собственной копией
	time_my = clock();

	temp_my += vektor_base_test(&my_2);
	my_2.insert(my_2.end() - 170, my_2.begin() + 10, my_2.end() - 170);
	temp_my += vektor_base_test(&my_2);
	//temp_my += " ";

	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);

	//=============================================================
	//=========================other size=420======================
	//=============================================================
	std::cout << "Test 10/12 (self size=420 insert(begin(), begin() + 1, end() - 1))" << std::endl;
	temp_orig = "", temp_my = "";

	//действия c оригиналом
	time_orig = clock();

	temp_orig += vektor_base_test(&orig_2);
	orig_2.insert(orig_2.begin(), orig_3.begin() + 1, orig_3.end() - 1);
	temp_orig += vektor_base_test(&orig_2);

	time_orig = clock() - time_orig;

	//действия c собственной копией
	time_my = clock();

	temp_my += vektor_base_test(&my_2);
	my_2.insert(my_2.begin(), my_3.begin() + 1, my_3.end() - 1);
	temp_my += vektor_base_test(&my_2);
	//temp_my += " ";

	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	//=========================self size=10 capacity=15 ==========
	//=============================================================
	std::cout << "Test 11/12 (self size=10 insert(begin() + 1, begin() + 3, end() - 1))" << std::endl;
	temp_orig = "", temp_my = "";


	std::vector<int> orig_4(10);
	ft::vector<int> my_4(10);

	init_vector_all(&orig_4, &my_4);
	for (size_t i = 0; i < 10; i++)
	{
		orig_4[i] = i;
		my_4[i] = i;
	}

	orig_4.reserve(15);
	my_4.reserve(15);

	//действия c оригиналом
	time_orig = clock();

	temp_orig += vektor_base_test(&orig_4);
	orig_4.insert(orig_4.begin() + 3, orig_4.begin() + 1, orig_4.end() - 5);
	temp_orig += vektor_base_test(&orig_4);

	time_orig = clock() - time_orig;

	//действия c собственной копией
	time_my = clock();

	temp_my += vektor_base_test(&my_4);
	my_4.insert(my_4.begin() + 3, my_4.begin() + 1, my_4.end() - 5);
	temp_my += vektor_base_test(&my_4);
	//temp_my += " ";

	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);

	//=============================================================
	//=========================self size=14 capacity=50============
	//=============================================================
	std::cout << "Test 12/12 (self size=14 insert(begin() + 8, begin() + 1, end() - 3))" << std::endl;
	temp_orig = "", temp_my = "";

	orig_4.reserve(50);
	my_4.reserve(50);

	//действия c оригиналом
	time_orig = clock();

	temp_orig += vektor_base_test(&orig_4);
	orig_4.insert(orig_4.begin() + 8, orig_4.begin() + 1, orig_4.end() - 3);
	temp_orig += vektor_base_test(&orig_4);

	time_orig = clock() - time_orig;

	//действия c собственной копией
	time_my = clock();

	temp_my += vektor_base_test(&my_4);
	my_4.insert(my_4.begin() + 8, my_4.begin() + 1, my_4.end() - 3);
	temp_my += vektor_base_test(&my_4);
	//temp_my += " ";

	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	//std::string str_leaks; std::cin >> str_leaks;
	return (!rez);
}
