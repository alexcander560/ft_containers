#include <iostream> 
#include <string>
 
using namespace std;

class SomeString
{
	private:
		std::string m_string;
	public:
		explicit SomeString(int a) { m_string.resize(a); }
	
		SomeString(const char *string) { m_string = string; }
	
		friend std::ostream& operator<<(std::ostream& out, const SomeString &s);
};
 
std::ostream& operator<<(std::ostream& out, const SomeString &s)
{
	out << s.m_string;
	return out;
}
 
class SomeString1
{
	private:
		std::string m_string;
	public:
		SomeString1(int a) { m_string.resize(a); }
	
		SomeString1(const char *string) { m_string = string; }
	
		friend std::ostream& operator<<(std::ostream& out, const SomeString1 &s);
};
 
std::ostream& operator<<(std::ostream& out, const SomeString1 &s)
{
	out << s.m_string;
	return out;
}

int main()
{	
	{
		SomeString mystring1(10);
		SomeString mystring2("A");
		SomeString mystring3('a');
		SomeString mystring4 = "A";
		//SomeString mystring5 = 'a'; // нельзя (так как explicit)

		std::cout << "(" << mystring1 << ")" << endl;
		std::cout << "(" << mystring2 << ")" << endl;
		std::cout << "(" << mystring3 << ")" << endl;
		std::cout << "(" << mystring4 << ")" << endl;
		//std::cout << mystring5 << endl;
	}

	cout << "-------------------\n";

	{
		SomeString1 mystring1(10);
		SomeString1 mystring2("A");
		SomeString1 mystring3('a');
		SomeString1 mystring4 = "A";
		SomeString1 mystring5 = 'a'; // можно, но хотелось, что бы не было неявных преобразований

		std::cout << "(" << mystring1 << ")" << endl;
		std::cout << "(" << mystring2 << ")" << endl;
		std::cout << "(" << mystring3 << ")" << endl;
		std::cout << "(" << mystring4 << ")" << endl;
		std::cout << "(" << mystring5 << ")" << endl; // а может мы хотели что бы так было делать нельзя?
	}

	return (0);
}
