#include "../test_utility.cpp"

int	main ()
{
	std::string			temp_orig = "", temp_my = "";
	unsigned int		time_orig = 0, time_my = 0, rez = 0;

	std::vector<int>	orig_0(0);
	std::vector<int>	orig_1(3 + SIZE_100K);
	std::vector<int>	orig_4(4 + SIZE_100K);

	orig_1[0 + SIZE_100K] = 7; orig_1[1 + SIZE_100K] = 2; orig_1[2 + SIZE_100K] = 8;
	orig_4[0 + SIZE_100K] = 7; orig_4[1 + SIZE_100K] = 2; orig_4[2 + SIZE_100K] = 8; orig_4[3 + SIZE_100K] = 3;

	ft::vector<int>		my_0(0);
	ft::vector<int>		my_1(3 + SIZE_100K);
	ft::vector<int>		my_4(4 + SIZE_100K);

	my_1[0 + SIZE_100K] = 7; my_1[1 + SIZE_100K] = 2; my_1[2 + SIZE_100K] = 8;
	my_4[0 + SIZE_100K] = 7; my_4[1 + SIZE_100K] = 2; my_4[2 + SIZE_100K] = 8; my_4[3 + SIZE_100K] = 3;

	//=============================================================
	std::cout << "Test 1/3 (swap size1 != 0 size2 == 0)\n";
	temp_orig = "", temp_my = "";
	time_orig = clock();
	
	temp_orig += vektor_base_test(&orig_1);
	temp_orig += vektor_base_test(&orig_0);
	swap(orig_1, orig_0);
	temp_orig += vektor_base_test(&orig_1);
	temp_orig += vektor_base_test(&orig_0);
	swap(orig_1, orig_0);

	time_orig = clock() - time_orig;
	time_my = clock();
	
	temp_my += vektor_base_test(&my_1);
	temp_my += vektor_base_test(&my_0);
	swap(my_1, my_0);
	temp_my += vektor_base_test(&my_1);
	temp_my += vektor_base_test(&my_0);
	swap(my_1, my_0);

	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);

	//=============================================================
	std::cout << "Test 2/3 (swap vektor1 == vektor2)\n";
	temp_orig = "", temp_my = "";
	time_orig = clock();
	
	temp_orig += vektor_base_test(&orig_1);
	temp_orig += vektor_base_test(&orig_1);
	swap(orig_1, orig_1);
	temp_orig += vektor_base_test(&orig_1);
	temp_orig += vektor_base_test(&orig_1);
	swap(orig_1, orig_1);

	time_orig = clock() - time_orig;
	time_my = clock();
	
	temp_my += vektor_base_test(&my_1);
	temp_my += vektor_base_test(&my_1);
	swap(my_1, my_1);
	temp_my += vektor_base_test(&my_1);
	temp_my += vektor_base_test(&my_1);
	swap(my_1, my_1);

	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "Test 3/3 (swap size1(size1 != 0) != size2 (size2 != 0))\n";
	temp_orig = "", temp_my = "";
	time_orig = clock();
	
	temp_orig += vektor_base_test(&orig_1);
	temp_orig += vektor_base_test(&orig_4);
	swap(orig_1, orig_4);
	temp_orig += vektor_base_test(&orig_1);
	temp_orig += vektor_base_test(&orig_4);
	swap(orig_1, orig_4);

	time_orig = clock() - time_orig;
	time_my = clock();
	
	temp_my += vektor_base_test(&my_1);
	temp_my += vektor_base_test(&my_4);
	swap(my_1, my_4);
	temp_my += vektor_base_test(&my_1);
	temp_my += vektor_base_test(&my_4);
	swap(my_1, my_4);

	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	
	return (!rez);
}
