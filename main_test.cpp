#include "test_vector/test_utility.cpp"

int	main ()
{
	ft::vector<int> a(10);

	init_vector(&a);
	ft::vector<int> c(a);

	ft::vector<int> b(a.begin(), a.end());

	std::cout << vektor_base_test(&a);
	std::cout << "\n";
	std::cout << vektor_base_test(&c);
	std::cout << "\n";

	std::vector<int> f(1);

	std::vector<int>::iterator it_1 = f.begin();
	std::vector<int>::iterator it_2 = f.end();

	std::cout << *it_1;
	std::cout << *it_2;
	

	return (0);
}
