#include "../test_utility_stack.cpp"

#include <vector>

int	main ()
{
	std::string	temp_orig = "", temp_my = "";
	unsigned int time_orig = 0, time_my = 0, rez = 0;
	size_t size = 100;

	std::stack<int> orig_1;
	ft::stack<int> my_1;

	std::vector<int> vec(size);
	for (size_t i = 0; i < size; i++)
		vec[i] = rand() % 10;
	
	//=============================================================
	std::cout << "size=0 push 100 use\n";
	temp_orig = "", temp_my = "";

	time_orig = clock();
	for (size_t i = 0; i < size; i++)
	{
		orig_1.push(vec[i]);
		temp_orig += std::to_string(orig_1.size());
	}
	time_orig = clock() - time_orig;

	time_my = clock();
	for (size_t i = 0; i < size; i++)
	{
		my_1.push(vec[i]);
		temp_my += std::to_string(my_1.size());
	}
	time_my = clock() - time_my;
	//temp_my += " ";

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);

	//=============================================================

	return (!rez);
}
