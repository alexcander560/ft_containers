#include "../test_utility.cpp"

int	main ()
{
	std::string			temp_orig = "", temp_my = "";
	unsigned int		time_orig = 0, time_my = 0, rez = 0;

	std::vector<int>	orig_0(0);
	std::vector<int>	orig_1(3 + SIZE_100K);
	std::vector<int>	orig_2(3 + SIZE_100K);
	std::vector<int>	orig_3(3 + SIZE_100K);
	std::vector<int>	orig_4(4 + SIZE_100K);
	std::vector<int>	orig_5(4 + SIZE_100K);
	std::vector<int>	orig_6(4 + SIZE_100K);

	orig_1[0 + SIZE_100K] = 7; orig_1[1 + SIZE_100K] = 2; orig_1[2 + SIZE_100K] = 8;
	orig_2[0 + SIZE_100K] = 7; orig_2[1 + SIZE_100K] = 2; orig_2[2 + SIZE_100K] = 7;
	orig_3[0 + SIZE_100K] = 7; orig_3[1 + SIZE_100K] = 2; orig_3[2 + SIZE_100K] = 9;

	orig_4[0 + SIZE_100K] = 7; orig_4[1 + SIZE_100K] = 2; orig_4[2 + SIZE_100K] = 8; orig_4[3 + SIZE_100K] = 3;
	orig_5[0 + SIZE_100K] = 7; orig_5[1 + SIZE_100K] = 2; orig_5[2 + SIZE_100K] = 7; orig_5[3 + SIZE_100K] = 3;
	orig_6[0 + SIZE_100K] = 7; orig_6[1 + SIZE_100K] = 2; orig_6[2 + SIZE_100K] = 9; orig_6[3 + SIZE_100K] = 3;

	ft::vector<int>		my_0(0);
	ft::vector<int>		my_1(3 + SIZE_100K);
	ft::vector<int>		my_2(3 + SIZE_100K);
	ft::vector<int>		my_3(3 + SIZE_100K);
	ft::vector<int>		my_4(4 + SIZE_100K);
	ft::vector<int>		my_5(4 + SIZE_100K);
	ft::vector<int>		my_6(4 + SIZE_100K);

	my_1[0 + SIZE_100K] = 7; my_1[1 + SIZE_100K] = 2; my_1[2 + SIZE_100K] = 8;
	my_2[0 + SIZE_100K] = 7; my_2[1 + SIZE_100K] = 2; my_2[2 + SIZE_100K] = 7;
	my_3[0 + SIZE_100K] = 7; my_3[1 + SIZE_100K] = 2; my_3[2 + SIZE_100K] = 9;

	my_4[0 + SIZE_100K] = 7; my_4[1 + SIZE_100K] = 2; my_4[2 + SIZE_100K] = 8; my_4[3 + SIZE_100K] = 3;
	my_5[0 + SIZE_100K] = 7; my_5[1 + SIZE_100K] = 2; my_5[2 + SIZE_100K] = 7; my_5[3 + SIZE_100K] = 3;
	my_6[0 + SIZE_100K] = 7; my_6[1 + SIZE_100K] = 2; my_6[2 + SIZE_100K] = 9; my_6[3 + SIZE_100K] = 3;

	//=============================================================

	std::cout << "Test 1/6 (==)\n";
	temp_orig = "", temp_my = "";
	time_orig = clock();
	temp_orig += std::to_string(orig_1 == orig_0) + " ";
	temp_orig += std::to_string(orig_1 == orig_1) + " ";
	temp_orig += std::to_string(orig_1 == orig_2) + " ";
	temp_orig += std::to_string(orig_1 == orig_3) + " ";
	temp_orig += std::to_string(orig_1 == orig_4) + " ";
	temp_orig += std::to_string(orig_1 == orig_5) + " ";
	temp_orig += std::to_string(orig_1 == orig_6) + " ";
	//temp_orig += " or";
	time_orig = clock() - time_orig;
	time_my = clock();
	// code my
	temp_my += std::to_string(my_1 == my_0) + " ";
	temp_my += std::to_string(my_1 == my_1) + " ";
	temp_my += std::to_string(my_1 == my_2) + " ";
	temp_my += std::to_string(my_1 == my_3) + " ";
	temp_my += std::to_string(my_1 == my_4) + " ";
	temp_my += std::to_string(my_1 == my_5) + " ";
	temp_my += std::to_string(my_1 == my_6) + " ";
	//temp_my += " my";
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "Test 2/6 (!=)\n";
	temp_orig = "", temp_my = "";
	time_orig = clock();
	// code orig
	temp_orig += std::to_string(orig_1 != orig_0) + " ";
	temp_orig += std::to_string(orig_1 != orig_1) + " ";
	temp_orig += std::to_string(orig_1 != orig_2) + " ";
	temp_orig += std::to_string(orig_1 != orig_3) + " ";
	temp_orig += std::to_string(orig_1 != orig_4) + " ";
	temp_orig += std::to_string(orig_1 != orig_5) + " ";
	temp_orig += std::to_string(orig_1 != orig_6) + " ";
	//temp_orig += " or";
	time_orig = clock() - time_orig;
	time_my = clock();
	// code my
	temp_my += std::to_string(my_1 != my_0) + " ";
	temp_my += std::to_string(my_1 != my_1) + " ";
	temp_my += std::to_string(my_1 != my_2) + " ";
	temp_my += std::to_string(my_1 != my_3) + " ";
	temp_my += std::to_string(my_1 != my_4) + " ";
	temp_my += std::to_string(my_1 != my_5) + " ";
	temp_my += std::to_string(my_1 != my_6) + " ";
	//temp_my += " my";
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "Test 3/6 (<)\n";
	temp_orig = "", temp_my = "";
	time_orig = clock();
	// code orig
	temp_orig += std::to_string(orig_1 < orig_0) + " ";
	temp_orig += std::to_string(orig_1 < orig_1) + " ";
	temp_orig += std::to_string(orig_1 < orig_2) + " ";
	temp_orig += std::to_string(orig_1 < orig_3) + " ";
	temp_orig += std::to_string(orig_1 < orig_4) + " ";
	temp_orig += std::to_string(orig_1 < orig_5) + " ";
	temp_orig += std::to_string(orig_1 < orig_6) + " ";
	time_orig = clock() - time_orig;
	//temp_orig += " or";
	time_my = clock();
	// code my
	temp_my += std::to_string(my_1 < my_0) + " ";
	temp_my += std::to_string(my_1 < my_1) + " ";
	temp_my += std::to_string(my_1 < my_2) + " ";
	temp_my += std::to_string(my_1 < my_3) + " ";
	temp_my += std::to_string(my_1 < my_4) + " ";
	temp_my += std::to_string(my_1 < my_5) + " ";
	temp_my += std::to_string(my_1 < my_6) + " ";
	//temp_my += " my";
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "Test 4/6 (<=)\n";
	temp_orig = "", temp_my = "";
	time_orig = clock();
	// code orig
	temp_orig += std::to_string(orig_1 <= orig_0) + " ";
	temp_orig += std::to_string(orig_1 <= orig_1) + " ";
	temp_orig += std::to_string(orig_1 <= orig_2) + " ";
	temp_orig += std::to_string(orig_1 <= orig_3) + " ";
	temp_orig += std::to_string(orig_1 <= orig_4) + " ";
	temp_orig += std::to_string(orig_1 <= orig_5) + " ";
	temp_orig += std::to_string(orig_1 <= orig_6) + " ";
	//temp_orig += " or";
	time_orig = clock() - time_orig;
	time_my = clock();
	// code my
	temp_my += std::to_string(my_1 <= my_0) + " ";
	temp_my += std::to_string(my_1 <= my_1) + " ";
	temp_my += std::to_string(my_1 <= my_2) + " ";
	temp_my += std::to_string(my_1 <= my_3) + " ";
	temp_my += std::to_string(my_1 <= my_4) + " ";
	temp_my += std::to_string(my_1 <= my_5) + " ";
	temp_my += std::to_string(my_1 <= my_6) + " ";
	//temp_my += " my";
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "Test 5/6 (>)\n";
	temp_orig = "", temp_my = "";
	time_orig = clock();
	// code orig
	temp_orig += std::to_string(orig_1 > orig_0) + " ";
	temp_orig += std::to_string(orig_1 > orig_1) + " ";
	temp_orig += std::to_string(orig_1 > orig_2) + " ";
	temp_orig += std::to_string(orig_1 > orig_3) + " ";
	temp_orig += std::to_string(orig_1 > orig_4) + " ";
	temp_orig += std::to_string(orig_1 > orig_5) + " ";
	temp_orig += std::to_string(orig_1 > orig_6) + " ";
	//temp_orig += " or";
	time_orig = clock() - time_orig;
	time_my = clock();
	// code my
	temp_my += std::to_string(my_1 > my_0) + " ";
	temp_my += std::to_string(my_1 > my_1) + " ";
	temp_my += std::to_string(my_1 > my_2) + " ";
	temp_my += std::to_string(my_1 > my_3) + " ";
	temp_my += std::to_string(my_1 > my_4) + " ";
	temp_my += std::to_string(my_1 > my_5) + " ";
	temp_my += std::to_string(my_1 > my_6) + " ";
	//temp_my += " my";
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "Test 6/6 (>=)\n";
	temp_orig = "", temp_my = "";
	time_orig = clock();
	// code orig
	temp_orig += std::to_string(orig_1 >= orig_0) + " ";
	temp_orig += std::to_string(orig_1 >= orig_1) + " ";
	temp_orig += std::to_string(orig_1 >= orig_2) + " ";
	temp_orig += std::to_string(orig_1 >= orig_3) + " ";
	temp_orig += std::to_string(orig_1 >= orig_4) + " ";
	temp_orig += std::to_string(orig_1 >= orig_5) + " ";
	temp_orig += std::to_string(orig_1 >= orig_6) + " ";
	//temp_orig += " or";
	time_orig = clock() - time_orig;
	time_my = clock();
	// code my
	temp_my += std::to_string(my_1 >= my_0) + " ";
	temp_my += std::to_string(my_1 >= my_1) + " ";
	temp_my += std::to_string(my_1 >= my_2) + " ";
	temp_my += std::to_string(my_1 >= my_3) + " ";
	temp_my += std::to_string(my_1 >= my_4) + " ";
	temp_my += std::to_string(my_1 >= my_5) + " ";
	temp_my += std::to_string(my_1 >= my_6) + " ";
	//temp_my += " my";
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	
	//=============================================================
	return (!rez);
}
