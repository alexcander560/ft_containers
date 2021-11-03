#include <map>
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <stdio.h>
#include <unistd.h>

#include "../map.hpp"

# define DEFAULT	"\033[0m"
# define BOLD		"\033[1m"
# define UNDERLINE	"\033[4m"
# define REVERS		"\033[7m"
# define RED		"\033[31m"
# define GREEN		"\033[32m"
# define YELLOW		"\033[33m"
# define BLUE		"\033[34m"
# define AQUA		"\033[36m"

# define RANDOM		1000
# define STR_PART	100
# define STR_MAX	1000

# define SIZE_0		0
# define SIZE_1		1
# define SIZE_2		2
# define SIZE_10	10
# define SIZE_100	100
# define SIZE_200	200
# define SIZE_1K	1000
# define SIZE_2K	2000
# define SIZE_10K	10000
# define SIZE_20K	20000
# define SIZE_100K	100000
# define SIZE_200K	200000
# define SIZE_1M	1000000
# define SIZE_2M	2000000
# define SIZE_10M	10000000
# define SIZE_20M	20000000
# define SIZE_100M	100000000
# define SIZE_200M	200000000

//# define clear() printf("\033[H\033[J")

using namespace std;

// Иницилихация стака std, ft одними параметрами заданной длины
void	init_map(std::map<int, std::string>* a_orig, ft::map<int, std::string>* a_my, int size)
{
	if (size < 0)
		std::cout << "Error size" << std::endl;
	else
	{
		int			temp;
		std::string	temp_str;

		std::srand(time(NULL));
		for (int i = 0; i < size; i++)
		{
			temp = (rand() % RANDOM);
			temp_str = std::to_string(temp) + "_str";

			(*a_orig).insert(std::pair<int, std::string>(temp, temp_str));
			(*a_my).insert(ft::pair<int, std::string>(temp, temp_str));
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
		std::cout << print_status(1) << std::endl;
		return (0);
	}
	else
	{
		std::cout << print_status(0) << std::endl;
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
		std::cout << print_status(1) << GREEN "slower " << std::setprecision(4) << temp << DEFAULT << std::endl;
		return (0);
	}
	else
	{
		std::cout << print_status(0) << RED " KO " DEFAULT;
		std::cout << RED "slower " << std::setprecision(4) << temp << DEFAULT << std::endl;
		return (1);
	}
}

std::string	map_base_test(std::map<int, std::string>* a)
{
	size_t size = 0;
	std::string	temp = "";

	std::map<int, std::string>::iterator it_1 = a->begin();
	std::map<int, std::string>::iterator it_2 = a->end();

	size = (*a).size();
	temp += " size=" + std::to_string(size) + " elem=";

	for (; it_1 != it_2; it_1++)
		temp += "(" + std::to_string(it_1->first) + ", " + it_1->second + ") ";
	
	return (temp);
}

std::string	map_base_test(ft::map<int, std::string>* a)
{
	size_t size = 0;
	std::string	temp = "";

	ft::map<int, std::string>::iterator it_1 = a->begin();
	ft::map<int, std::string>::iterator it_2 = a->end();

	size = (*a).size();
	temp += " size=" + std::to_string(size) + " elem=";

	for (; it_1 != it_2; it_1++)
		temp += "(" + std::to_string(it_1->first) + ", " + it_1->second + ") ";
	
	return (temp);
}
