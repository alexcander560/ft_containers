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

	std::cout << "all test operator\n";
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
	std::cout << "check SELF! operator->() const { return (&(operator*())); }\n";

	return (rez);
}
