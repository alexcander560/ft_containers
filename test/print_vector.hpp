#include "test.hpp"

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
	std::cout << REVERS << "ORIG" << DEFAULT << std::endl;
	print_vector(a_orig);
	std::cout << REVERS << "MY" << DEFAULT << std::endl;
	print_vector(a_my);
	std::cout << "--------------------" << std::endl;
}
