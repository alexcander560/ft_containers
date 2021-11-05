#include <stack>
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <stdio.h>
#include <unistd.h>

#include "../stack.hpp"

# define DEFAULT	"\033[0m"
# define BOLD		"\033[1m"
# define UNDERLINE	"\033[4m"
# define REVERS		"\033[7m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define AQUA		"\033[36m"

# define RANDOM		10
# define STR_PART	100
# define STR_MAX	1000

# define SIZE_0		0
# define SIZE_1		1
# define SIZE_10	10
# define SIZE_100	100
# define SIZE_1K	1000
# define SIZE_10K	10000
# define SIZE_50K	50000
# define SIZE_100K	100000
# define SIZE_1M	1000000
# define SIZE_10M	10000000
# define SIZE_100M	100000000

using namespace std;

// Иницилихация стака std, ft одними параметрами заданной длины
template <typename T>
void	init_stack(std::stack<T>* a_orig, ft::stack<T>* a_my, int size)
{
	if (size < 0)
		std::cout << "Error size" << std::endl;
	else
	{
		T temp = 0;

		std::srand(time(NULL));
		for (int i = 0; i < size; i++)
		{
			temp = (rand() % RANDOM) + 0.5;
			(*a_orig).push(temp);
			(*a_my).push(temp);
		}
	}
}

std::string	print_status(bool t)
{
	std::string ret;
	if (t)
		ret = GREEN " OK " DEFAULT;
	else
		ret = RED " KO " DEFAULT;
	return (ret);
}

void	print_status_comp_str(std::string name, std::string str)
{
	size_t	len = str.length();
	bool	flag = false;

	std::cout << name << std::endl;;

	if (len < STR_MAX)
		std::cout << str << "\n";
	else
	{
		size_t i = 0;

		for (; i < len && i < STR_PART; i++)
			std::cout << str[i];
		std::cout << "... ";
		for (; i < len; i++)
		{
			if (str[i] == 's')
				break ;
		}
		for (size_t j = i; j < len && j < i + STR_PART; j++)
		{
			std::cout << str[j];
			flag = true;
		}
		if (flag == true)
			std::cout << "... ";
	}
	std::cout << std::endl;
}

bool	print_status_comp(std::string orig, std::string my)
{
	std::string ret;

	std::cout << "Comp: ";
	if (orig == my)
	{
		std::cout << "" GREEN " OK \n" DEFAULT;
		return (0);
	}
	else
	{
		std::cout << RED " KO \n" DEFAULT;
		print_status_comp_str("orig", orig);
		print_status_comp_str("my", my);
		return (1);
	}
}

bool	print_status_time(int orig, int my)
{
	if (orig == 0 || my == 0)
	{
		orig++;
		my++;
	}
	float temp = (float)my/(float)orig;

	std::cout << "Time: ";
	std::string ret;
	if (temp < 20)
	{	
		std::cout << "" GREEN " OK " DEFAULT;
		std::cout << GREEN "slower " << std::setprecision(4) << temp << DEFAULT << std::endl;
		return (0);
	}
	else
	{
		std::cout << RED " KO " DEFAULT;
		std::cout << RED "slower " << std::setprecision(4) << temp << DEFAULT << std::endl;
		return (1);
	}
}

template <typename T>
std::string	stack_base_test(T *a)
{
	std::string	temp = "";

	temp += " size=" + std::to_string((*a).size()) + " top=" + std::to_string((*a).top());

	return (temp);
}
