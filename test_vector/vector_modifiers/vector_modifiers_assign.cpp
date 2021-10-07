#include "../test_utility.cpp"

int	main ()
{
	std::string	temp_orig = "", temp_my = "";
	unsigned int time_orig = 0, time_my = 0, rez = 0;

	std::cout << "Заглушка assign (2 реализации)" << std::endl;
	temp_orig = "", temp_my = "";
	std::vector<int> orig_1(1);
	ft::vector<int> my_1(1);
	init_vector_all(&orig_1, &my_1);

	time_orig = clock();
	/*
	действия оригинала
	*/
	time_orig = clock() - time_orig;

	time_my = clock();
	/*
	действия мои
	*/
	time_my = clock() - time_my;

	rez += print_status_comp(temp_orig, temp_my);
	rez += print_status_time(time_orig, time_my);

	return (!rez);
}
