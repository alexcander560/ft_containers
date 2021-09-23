#include "../test_utility.cpp"

int	main ()
{
	unsigned int time_orig = 0, time_my = 0, rez = 0;

	std::vector<int> orig_1;
	ft::vector<int> my_1;

	std::vector<int> orig_2(SIZE_100K);
	ft::vector<int> my_2(SIZE_100K);

	std::vector<int> orig_3(orig_2);
	ft::vector<int> my_3(my_2);

	init_vector_all(&orig_3, &my_3);
	std::vector<int> orig_4(orig_3.begin() + 13, orig_3.end() - 42);
	ft::vector<int> my_4(my_3.begin() + 13, my_3.end() - 42);

	time_orig = clock();
	orig_1.get_allocator();
	orig_2.get_allocator();
	orig_3.get_allocator();
	orig_4.get_allocator();
	time_orig = clock() - time_orig;

	time_my = clock();
	my_1.get_allocator();
	my_2.get_allocator();
	my_3.get_allocator();
	my_4.get_allocator();
	time_my = clock() - time_my;

	//rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);
	std::cout << "check SELF! allocator_type get_allocator() const { return (_alloc); }\n";

	return (rez);
}
