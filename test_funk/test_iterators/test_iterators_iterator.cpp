#include "../test_utility.cpp"

// class Test_class
// {
// 	public:
// 		std::vector<int>::iterator iter;
// };

// void	test_iter(Test_class it, Test_class *it_r)
// {
// 	//std::cout << "Hello\n";
// 	std::vector<int>::iterator iter;

// 	iter = it.iter;
// 	std::cout << "1: " << *iter << std::endl;
// 	std::cout << "2: " << *(it.iter) << std::endl;
// 	std::cout << "3: " << *(it_r->iter) << std::endl;
// }

int	main ()
{
	std::string	temp_orig = "", temp_my = "";
	unsigned int time_orig = 0, time_my = 0, rez = 0;

	std::vector<int> orig(SIZE_1K);
	ft::vector<int> my(SIZE_1K);

	std::vector<int>::iterator it1_orig;
	it1_orig = orig.begin();
	std::vector<int>::iterator it2_orig(it1_orig);
	it2_orig = orig.end();

	ft::vector<int>::iterator it1_my;
	it1_my = my.begin();
	ft::vector<int>::iterator it2_my(it1_my);
	it2_my = my.end();
	init_vector_all(&orig, &my);

	std::cout << "all test operator\n";
	time_orig = clock();

	// Test_class test_clas_var;
	// test_clas_var.iter = it1_orig;
	// test_iter(test_clas_var, &test_clas_var);

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
