#include <vector>
#include <iostream>
#include <string>
#include <iomanip>

#include "vector.hpp"

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

int	all_test = 0;

// Изменение цветов строки
void	print_rev(std::string str)
{
	std::cout << REVERS << str << DEFAULT << std::endl;
}

std::string	print_status(bool t)
{
	std::string ret;
	if (t)
		ret =  GREEN " OK " DEFAULT;
	else
		ret = RED " KO " DEFAULT;
	return (ret);
}

// Печать вектора std
template <typename T>
void	print_vector(std::vector<T> a)
{
	int	size = a.size();
	for (int i = 0; i < size; i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;
}

// Печать вектора ft
template <typename T>
void	print_vector(ft::vector<T> a)
{
	int	size = a.size();
	std::cout << "size= "<< size << std::endl;
	std::cout << "max_size= "<< a.max_size() << std::endl;
	std::cout << "at(size)= "<< a.at(a.size() - 1) << std::endl;
	std::cout << "empty= "<< a.empty() << std::endl;

	try
	{
		std::cout << "at(-1)= "<< a.at(-1) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << "at(size - 1)= "<< a.at(a.size()) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < size; i++)
		std::cout << a[i] << " ";
	std::cout << std::endl;
}

// Печать вектора std, затем ft
template <typename T>
void	print_vector_orig_my(std::vector<T> a_orig, ft::vector<T> a_my)
{
	std::cout << "--------------------" << std::endl;
	print_rev("ORIG");
	print_vector(a_orig);
	print_rev("MY");
	print_vector(a_my);
	std::cout << "--------------------" << std::endl;
}

// Печать начала/конца таблицы
void	print_vector_all_head(bool t)
{
	if (t)
	{
		std::cout
		<< REVERS << "|-------------------------------------------------------------------|" << DEFAULT << std::endl
		<< REVERS << "|" << DEFAULT << std::setw (20) << "param"
		<< REVERS << "|" << DEFAULT << std::setw (20) << "original"
		<< REVERS << "|" << DEFAULT << std::setw (20) << "my" <<
		REVERS << "|" << DEFAULT << "    " << REVERS << "|" << DEFAULT << std::endl
		<< REVERS << "|-------------------------------------------------------------------|" << std::endl;
	}
	else
	{
		std::cout << REVERS << "|-------------------------------------------------------------------|" << DEFAULT << std::endl;
	}
}

// Печать строки табоицы
bool	print_vector_all_str(std::string str, std::string orig, std::string my)
{
	all_test++;
	bool ret = (orig == my ? true : false);

	std::cout
	<< REVERS << "|" << DEFAULT << std::setw (20) << str
	<< REVERS << "|" << DEFAULT << std::setw (20) << orig
	<< REVERS << "|" << DEFAULT << std::setw (20) << my
	<< REVERS << "|" << DEFAULT << print_status(ret)
	<< REVERS << "|" << DEFAULT << std::endl;
	
	return (ret);
}

// Иницилихация вектора std
template <typename T>
void	init_vector(std::vector<T>* a)
{
	int	size = (*a).size();
	for (int i = 0; i < size; i++)
		(*a)[i] = (rand() % RANDOM) + 0.5;
}

// Иницилихация вектора ft
template <typename T>
void	init_vector(ft::vector<T>* a)
{
	int	size = (*a).size();
	for (int i = 0; i < size; i++)
		(*a)[i] = (rand() % RANDOM) + 0.5;
}

// Иницилихация вектора std, ft одними параметрами
template <typename T>
void	init_vector_all(std::vector<T>* a_orig, ft::vector<T>* a_my)
{
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

// Печать тестовой таблицы
template <typename T>
void	test_tabl(std::vector<T> a_orig, ft::vector<T> a_my)
{
	std::string	temp_orig, temp_my;
	int 		point = 0;

	// печать заголовка
	print_vector_all_head(1);
	
	// печать элементов
	int size_orig = a_orig.size();
	for (int i = 0; i < size_orig; i++)
		temp_orig += std::to_string(a_orig[i]) + " ";
	int size_my = a_my.size();
	for (int i = 0; i < size_my; i++)
		temp_my += std::to_string(a_my[i]) + " ";
	point += print_vector_all_str("elements", temp_orig, temp_my);

	// .size()
	temp_orig = std::to_string(a_orig.size());
	temp_my = std::to_string(a_my.size());
	point += print_vector_all_str("size", temp_orig, temp_my);

	// .max_size()
	temp_orig = std::to_string(a_orig.max_size());
	temp_my = std::to_string(a_my.max_size());
	point += print_vector_all_str("max_size", temp_orig, temp_my);

	// .at(a_orig.size() - 1)
	try { temp_orig = std::to_string(a_orig.at(a_orig.size() - 1)); }
	catch(const std::exception& e) { temp_orig = e.what(); }
	try { temp_my = std::to_string(a_my.at(a_my.size() - 1)); }
	catch(const std::exception& e){ temp_my = e.what(); }
	point += print_vector_all_str("at(size - 1)", temp_orig, temp_my);

	// .at(a_orig.size())
	try { temp_orig = std::to_string(a_orig.at(a_orig.size())); }
	catch(const std::exception& e) { temp_orig = e.what(); }
	try { temp_my = std::to_string(a_my.at(a_my.size())); }
	catch(const std::exception& e){ temp_my = e.what(); }
	point += print_vector_all_str("at(size)", temp_orig, temp_my);

	// .empty()
	temp_orig = std::to_string(a_orig.empty());
	temp_my = std::to_string(a_my.empty());
	point += print_vector_all_str("empty", temp_orig, temp_my);

	//.capacity()
	temp_orig = std::to_string(a_orig.capacity());
	temp_my = std::to_string(a_my.capacity());
	point += print_vector_all_str("capacity", temp_orig, temp_my);

	//.front()
	temp_orig = std::to_string(a_orig.front());
	temp_my = std::to_string(a_my.front());
	point += print_vector_all_str("front", temp_orig, temp_my);

	//.back()
	temp_orig = std::to_string(a_orig.back());
	temp_my = std::to_string(a_my.back());
	point += print_vector_all_str("back", temp_orig, temp_my);
	//.get_allocator()
	// Проверить вручную?
	//==
	temp_orig = std::to_string(a_orig == a_orig);
	temp_my = std::to_string(a_my == a_my);
	point += print_vector_all_str("operator==", temp_orig, temp_my);
	//!=
	temp_orig = std::to_string(a_orig != a_orig);
	temp_my = std::to_string(a_my != a_my);
	point += print_vector_all_str("operator!=", temp_orig, temp_my);
	//<
	temp_orig = std::to_string(a_orig < a_orig);
	temp_my = std::to_string(a_my < a_my);
	point += print_vector_all_str("operator<", temp_orig, temp_my);

	//<=
	temp_orig = std::to_string(a_orig <= a_orig);
	temp_my = std::to_string(a_my <= a_my);
	point += print_vector_all_str("operator<=", temp_orig, temp_my);

	//>
	temp_orig = std::to_string(a_orig > a_orig);
	temp_my = std::to_string(a_my > a_my);
	point += print_vector_all_str("operator>", temp_orig, temp_my);

	//>=
	temp_orig = std::to_string(a_orig >= a_orig);
	temp_my = std::to_string(a_my >= a_my);
	point += print_vector_all_str("operator>=", temp_orig, temp_my);

	//reserve()
	a_orig.reserve(a_orig.size() + 2);
	a_my.reserve(a_my.size() + 2);
	temp_orig = std::to_string(a_orig.capacity());
	temp_my = std::to_string(a_my.capacity());
	point += print_vector_all_str("reserve(+2,capacity)", temp_orig, temp_my);

	/*

	//pop_back()
	a_orig.pop_back();
	a_my.pop_back();
	point += print_vector_all_str("pop_back", "", "");
	// .size()
	temp_orig = std::to_string(a_orig.size());
	temp_my = std::to_string(a_my.size());
	point += print_vector_all_str("size", temp_orig, temp_my);
	//.capacity()
	temp_orig = std::to_string(a_orig.capacity());
	temp_my = std::to_string(a_my.capacity());
	point += print_vector_all_str("capacity", temp_orig, temp_my);
	//[size()]()
	temp_orig = std::to_string(a_orig[a_orig.size()]);
	temp_my = std::to_string(a_my[a_my.size()]);
	point += print_vector_all_str("[size()]", temp_orig, temp_my);

	*/

	// печать конца таблицы
	print_vector_all_head(0);
	float finish = (float)point/(float)all_test * 100;
	std::cout << point << "/" << all_test << "(" << std::setprecision(4) << finish << "%)" << std::endl;
}

// Основаная функция
int	main()
{
	std::srand(time(NULL));
	//----------
	int size = 4;
	std::vector<int> orig(size);
	ft::vector<int> my(size);
	//----------
	//----------
	init_vector_all(&orig, &my);
	test_tabl(orig, my);


	// std::vector<double> orig_float(size - 2);
	// ft::vector<double> my_float(size - 2);
	// init_vector_all(&orig_float, &my_float);
	// test_tabl(orig_float, my_float);

	//----------
	//----------
	//std::string str_test_leaks;
	//getline(std::cin, str_test_leaks);
	//----------

	return (0);
}
