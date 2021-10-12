#include "test.hpp"
#include "init_vector.hpp"
#include "print_vector.hpp"
#include "table.hpp"

int	main(/*int argc, char **argv*/)
{
	std::srand(time(NULL));
	int size = 4;
	std::vector<int> orig(size);
	ft::vector<int> my(size);

	init_vector_all(&orig, &my);
	test_tabl(orig, my);

	return (0);
}
