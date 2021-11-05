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
	std::cout << "Test 1/1\n";
	temp_orig = "", temp_my = "";

	time_orig = clock();
	for (size_t i = 0; i < size; i++)
	{
		orig_1.push(vec[i]);

		const std::stack<int> temp(orig_1);
		//const std::stack<int> temp = orig_1;

		temp_orig += std::to_string(temp.top());
		temp_orig += std::to_string(temp.top());
	}
	time_orig = clock() - time_orig;

	time_my = clock();
	for (size_t i = 0; i < size; i++)
	{
		my_1.push(vec[i]);

		const ft::stack<int> temp(my_1);
		//const ft::stack<int> temp = my_1;

		temp_my += std::to_string(temp.top());
		temp_my += std::to_string(temp.top());
	}
	time_my = clock() - time_my;
	//temp_my += " ";

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);

	//=============================================================

	return (!rez);
}
