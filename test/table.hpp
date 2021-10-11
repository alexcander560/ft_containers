#include "test.hpp"

int	all_test = 0;
int	width = 35;

// Печать булевого значения с красивом виде
std::string	print_status(bool t)
{
	std::string ret;
	if (t)
		ret = GREEN " OK " DEFAULT;
	else
		ret = RED " KO " DEFAULT;
	return (ret);
}

// Возвразает строку со строкой умноженной на n раз
std::string	str_n(std::string str, int n)
{
	std::string new_str;

	for (size_t i = 0; i < (size_t)n; i++)
		new_str += str;	

	return (new_str);
}

// Возвращает строку с инвертированными цветами
std::string	str_revers(std::string str)
{
	std::string new_str = REVERS + str + DEFAULT;
	return (new_str);
}

// Печать строки табоицы (возвращает истину если строки равны)
bool	table_str(std::string str, std::string orig, std::string my)
{
	all_test++;
	bool ret = (orig == my ? true : false);

	std::cout
	<< str_revers("|") << std::setw (width) << str
	<< str_revers("|") << std::setw (width) << orig
	<< str_revers("|") << std::setw (width) << my
	<< str_revers("|") << print_status(ret)
	<< str_revers("|") << std::endl;
	
	return (ret);
}

// Печать начала/конца таблицы
void	table_head(int t)
{
	if (t == 1)
	{
		std::cout
		<< str_revers("|") << str_revers(str_n("-", (width * 3) + 7)) << str_revers("|") << std::endl
		<< str_revers("|") << std::setw (width) << "param"
		<< str_revers("|") << std::setw (width) << "original"
		<< str_revers("|") << std::setw (width) << "my"
		<< str_revers("|") << str_n(" ", 4) << str_revers("|") << std::endl
		<< str_revers("|") << str_revers(str_n("-", (width * 3) + 7)) << str_revers("|") << std::endl;
	}
	else if (t == 2)
		std::cout << str_revers("|") << str_revers(str_n ("-", (width * 3) + 7)) << str_revers("|") << std::endl;
	else if (t == 3)
	{
		std::cout
		<< str_revers("|") << str_n ("-", width)
		<< str_revers("|") << str_n ("-", width)
		<< str_revers("|") << str_n ("-", width)
		<< str_revers("|") << str_n ("-", 4)
		<< str_revers("|") << std::endl;
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
// Тест на iterators
template <typename T>
int	table_iterators(std::vector<T> *a_orig, ft::vector<T> *a_my, bool f)
{
	std::string	temp_orig, temp_my;
	int	point = 0;

	typename std::vector<T>::iterator it1 = (*a_orig).begin();
	typename std::vector<T>::iterator it2 = (*a_orig).end();
	typename ft::vector<T>::iterator it3 = (*a_my).begin();
	typename ft::vector<T>::iterator it4 = (*a_my).end();
	typename std::vector<T>::reverse_iterator it5 = (*a_orig).rbegin();
	typename std::vector<T>::reverse_iterator it6 = (*a_orig).rend();
	typename ft::vector<T>::reverse_iterator it7 = (*a_my).rbegin();
	typename ft::vector<T>::reverse_iterator it8 = (*a_my).rend();

	temp_orig = std::to_string(*((*a_orig).begin() - 0));
	temp_my = std::to_string(*((*a_my).begin() - 0));
	point += table_str("begin", temp_orig, temp_my);

	temp_orig = std::to_string(*((*a_orig).end() - 1));
	temp_my = std::to_string(*((*a_my).end() - 1));
	point += table_str("end-1", temp_orig, temp_my);

	temp_orig = std::to_string(*((*a_orig).rbegin() - 0));
	temp_my = std::to_string(*((*a_my).rbegin() - 0));
	point += table_str("rbegin-1", temp_orig, temp_my);

	temp_orig = std::to_string(*((*a_orig).rend() - 1));
	temp_my = std::to_string(*((*a_my).rend() - 1));
	point += table_str("end-1", temp_orig, temp_my);

	temp_orig = "";
	temp_my = "";
	while (it1 != it2)
		temp_orig += std::to_string(*it1++) + " ";
	while (it3 != it4)
		temp_my += std::to_string(*it3++) + " ";
	point += table_str("begin - end", temp_orig, temp_my);

	temp_orig = "";
	temp_my = "";
	while (it5 != it6)
		temp_orig += std::to_string(*it5++) + " ";
	while (it7 != it8)
		temp_my += std::to_string(*it7++) + " ";
	point += table_str("begin - end", temp_orig, temp_my);

	if (f)
		table_head(3);
	return (point);
}
// Тест на iterators const
template <typename T>
int	table_iterators_const(std::vector<T> *a_orig, ft::vector<T> *a_my, bool f)
{
	std::string	temp_orig, temp_my;
	int	point = 0;

	const std::vector<T> orig(*a_orig);
	const ft::vector<T> my(*a_my);

	typename std::vector<T>::const_iterator it1 = orig.begin();
	typename std::vector<T>::const_iterator it2 = orig.end();
	typename ft::vector<T>::const_iterator it3 = my.begin();
	typename ft::vector<T>::const_iterator it4 = my.end();
	typename std::vector<T>::const_reverse_iterator it5 = orig.rbegin();
	typename std::vector<T>::const_reverse_iterator it6 = orig.rend();
	typename ft::vector<T>::const_reverse_iterator it7 = my.rbegin();
	typename ft::vector<T>::const_reverse_iterator it8 = my.rend();

	temp_orig = std::to_string(*(orig.begin() - 0));
	temp_my = std::to_string(*(my.begin() - 0));
	point += table_str("begin (const)", temp_orig, temp_my);

	temp_orig = std::to_string(*(orig.end() - 1));
	temp_my = std::to_string(*(my.end() - 1));
	point += table_str("end-1 (const)", temp_orig, temp_my);

	temp_orig = std::to_string(*(orig.rbegin() - 0));
	temp_my = std::to_string(*(my.rbegin() - 0));
	point += table_str("rbegin-1 (const)", temp_orig, temp_my);

	temp_orig = std::to_string(*(orig.rend() - 1));
	temp_my = std::to_string(*(my.rend() - 1));
	point += table_str("end-1 (const)", temp_orig, temp_my);

	temp_orig = "";
	temp_my = "";
	while (it1 != it2)
		temp_orig += std::to_string(*it1++) + " ";
	while (it3 != it4)
		temp_my += std::to_string(*it3++) + " ";
	point += table_str("begin - end (const)", temp_orig, temp_my);

	temp_orig = "";
	temp_my = "";
	while (it5 != it6)
		temp_orig += std::to_string(*it5++) + " ";
	while (it7 != it8)
		temp_my += std::to_string(*it7++) + " ";
	point += table_str("begin - end (const)", temp_orig, temp_my);	

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

	point += table_str("at((size - 1) / 2)", temp_orig, temp_my);

	try { temp_orig = std::to_string((*a_orig).at((*a_orig).size() - 1)); }
	catch(const std::exception& e) { temp_orig = e.what(); }
	try { temp_my = std::to_string((*a_my).at((*a_my).size() - 1)); }
	catch(const std::exception& e){ temp_my = e.what(); }

	point += table_str("at(size - 1)", temp_orig, temp_my);

	try { temp_orig = std::to_string((*a_orig).at((*a_orig).size())); }
	catch(const std::exception& e) { temp_orig = e.what(); }
	try { temp_my = std::to_string((*a_my).at((*a_my).size())); }
	catch(const std::exception& e){ temp_my = e.what(); }

	point += table_str("at(size)", temp_orig, temp_my);

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

	point += table_str("reserve(size + 3)", " ", " ");
	point += table_size(a_orig, a_my, 0);
	point += table_capacity(a_orig, a_my, 0);
	point += table_elements(a_orig, a_my, 0);

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

	point += table_str("resize(size - 1)", " ", " ");
	(*a_orig).resize((*a_orig).size() - 1);
	(*a_my).resize((*a_my).size() - 1);
	point += table_size(a_orig, a_my, 0);
	point += table_capacity(a_orig, a_my, 0);
	point += table_elements(a_orig, a_my, 0);

	point += table_str("resize(size + 2)", " ", " ");
	(*a_orig).resize((*a_orig).size() + 2);
	(*a_my).resize((*a_my).size() + 2);
	point += table_size(a_orig, a_my, 0);
	point += table_capacity(a_orig, a_my, 0);
	point += table_elements(a_orig, a_my, 0);

	point += table_str("resize(size + 3)", " ", " ");
	(*a_orig).resize((*a_orig).size() + 3);
	(*a_my).resize((*a_my).size() + 3);
	point += table_size(a_orig, a_my, 0);
	point += table_capacity(a_orig, a_my, 0);
	point += table_elements(a_orig, a_my, 0);

	if (f)
		table_head(3);
	return (point);
}
// Тест pop_back
template <typename T>
int	table_pop_back(std::vector<T> *a_orig, ft::vector<T> *a_my, bool f)
{
	std::string	temp_orig, temp_my;
	int			point = 0;

	point += table_str("pop_back 5 times", " ", " ");
	(*a_orig).pop_back();
	(*a_my).pop_back();
	(*a_orig).pop_back();
	(*a_my).pop_back();
	(*a_orig).pop_back();
	(*a_my).pop_back();
	(*a_orig).pop_back();
	(*a_my).pop_back();
	(*a_orig).pop_back();
	(*a_my).pop_back();
	point += table_size(a_orig, a_my, 0);
	point += table_capacity(a_orig, a_my, 0);
	point += table_elements(a_orig, a_my, 0);

	if (f)
		table_head(3);
	return (point);
}
// Тест push_back
template <typename T>
int	table_push_back(std::vector<T> *a_orig, ft::vector<T> *a_my, bool f)
{
	std::string	temp_orig, temp_my;
	int			point = 0;

	point += table_str("push_back(7) 2 times", " ", " ");
	(*a_orig).push_back(7);
	(*a_my).push_back(7);
	(*a_orig).push_back(7);
	(*a_my).push_back(7);
	point += table_size(a_orig, a_my, 0);
	point += table_capacity(a_orig, a_my, 0);
	point += table_elements(a_orig, a_my, 0);

	if (f)
		table_head(3);
	return (point);
}
// Тест insert
template <typename T>
int	table_insert_1(std::vector<T> *a_orig, ft::vector<T> *a_my, bool f)
{
	std::string	temp_orig, temp_my;
	int			point = 0;

	point += table_str("insert(begin, 4), insert(end, 4)", " ", " ");

	(*a_orig).insert((*a_orig).begin(), 4);
	(*a_my).insert((*a_my).begin(), 4);
	(*a_orig).insert((*a_orig).end(), 4);
	(*a_my).insert((*a_my).end(), 4);
	point += table_size(a_orig, a_my, 0);
	point += table_capacity(a_orig, a_my, 0);
	point += table_elements(a_orig, a_my, 0);

	if (f)
		table_head(3);
	return (point);
}
// Тест insert
template <typename T>
int	table_insert_2(std::vector<T> *a_orig, ft::vector<T> *a_my, bool f)
{
	std::string	temp_orig, temp_my;
	int			point = 0;

	point += table_str("insert(begin, 2, 42)", " ", " ");

	(*a_orig).insert((*a_orig).begin(), (size_t)2, 42);
	(*a_my).insert((*a_my).begin(), (size_t)2, 42);
	point += table_size(a_orig, a_my, 0);
	point += table_capacity(a_orig, a_my, 0);
	point += table_elements(a_orig, a_my, 0);

	if (f)
		table_head(3);
	return (point);
}
// Тест insert
template <typename T>
int	table_insert_3(std::vector<T> *a_orig, ft::vector<T> *a_my, bool f)
{
	std::string	temp_orig, temp_my;
	int			point = 0;

	point += table_str("insert(begin, begin, begin + 2)", " ", " ");

	typename std::vector<T>::iterator it4 = (*a_orig).begin();
	typename std::vector<T>::iterator it5 = (*a_orig).begin();
	typename std::vector<T>::iterator it6 = (*a_orig).begin() + 2;

	typename ft::vector<T>::iterator it1 = (*a_my).begin();
	typename ft::vector<T>::iterator it2 = (*a_my).begin();
	typename ft::vector<T>::iterator it3 = (*a_my).begin() + 2;
	

	(*a_orig).insert(it4, it5, it6);
	(*a_my).insert(it1, it2, it3);

	point += table_size(a_orig, a_my, 0);
	point += table_capacity(a_orig, a_my, 0);
	point += table_elements(a_orig, a_my, 0);

	if (f)
		table_head(3);
	return (point);
}
// Тест clear
template <typename T>
int	table_clear(std::vector<T> *a_orig, ft::vector<T> *a_my, bool f)
{
	std::string	temp_orig, temp_my;
	int			point = 0;

	point += table_str("clear", " ", " ");
	(*a_orig).clear();
	(*a_my).clear();

	point += table_size(a_orig, a_my, 0);
	point += table_capacity(a_orig, a_my, 0);
	point += table_elements(a_orig, a_my, 0);

	if (f)
		table_head(3);
	return (point);
}
// Тест operator =
template <typename T>
int	table_operator_1(std::vector<T> a1_orig, std::vector<T> a2_orig,
					ft::vector<T> a1_my, ft::vector<T> a2_my,
					std::string str1, std::string str2, bool f)
{
	f = f + 1 - 1;
	std::string	temp_orig, temp_my;
	int			point = 0;

	temp_orig = std::to_string(a1_orig==a2_orig);
	temp_my = std::to_string(a1_my==a2_my);
	point += table_str(str1 + "==" + str2, temp_orig, temp_my);

	return (point);
}

// Тест operator !=
template <typename T>
int	table_operator_2(std::vector<T> a1_orig, std::vector<T> a2_orig,
					ft::vector<T> a1_my, ft::vector<T> a2_my,
					std::string str1, std::string str2, bool f)
{
	f = f + 1 - 1;
	std::string	temp_orig, temp_my;
	int			point = 0;

	temp_orig = std::to_string(a1_orig!=a2_orig);
	temp_my = std::to_string(a1_my!=a2_my);
	point += table_str(str1 + "!=" + str2, temp_orig, temp_my);

	return (point);
}

// Тест operator <
template <typename T>
int	table_operator_3(std::vector<T> a1_orig, std::vector<T> a2_orig,
					ft::vector<T> a1_my, ft::vector<T> a2_my,
					std::string str1, std::string str2, bool f)
{
	f = f + 1 - 1;
	std::string	temp_orig, temp_my;
	int			point = 0;

	temp_orig = std::to_string(a1_orig<a2_orig);
	temp_my = std::to_string(a1_my<a2_my);
	point += table_str(str1 + "<" + str2, temp_orig, temp_my);

	return (point);
}

// Тест operator <=
template <typename T>
int	table_operator_4(std::vector<T> a1_orig, std::vector<T> a2_orig,
					ft::vector<T> a1_my, ft::vector<T> a2_my,
					std::string str1, std::string str2, bool f)
{
	f = f + 1 - 1;
	std::string	temp_orig, temp_my;
	int			point = 0;

	temp_orig = std::to_string(a1_orig<=a2_orig);
	temp_my = std::to_string(a1_my<=a2_my);
	point += table_str(str1 + "<=" + str2, temp_orig, temp_my);

	return (point);
}

// Тест operator >
template <typename T>
int	table_operator_5(std::vector<T> a1_orig, std::vector<T> a2_orig,
					ft::vector<T> a1_my, ft::vector<T> a2_my,
					std::string str1, std::string str2, bool f)
{
	f = f + 1 - 1;
	std::string	temp_orig, temp_my;
	int			point = 0;

	temp_orig = std::to_string(a1_orig>a2_orig);
	temp_my = std::to_string(a1_my>a2_my);
	point += table_str(str1 + ">" + str2, temp_orig, temp_my);

	return (point);
}

// Тест operator >=
template <typename T>
int	table_operator_6(std::vector<T> a1_orig, std::vector<T> a2_orig,
					ft::vector<T> a1_my, ft::vector<T> a2_my,
					std::string str1, std::string str2, bool f)
{
	f = f + 1 - 1;
	std::string	temp_orig, temp_my;
	int			point = 0;

	temp_orig = std::to_string(a1_orig>=a2_orig);
	temp_my = std::to_string(a1_my>=a2_my);
	point += table_str(str1 + ">=" + str2, temp_orig, temp_my);

	return (point);
}

// Тест operator
template <typename T>
int	table_operator(std::vector<T> *a_orig, ft::vector<T> *a_my, bool f)
{
	std::string	temp_orig, temp_my;
	int			point = 0;

	(std::vector<T>) *a_orig;
	(ft::vector<T>) *a_my;

	table_head(3);

	std::vector<T> b1_orig;
	b1_orig.push_back(7);
	b1_orig.push_back(4);
	b1_orig.push_back(2);
	ft::vector<T> b1_my;
	b1_my.push_back(7);
	b1_my.push_back(4);
	b1_my.push_back(2);

	std::vector<T> b2_orig;
	b2_orig.push_back(7);
	b2_orig.push_back(4);
	b2_orig.push_back(1);
	ft::vector<T> b2_my;
	b2_my.push_back(7);
	b2_my.push_back(4);
	b2_my.push_back(1);

	std::vector<T> b3_orig;
	b3_orig.push_back(7);
	b3_orig.push_back(4);
	b3_orig.push_back(3);
	ft::vector<T> b3_my;
	b3_my.push_back(7);
	b3_my.push_back(4);
	b3_my.push_back(3);

	std::vector<T> b4_orig;
	b4_orig.push_back(7);
	b4_orig.push_back(4);
	b4_orig.push_back(2);
	b4_orig.push_back(9);
	ft::vector<T> b4_my;
	b4_my.push_back(7);
	b4_my.push_back(4);
	b4_my.push_back(2);
	b4_my.push_back(9);

	std::vector<T> b5_orig;
	b5_orig.push_back(7);
	b5_orig.push_back(4);
	ft::vector<T> b5_my;
	b5_my.push_back(7);
	b5_my.push_back(4);

	point += table_str("b1", "", "");
	point += table_elements(&b1_orig, &b1_my, 0);
	point += table_str("b2", "", "");
	point += table_elements(&b2_orig, &b2_my, 0);
	point += table_str("b3", "", "");
	point += table_elements(&b3_orig, &b3_my, 0);
	point += table_str("b4", "", "");
	point += table_elements(&b4_orig, &b4_my, 0);
	point += table_str("b5", "", "");
	point += table_elements(&b5_orig, &b5_my, 0);

	table_head(3);
	point += table_operator_1(b1_orig, b1_orig, b1_my, b1_my, "b1", "b1", 0);
	point += table_operator_1(b1_orig, b2_orig, b1_my, b2_my, "b1", "b2", 0);
	point += table_operator_1(b1_orig, b3_orig, b1_my, b3_my, "b1", "b3", 0);
	point += table_operator_1(b1_orig, b4_orig, b1_my, b4_my, "b1", "b4", 0);
	point += table_operator_1(b1_orig, b5_orig, b1_my, b5_my, "b1", "b5", 0);

	table_head(3);
	point += table_operator_2(b1_orig, b1_orig, b1_my, b1_my, "b1", "b1", 0);
	point += table_operator_2(b1_orig, b2_orig, b1_my, b2_my, "b1", "b2", 0);
	point += table_operator_2(b1_orig, b3_orig, b1_my, b3_my, "b1", "b3", 0);
	point += table_operator_2(b1_orig, b4_orig, b1_my, b4_my, "b1", "b4", 0);
	point += table_operator_2(b1_orig, b5_orig, b1_my, b5_my, "b1", "b5", 0);

	table_head(3);
	point += table_operator_3(b1_orig, b1_orig, b1_my, b1_my, "b1", "b1", 0);
	point += table_operator_3(b1_orig, b2_orig, b1_my, b2_my, "b1", "b2", 0);
	point += table_operator_3(b1_orig, b3_orig, b1_my, b3_my, "b1", "b3", 0);
	point += table_operator_3(b1_orig, b4_orig, b1_my, b4_my, "b1", "b4", 0);
	point += table_operator_3(b1_orig, b5_orig, b1_my, b5_my, "b1", "b5", 0);

	table_head(3);
	point += table_operator_4(b1_orig, b1_orig, b1_my, b1_my, "b1", "b1", 0);
	point += table_operator_4(b1_orig, b2_orig, b1_my, b2_my, "b1", "b2", 0);
	point += table_operator_4(b1_orig, b3_orig, b1_my, b3_my, "b1", "b3", 0);
	point += table_operator_4(b1_orig, b4_orig, b1_my, b4_my, "b1", "b4", 0);
	point += table_operator_4(b1_orig, b5_orig, b1_my, b5_my, "b1", "b5", 0);

	table_head(3);
	point += table_operator_5(b1_orig, b1_orig, b1_my, b1_my, "b1", "b1", 0);
	point += table_operator_5(b1_orig, b2_orig, b1_my, b2_my, "b1", "b2", 0);
	point += table_operator_5(b1_orig, b3_orig, b1_my, b3_my, "b1", "b3", 0);
	point += table_operator_5(b1_orig, b4_orig, b1_my, b4_my, "b1", "b4", 0);
	point += table_operator_5(b1_orig, b5_orig, b1_my, b5_my, "b1", "b5", 0);

	table_head(3);
	point += table_operator_6(b1_orig, b1_orig, b1_my, b1_my, "b1", "b1", 0);
	point += table_operator_6(b1_orig, b2_orig, b1_my, b2_my, "b1", "b2", 0);
	point += table_operator_6(b1_orig, b3_orig, b1_my, b3_my, "b1", "b3", 0);
	point += table_operator_6(b1_orig, b4_orig, b1_my, b4_my, "b1", "b4", 0);
	point += table_operator_6(b1_orig, b5_orig, b1_my, b5_my, "b1", "b5", 0);

	if (f)
		table_head(3);
	table_head(3);
	return (point);
}

// Тест swap
template <typename T>
int	table_swap(std::vector<T> *a_orig, ft::vector<T> *a_my, bool f)
{
	std::string	temp_orig, temp_my;
	int	point = 0;

	std::vector<T> orig(3);
	ft::vector<T> my(3);
	init_vector_all(&orig, &my);

	point += table_str("no changes", " ", " ");
	point += table_elements(a_orig, a_my, 0);
	point += table_size(a_orig, a_my, 0);
	point += table_capacity(a_orig, a_my, 0);
	swap (*a_orig, orig);
	swap (*a_my, my);
	point += table_str("swap(2 arg)", " ", " ");	
	point += table_elements(a_orig, a_my, 0);
	point += table_size(a_orig, a_my, 0);
	point += table_capacity(a_orig, a_my, 0);
	(*a_orig).swap(orig);
	(*a_my).swap(my);
	point += table_str("swap(1 arg)", " ", " ");
	point += table_elements(a_orig, a_my, 0);
	point += table_size(a_orig, a_my, 0);
	point += table_capacity(a_orig, a_my, 0);

	if (f)
		table_head(3);
	return (point);
}

// Тест assign
template <typename T>
int	table_assign(std::vector<T> *a_orig, ft::vector<T> *a_my, bool f)
{
	std::string	temp_orig, temp_my;
	int	point = 0;

	std::vector<T> orig(3);
	ft::vector<T> my(3);
	init_vector_all(&orig, &my);

	// point += table_str("no changes", " ", " ");
	// point += table_elements(a_orig, a_my, 0);
	// point += table_size(a_orig, a_my, 0);
	// point += table_capacity(a_orig, a_my, 0);

	point += table_str("assign(iterator)", " ", " ");
	(*a_orig).assign (orig.begin(), orig.end());
	(*a_my).assign (my.begin(), my.end());
	point += table_elements(a_orig, a_my, 0);
	point += table_size(a_orig, a_my, 0);
	point += table_capacity(a_orig, a_my, 0);

	point += table_str("assign(10, 42)", " ", " ");
	(*a_orig).assign (10, 42);
	(*a_my).assign ((size_t)10, 42);
	point += table_elements(a_orig, a_my, 0);
	point += table_size(a_orig, a_my, 0);
	point += table_capacity(a_orig, a_my, 0);

	if (f)
		table_head(3);
	return (point);
}

// Тест erase
template <typename T>
int	table_erase(std::vector<T> *a_orig, ft::vector<T> *a_my, bool f)
{
	std::string	temp_orig, temp_my;
	int	point = 0;

	std::vector<T> orig(3);
	ft::vector<T> my(3);
	init_vector_all(&orig, &my);

	// point += table_str("no changes", " ", " ");
	// point += table_elements(a_orig, a_my, 0);
	// point += table_size(a_orig, a_my, 0);
	// point += table_capacity(a_orig, a_my, 0);

	point += table_str("erase(begin)", " ", " ");
	(*a_orig).erase ((*a_orig).begin());
	(*a_my).erase ((*a_my).begin());
	point += table_elements(a_orig, a_my, 0);
	point += table_size(a_orig, a_my, 0);
	point += table_capacity(a_orig, a_my, 0);

	point += table_str("erase(end - 1)", " ", " ");
	(*a_orig).erase ((*a_orig).end() - 1);
	(*a_my).erase ((*a_my).end() - 1);
	point += table_elements(a_orig, a_my, 0);
	point += table_size(a_orig, a_my, 0);
	point += table_capacity(a_orig, a_my, 0);

	point += table_str("erase(begin, begin)", " ", " ");
	(*a_orig).erase ((*a_orig).begin(), (*a_orig).begin());
	(*a_my).erase ((*a_my).begin(), (*a_my).begin());
	point += table_elements(a_orig, a_my, 0);
	point += table_size(a_orig, a_my, 0);
	point += table_capacity(a_orig, a_my, 0);

	point += table_str("erase(end, end)", " ", " ");
	(*a_orig).erase ((*a_orig).end(), (*a_orig).end());
	(*a_my).erase ((*a_my).end(), (*a_my).end());
	point += table_elements(a_orig, a_my, 0);
	point += table_size(a_orig, a_my, 0);
	point += table_capacity(a_orig, a_my, 0);

	point += table_str("erase(begin + 1, end - 1)", " ", " ");
	(*a_orig).erase ((*a_orig).begin() + 1, (*a_orig).end() - 1);
	(*a_my).erase ((*a_my).begin() + 1, (*a_my).end() - 1);
	point += table_elements(a_orig, a_my, 0);
	point += table_size(a_orig, a_my, 0);
	point += table_capacity(a_orig, a_my, 0);

	//std::cout << "OOO= " << (*a_orig)[2] << "\n";



	if (f)
		table_head(3);
	return (point);
}

// Тест методов, коорые имеют 2 реализации c const и без
template <typename T>
int	table_const(std::vector<T> *a_orig, ft::vector<T> *a_my, bool f)
{
	std::string	temp_orig, temp_my;
	int	point = 0;

	const std::vector<T> orig(*a_orig);
	const ft::vector<T> my(*a_my);

	temp_orig = std::to_string(orig[0]);
	temp_my = std::to_string(my[0]);
	point += table_str("[0] (const)", temp_orig, temp_my);

	temp_orig = std::to_string(orig.at(0));
	temp_my = std::to_string(my.at(0));
	point += table_str("at(0) (const)", temp_orig, temp_my);
	
	temp_orig = std::to_string(orig.front());
	temp_my = std::to_string(my.front());
	point += table_str("front() (const)", temp_orig, temp_my);

	temp_orig = std::to_string(orig.back());
	temp_my = std::to_string(my.back());
	point += table_str("back() (const)", temp_orig, temp_my);

	if (f)
		table_head(3);
	return (point);
}

// Тест Allocator
template <typename T>
int	table_allocator(std::vector<T> *a_orig, ft::vector<T> *a_my, bool f)
{
	std::string	temp_orig, temp_my;
	int	point = 0;

	// std::allocator<T> orig = (*a_orig).get_allocator();
	// std::allocator<T> my = (*a_my).get_allocator();
	(*a_orig).get_allocator();
	(*a_my).get_allocator();

	// bool rez = (orig == my);
	// std::cout << rez << std::endl;
	
	point += table_str("get_allocator", "?", "?");


	if (f)
		table_head(3);
	return (point);
}

// Печать тестовой таблицы
template <typename T>
void	test_tabl(std::vector<T> a_orig, ft::vector<T> a_my)
{
	std::string	temp_orig, temp_my;
	int 		point = 0;

	// печать заголовка
	table_head(1);

	point += table_elements(&a_orig, &a_my, 1);
	point += table_size(&a_orig, &a_my, 1);
	point += table_iterators(&a_orig, &a_my, 1);
	point += table_iterators_const(&a_orig, &a_my, 1);
	point += table_max_size(&a_orig, &a_my, 1);
	point += table_at(&a_orig, &a_my, 1);
	point += table_empty(&a_orig, &a_my, 1);
	point += table_capacity(&a_orig, &a_my, 1);
	point += table_front(&a_orig, &a_my, 1);
	point += table_back(&a_orig, &a_my, 1);
	point += table_reserve(&a_orig, &a_my, 1);
	point += table_resize(&a_orig, &a_my, 1);
	point += table_pop_back(&a_orig, &a_my, 1);
	point += table_push_back(&a_orig, &a_my, 1);
	point += table_insert_1(&a_orig, &a_my, 1);
	point += table_insert_2(&a_orig, &a_my, 1);
	point += table_insert_3(&a_orig, &a_my, 1);
	point += table_operator(&a_orig, &a_my, 1);
	point += table_swap(&a_orig, &a_my, 1);
	point += table_assign(&a_orig, &a_my, 1);
	point += table_erase(&a_orig, &a_my, 1);
	point += table_const(&a_orig, &a_my, 1);
	point += table_clear(&a_orig, &a_my, 1); 
	point += table_allocator(&a_orig, &a_my, 0);

	//std::cout << "Hello\n";

	// печать конца таблицы

	table_head(2);
	float finish = (float)point/(float)all_test * 100;
	std::cout << point << "/" << all_test << "(" << std::setprecision(4) << finish << "%)" << std::endl;
	//std::cout << "Hello\n";
}
