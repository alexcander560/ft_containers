#include <stack>
#include <iostream>
#include "stack.hpp"

int main ()
{
	std::cout << "Hello\n";

	std::stack<int> a;
	ft::stack<int> b;

	a.push(42);
	b.push(42);

	std::cout << a.top() << std::endl;
	std::cout << b.top() << std::endl;

	std::cout << (a == a) << std::endl;
	std::cout << (b == b) << std::endl;


	return (0);
}