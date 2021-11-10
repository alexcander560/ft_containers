#include "../test_utility_map.cpp"

#define	TEST 0
#define	LEAK 0

int	test(string test)
{
	string			temp_orig = "", temp_my = "";
	unsigned int	time_orig = 0, time_my = 0, rez = 0;

	cout << test << endl;
	//===========================ORIG==============================
	time_orig = clock();
	
	std::map<char,int> mymap;
	std::map<char,int>::key_compare mycomp = mymap.key_comp();

	mymap['a']=100;
	mymap['b']=200;
	mymap['c']=300;
	char highest = mymap.rbegin()->first;

	std::map<char,int>::iterator it = mymap.begin();
	do {
		temp_orig += it->first + to_string(it->second);
	} while ( mycomp((*it++).first, highest) );


	time_orig = clock() - time_orig;
	//============================MY===============================
	time_my = clock();
	
	ft::map<char,int> ft_mymap;
	ft::map<char,int>::key_compare ft_mycomp = ft_mymap.key_comp();

	ft_mymap['a']=100;
	ft_mymap['b']=200;
	ft_mymap['c']=300;
	char ft_highest = ft_mymap.rbegin()->first;

	ft::map<char,int>::iterator ft_it = ft_mymap.begin();
	do {
		temp_my += ft_it->first + to_string(ft_it->second);
	} while ( ft_mycomp((*ft_it++).first, ft_highest) );

	if (TEST)
		temp_my += " ";
	time_my = clock() - time_my;
	//=============================================================
	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	return (rez);
}

int	main()
{
	string	str_leaks = "";
	int		rez = 0;

	//=============================================================
	rez += test("Test 1/1");
	//=============================================================
	if (LEAK)
		cin >> str_leaks;
	return (!rez);
}
