#include <vector>
#include "vector.hpp"
#include <iostream>

#include <set>
#include <map>
#include "map.hpp"

using namespace std;

int main()
{
	std::map<int, int>orig;
	orig.insert(std::pair<int, int>(42, 42));
	orig.insert(std::pair<int, int>(43, 43));
	orig.insert(std::pair<int, int>(44, 44));
	std::map<int, int>::iterator orig_it_1(orig.begin());
	std::map<int, int>::const_iterator orig_it_2;
	const std::map<int, int>::iterator orig_it_3;

	const std::map<int, int>orig_c(orig);
	orig_it_2 = orig_c.find(43);
	cout << orig_it_2->first << endl;

	cout << "==========\n";


	ft::map<int, int>my;

	my.insert(ft::pair<int, int>(42, 42));
	my.insert(ft::pair<int, int>(43, 43));
	my.insert(ft::pair<int, int>(44, 44));

	ft::map<int, int>::iterator my_it_1(my.begin());
	ft::map<int, int>::const_iterator my_it_2;

	const ft::map<int, int>my_c(my);

	cout << my.size() << endl;
	my_it_1 = my.find(43);
	cout << my_it_1->first << endl;

	cout << my_c.size() << endl;

	cout << my_c.find(43)->first << endl;

	my_it_2 = my_c.find(43);
	cout << my_it_2->first << endl;


	cout << "END\n";
	return (0);
}
