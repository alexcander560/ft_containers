#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
#include <stdio.h>
#include <unistd.h>

#include "../vector.hpp"

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

// Иницилихация вектора std, ft одними параметрами
template <typename T>
void	init_vector_all(std::vector<T>* a_orig, ft::vector<T>* a_my)
{
	std::srand(time(NULL));
	int	size_orig = (*a_orig).size();
	int	size_my = (*a_my).size();
	if (size_orig != size_my)
	{
		std::cout << "Error size" << std::endl;
		return ;
	}
	for (int i = 0; i < size_orig; i++)
		(*a_orig)[i] = (*a_my)[i] = (rand() % RANDOM) + 0.5;
}

// Иницилихация вектора std
template <typename T>
void	init_vector(std::vector<T>* a)
{
	std::srand(time(NULL));
	int	size = (*a).size();
	for (int i = 0; i < size; i++)
		(*a)[i] = (rand() % RANDOM) + 0.5;
}

// Иницилихация вектора ft
template <typename T>
void	init_vector(ft::vector<T>* a)
{
	std::srand(time(NULL));
	int	size = (*a).size();
	for (int i = 0; i < size; i++)
		(*a)[i] = (rand() % RANDOM) + 0.5;
}

// Печать булевого значения с красивом виде
std::string	print_status(bool t)
{
	std::string ret;
	if (t)
		ret =  GREEN " OK " DEFAULT;
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
	//std::cout << "orig\n" << "str long... =(" << "\n";
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
	//std::cout << orig << " " << my;

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
std::string	vektor_base_test(std::vector<T> *a)
{
	size_t size = 0;
	std::string	temp = "";

	size = (*a).size();
	temp += " size=" + std::to_string(size) + " capacity=" + std::to_string((*a).capacity()) + " elem=";
	for (size_t i = 0; i < size; i++)
		temp += std::to_string((*a)[i]);

	return (temp);
}

template <typename T>
std::string	vektor_base_test(ft::vector<T> *a)
{
	size_t size = 0;
	std::string	temp = "";

	size = (*a).size();
	temp += " size=" + std::to_string(size) + " capacity=" + std::to_string((*a).capacity()) + " elem=";
	for (size_t i = 0; i < size; i++)
		temp += std::to_string((*a)[i]);

	return (temp);
}
