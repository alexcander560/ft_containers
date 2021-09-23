#include "../test_utility.cpp"

int	main ()
{
	std::string	temp_orig = "", temp_my = "";
	unsigned int time_orig = 0, time_my = 0, rez = 0;

	std::vector<int> orig_base(SIZE_1K);
	ft::vector<int> my_base(SIZE_1K);
	init_vector_all(&orig_base, &my_base);

	const std::vector<int> orig(orig_base);
	const ft::vector<int> my(my_base);

	std::vector<int>::const_iterator it1_orig;
	it1_orig = orig.begin();
	std::vector<int>::const_iterator it2_orig(it1_orig);
	it2_orig = orig.end();

	ft::vector<int>::const_iterator it1_my;
	it1_my = my.begin();
	ft::vector<int>::const_iterator it2_my(it1_my);
	it2_my = my.end();

	std::cout << "all test operator const\n";
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
	//temp_orig += "|";
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


	//temp_my += "||";
	time_my = clock() - time_my;


	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	//=============================================================
	std::cout << "check SELF! operator->() { return (_ptr); }\n";


	return (rez);
}