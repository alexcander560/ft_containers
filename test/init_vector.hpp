#include "test.hpp"

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
