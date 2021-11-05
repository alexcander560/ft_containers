#include "../test_utility.cpp"

int	main ()
{

	std::string	temp_orig = "", temp_my = "";
	unsigned int time_orig = 0, time_my = 0, rez = 0;

	std::vector<int> orig(SIZE_1K);
	ft::vector<int> my(SIZE_1K);

	std::vector<int>::reverse_iterator it1_orig;
	it1_orig = orig.rbegin();
	std::vector<int>::reverse_iterator it2_orig(it1_orig);
	it2_orig = orig.rend();

	ft::vector<int>::reverse_iterator it1_my;
	it1_my = my.rbegin();
	ft::vector<int>::reverse_iterator it2_my(it1_my);
	it2_my = my.rend();
	init_vector_all(&orig, &my);

	//=============================================================

	std::cout << "Test 1/3 (all test operator)\n";
	time_orig = clock();

	while (it1_orig != it2_orig)
	{
		temp_orig += std::to_string(*it1_orig);
		if ((it1_orig) != (it2_orig - 1))
		{
			temp_orig += std::to_string(it1_orig[0]);
			temp_orig += std::to_string(*it1_orig++);
			temp_orig += std::to_string(*it1_orig--) + " ";
		}

		it1_orig++;
		it1_orig--;
		++it1_orig;
		--it1_orig;
		it1_orig + 100;
		it1_orig - 42;
		42 + it1_orig;
		-42 + it1_orig;
		it1_orig = it1_orig + 2;
		it1_orig = it1_orig - 2;
		it1_orig = 1 + it1_orig;
		it1_orig += 3;
		it1_orig -= 3;
		if ((it1_orig == it1_orig) != 1)
			break ;
		if ((it1_orig != it1_orig) != 0)
			break ;
		if ((it1_orig < it1_orig) != 0)
			break ;
		if ((it1_orig <= it1_orig) != 1)
			break ;
		if ((it1_orig > it1_orig) != 0)
			break ;
		if ((it1_orig >= it1_orig) != 1)
			break ;
	}
	
	time_orig = clock() - time_orig;

	time_my = clock();
	
	while (it1_my != it2_my)
	{
		temp_my += std::to_string(*it1_my);
		if ((it1_my) != (it2_my - 1))
		{
			temp_my += std::to_string(it1_my[0]);
			temp_my += std::to_string(*it1_my++);
			temp_my += std::to_string(*it1_my--) + " ";
		}
		it1_my++;
		it1_my--;
		++it1_my;
		--it1_my;
		it1_my + 100;
		it1_my - 42;
		42 + it1_my;
		-42 + it1_my;
		it1_my = it1_my + 2;
		it1_my = it1_my - 2;
		it1_my = 1 + it1_my;
		it1_my += 3;
		it1_my -= 3;
		if ((it1_my == it1_my) != 1)
			break ;
		if ((it1_my != it1_my) != 0)
			break ;
		if ((it1_my < it1_my) != 0)
			break ;
		if ((it1_my <= it1_my) != 1)
			break ;
		if ((it1_my > it1_my) != 0)
			break ;
		if ((it1_my >= it1_my) != 1)
			break ;
	}

	time_my = clock() - time_my;


	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "Test 2/3 (test operator->)\n";

	temp_orig = "", temp_my = "";
	time_orig = clock();

	std::vector<std::pair<int, char> > orig_pair;
	orig_pair.push_back(std::make_pair(1, 'a'));
	std::vector<std::pair<int, char> >::reverse_iterator it_orig_pair(orig_pair.rbegin());
	for (size_t i = 0; i < SIZE_100K; i++)
	{
		temp_orig += std::to_string(it_orig_pair->first);
		temp_orig += std::to_string(it_orig_pair->second);
	}

	time_orig = clock() - time_orig;

	time_my = clock();

	ft::vector<ft::pair<int, char> > my_pair;
	my_pair.push_back(ft::make_pair(1, 'a'));
	ft::vector<ft::pair<int, char> >::reverse_iterator it_my_pair(my_pair.rbegin());
	for (size_t i = 0; i < SIZE_100K; i++)
	{
		temp_my += std::to_string(it_my_pair->first);
		temp_my += std::to_string(it_my_pair->second);
	}
	//temp_my += " ";

	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	long long int	long_per = 9223372036854775807;
	char 			ch = 'a';
	int 			per = 42;
	temp_orig = "", temp_my = "";
	long_per--;
	it1_orig = orig.rbegin() + 1;
	it1_my = my.rbegin() + 1;
	
	std::cout << "Test 3/3 (test other)\n";
	time_orig = clock();
	//Оригинал
	it1_orig = it1_orig + ch;
	it1_orig = it1_orig - ch;
	it1_orig = ch + it1_orig;
	it1_orig = -ch + it1_orig;
	//--
	it1_orig = it1_orig + per;
	it1_orig = it1_orig - per;
	it1_orig = per + it1_orig;
	it1_orig = -per + it1_orig;
	//--
	it1_orig = it1_orig + long_per;
	it1_orig = it1_orig - long_per;
	it1_orig = long_per + it1_orig;
	it1_orig = 1L + it1_orig;
	it1_orig = 1LL + it1_orig;
	it1_orig = -long_per + it1_orig;
	//--

	temp_orig += std::to_string(*it1_orig);

	time_orig = clock() - time_orig;

	time_my = clock();
	//Мой код
	it1_my = it1_my + ch;
	it1_my = it1_my - ch;
	it1_my = ch + it1_my;
	it1_my = -ch + it1_my;
	//--
	it1_my = it1_my + per;
	it1_my = it1_my - per;
	it1_my = per + it1_my;
	it1_my = -per + it1_my;
	//--
	it1_my = it1_my + long_per;
	it1_my = it1_my - long_per;
	it1_my = long_per + it1_my;
	it1_my = 1L + it1_my;
	it1_my = 1LL + it1_my;
	it1_my = -long_per + it1_my;
	//--

	temp_my += std::to_string(*it1_my);
	//temp_my += " ";

	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================

	return (!rez);
}
