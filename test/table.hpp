#include "test.hpp"

int	all_test = 0;

std::string	print_status(bool t)
{
	std::string ret;
	if (t)
		ret =  GREEN " OK " DEFAULT;
	else
		ret = RED " KO " DEFAULT;
	return (ret);
}

// Печать строки табоицы (возвращает истину если строки равны)
bool	table_str(std::string str, std::string orig, std::string my)
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

// Печать начала/конца таблицы
void	table_head(int t)
{
	if (t == 1)
	{
		std::cout
		<< REVERS << "|-------------------------------------------------------------------|" << DEFAULT << std::endl
		<< REVERS << "|" << DEFAULT << std::setw (20) << "param"
		<< REVERS << "|" << DEFAULT << std::setw (20) << "original"
		<< REVERS << "|" << DEFAULT << std::setw (20) << "my" <<
		REVERS << "|" << DEFAULT << "    " << REVERS << "|" << DEFAULT << std::endl
		<< REVERS << "|-------------------------------------------------------------------|" << std::endl;
	}
	else if (t == 2)
		std::cout << REVERS << "|-------------------------------------------------------------------|" << DEFAULT << std::endl;
	else if (t == 3)
	{
		std::cout
		<< REVERS << "|" DEFAULT << "--------------------"
		<< REVERS << "|" DEFAULT << "--------------------"
		<< REVERS << "|" DEFAULT << "--------------------"
		<< REVERS << "|" DEFAULT "----"
		<< REVERS << "|" DEFAULT << std::endl;
	}
}

// Тест на содержимое вектора
template <typename T>
int	table_elements(std::vector<T> *a_orig, ft::vector<T> *a_my, bool f)
{
	std::string	temp_orig, temp_my;
	int size_orig = (*a_orig).size();
	int size_my = (*a_my).size();
	int	point = 0;

	for (int i = 0; i < size_orig; i++)
		temp_orig += std::to_string((*a_orig)[i]) + " ";
	for (int i = 0; i < size_my; i++)
		temp_my += std::to_string((*a_my)[i]) + " ";
	point += table_str("elements", temp_orig, temp_my);

	if (f)
		table_head(3);
	return (point);
}
// Тест на длину вектора
template <typename T>
int	table_size(std::vector<T> *a_orig, ft::vector<T> *a_my, bool f)
{
	std::string	temp_orig, temp_my;
	int	point = 0;

	temp_orig = std::to_string((*a_orig).size());
	temp_my = std::to_string((*a_my).size());
	point += table_str("size", temp_orig, temp_my);

	if (f)
		table_head(3);
	return (point);
}
// Тест на max_size
template <typename T>
int	table_max_size(std::vector<T> *a_orig, ft::vector<T> *a_my, bool f)
{
	std::string	temp_orig, temp_my;
	int	point = 0;

	temp_orig = std::to_string((*a_orig).max_size());
	temp_my = std::to_string((*a_my).max_size());
	point += table_str("max_size", temp_orig, temp_my);

	if (f)
		table_head(3);
	return (point);
}
// Тест at
template <typename T>
int	table_at(std::vector<T> *a_orig, ft::vector<T> *a_my, bool f)
{
	std::string	temp_orig, temp_my;
	int			point = 0;

	try { temp_orig = std::to_string((*a_orig).at(0)); }
	catch(const std::exception& e) { temp_orig = e.what(); }
	try { temp_my = std::to_string((*a_my).at(0)); }
	catch(const std::exception& e){ temp_my = e.what(); }

	point += table_str("at(0)", temp_orig, temp_my);

	try { temp_orig = std::to_string((*a_orig).at(((*a_orig).size() - 1)/2)); }
	catch(const std::exception& e) { temp_orig = e.what(); }
	try { temp_my = std::to_string((*a_my).at(((*a_orig).size() - 1)/2)); }
	catch(const std::exception& e){ temp_my = e.what(); }

	point += table_str("at(.size() - 1)/2)", temp_orig, temp_my);

	try { temp_orig = std::to_string((*a_orig).at((*a_orig).size() - 1)); }
	catch(const std::exception& e) { temp_orig = e.what(); }
	try { temp_my = std::to_string((*a_my).at((*a_my).size() - 1)); }
	catch(const std::exception& e){ temp_my = e.what(); }

	point += table_str("at(.size() - 1)", temp_orig, temp_my);

	try { temp_orig = std::to_string((*a_orig).at((*a_orig).size())); }
	catch(const std::exception& e) { temp_orig = e.what(); }
	try { temp_my = std::to_string((*a_my).at((*a_my).size())); }
	catch(const std::exception& e){ temp_my = e.what(); }

	point += table_str("at(.size())", temp_orig, temp_my);

	try { temp_orig = std::to_string((*a_orig).at(-1)); }
	catch(const std::exception& e) { temp_orig = e.what(); }
	try { temp_my = std::to_string((*a_my).at(-1)); }
	catch(const std::exception& e){ temp_my = e.what(); }

	point += table_str("at(-1)", temp_orig, temp_my);

	if (f)
		table_head(3);
	return (point);
}
// Тест empty
template <typename T>
int	table_empty(std::vector<T> *a_orig, ft::vector<T> *a_my, bool f)
{
	std::string	temp_orig, temp_my;
	int			point = 0;

	temp_orig = std::to_string((*a_orig).empty());
	temp_my = std::to_string((*a_my).empty());
	point += table_str("empty", temp_orig, temp_my);

	std::vector<int> b_orig;
	ft::vector<int> b_my;
	temp_orig = std::to_string(b_orig.empty());
	temp_my = std::to_string(b_my.empty());
	point += table_str("empty(size = 0)", temp_orig, temp_my);

	if (f)
		table_head(3);
	return (point);
}
// Тест capacity
template <typename T>
int	table_capacity(std::vector<T> *a_orig, ft::vector<T> *a_my, bool f)
{
	std::string	temp_orig, temp_my;
	int			point = 0;

	temp_orig = std::to_string((*a_orig).capacity());
	temp_my = std::to_string((*a_my).capacity());
	point += table_str("capacity", temp_orig, temp_my);

	if (f)
		table_head(3);
	return (point);
}
// Тест front
template <typename T>
int	table_front(std::vector<T> *a_orig, ft::vector<T> *a_my, bool f)
{
	std::string	temp_orig, temp_my;
	int			point = 0;

	temp_orig = std::to_string((*a_orig).front());
	temp_my = std::to_string((*a_my).front());
	point += table_str("front", temp_orig, temp_my);

	if (f)
		table_head(3);
	return (point);
}
// Тест back
template <typename T>
int	table_back(std::vector<T> *a_orig, ft::vector<T> *a_my, bool f)
{
	std::string	temp_orig, temp_my;
	int			point = 0;

	temp_orig = std::to_string((*a_orig).back());
	temp_my = std::to_string((*a_my).back());
	point += table_str("back", temp_orig, temp_my);

	if (f)
		table_head(3);
	return (point);
}
// Тест reserve
template <typename T>
int	table_reserve(std::vector<T> *a_orig, ft::vector<T> *a_my, bool f)
{
	std::string	temp_orig, temp_my;
	int			point = 0;

	(*a_orig).reserve((*a_orig).size() + 3);
	(*a_my).reserve((*a_my).size() + 3);

	(*a_orig).reserve((*a_orig).size() - 1);
	(*a_my).reserve((*a_my).size() - 1);

	point += table_str("reserve(size()+3)", " ", " ");
	table_size(a_orig, a_my, 0);
	table_capacity(a_orig, a_my, 0);
	table_elements(a_orig, a_my, 0);

	if (f)
		table_head(3);
	return (point);
}
// Тест resize
template <typename T>
int	table_resize(std::vector<T> *a_orig, ft::vector<T> *a_my, bool f)
{
	std::string	temp_orig, temp_my;
	int			point = 0;

	point += table_str("resize(.size() - 1)", " ", " ");
	(*a_orig).resize((*a_orig).size() - 1);
	(*a_my).resize((*a_my).size() - 1);
	table_size(a_orig, a_my, 0);
	table_capacity(a_orig, a_my, 0);
	table_elements(a_orig, a_my, 0);

	point += table_str("resize(.size() + 2)", " ", " ");
	(*a_orig).resize((*a_orig).size() + 2);
	(*a_my).resize((*a_my).size() + 2);
	table_size(a_orig, a_my, 0);
	table_capacity(a_orig, a_my, 0);
	table_elements(a_orig, a_my, 0);

	point += table_str("resize(.size() + 3)", " ", " ");
	(*a_orig).resize((*a_orig).size() + 3);
	(*a_my).resize((*a_my).size() + 3);
	table_size(a_orig, a_my, 0);
	table_capacity(a_orig, a_my, 0);
	table_elements(a_orig, a_my, 0);

	table_head(3);
	return (point);
}


// Печать тестовой таблицы
template <typename T>
void	test_tabl(std::vector<T> a_orig, ft::vector<T> a_my)
{
	std::string	temp_orig, temp_my;
	int 		point = 0;
	int			size_orig, size_my;

	// печать заголовка
	table_head(1);
	point += table_elements(&a_orig, &a_my, 1);
	point += table_size(&a_orig, &a_my, 1);
	point += table_max_size(&a_orig, &a_my, 1);
	point += table_at(&a_orig, &a_my, 1);
	point += table_empty(&a_orig, &a_my, 1);
	point += table_capacity(&a_orig, &a_my, 1);
	point += table_front(&a_orig, &a_my, 1);
	point += table_back(&a_orig, &a_my, 1);
	point += table_reserve(&a_orig, &a_my, 1);
	point += table_resize(&a_orig, &a_my, 1);

	return ;

	/*
	//==
	temp_orig = std::to_string(a_orig == a_orig);
	temp_my = std::to_string(a_my == a_my);
	point += table_str("operator==", temp_orig, temp_my);
	//!=
	temp_orig = std::to_string(a_orig != a_orig);
	temp_my = std::to_string(a_my != a_my);
	point += table_str("operator!=", temp_orig, temp_my);
	//<
	temp_orig = std::to_string(a_orig < a_orig);
	temp_my = std::to_string(a_my < a_my);
	point += table_str("operator<", temp_orig, temp_my);

	//<=
	temp_orig = std::to_string(a_orig <= a_orig);
	temp_my = std::to_string(a_my <= a_my);
	point += table_str("operator<=", temp_orig, temp_my);

	//>
	temp_orig = std::to_string(a_orig > a_orig);
	temp_my = std::to_string(a_my > a_my);
	point += table_str("operator>", temp_orig, temp_my);

	//>=
	temp_orig = std::to_string(a_orig >= a_orig);
	temp_my = std::to_string(a_my >= a_my);
	point += table_str("operator>=", temp_orig, temp_my);
	*/

	/*
	//clear()
	(*a_orig).clear();
	(*a_my).clear();
	temp_orig = std::to_string((*a_orig).capacity());
	temp_my = std::to_string((*a_my).capacity());
	point += table_str("clear()", temp_orig, temp_my);

	temp_orig = ""; 
	temp_my= "";
	// печать элементов
	size_orig = (*a_orig).size();
	for (int i = 0; i < size_orig; i++)
		temp_orig += std::to_string(a_orig[i]) + " ";
	size_my = (*a_my).size();
	for (int i = 0; i < size_my; i++)
		temp_my += std::to_string(a_my[i]) + " ";
	point += table_str("elements", temp_orig, temp_my);
	*/

	/*
	//pop_back()
	(*a_orig).pop_back();
	(*a_my).pop_back();
	point += table_str("pop_back", "", "");
	// .size()
	temp_orig = std::to_string((*a_orig).size());
	temp_my = std::to_string((*a_my).size());
	point += table_str("size", temp_orig, temp_my);
	//.capacity()
	temp_orig = std::to_string((*a_orig).capacity());
	temp_my = std::to_string((*a_my).capacity());
	point += table_str("capacity", temp_orig, temp_my);
	//[size()]()
	temp_orig = std::to_string(a_orig[(*a_orig).size()]);
	temp_my = std::to_string(a_my[(*a_my).size()]);
	point += table_str("[size()]", temp_orig, temp_my);

	// печать элементов
	temp_orig = ""; 
	temp_my= "";
	size_orig = (*a_orig).size();
	for (int i = 0; i < size_orig; i++)
		temp_orig += std::to_string(a_orig[i]) + " ";
	size_my = (*a_my).size();
	for (int i = 0; i < size_my; i++)
		temp_my += std::to_string(a_my[i]) + " ";
	point += table_str("elements", temp_orig, temp_my);

	// .resize()
	(*a_orig).resize(5);
	(*a_my).resize(5);
	temp_orig = ""; 
	temp_my= "";
	size_orig = (*a_orig).size();
	for (int i = 0; i < size_orig; i++)
		temp_orig += std::to_string(a_orig[i]) + " ";
	size_my = (*a_my).size();
	for (int i = 0; i < size_my; i++)
		temp_my += std::to_string(a_my[i]) + " ";
	point += table_str("elements", temp_orig, temp_my);
	*/

	// печать конца таблицы
	table_head(2);
	float finish = (float)point/(float)all_test * 100;
	std::cout << point << "/" << all_test << "(" << std::setprecision(4) << finish << "%)" << std::endl;
}
