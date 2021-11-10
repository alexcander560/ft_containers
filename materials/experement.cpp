#include <iostream>

class Base {
	public:
	Base(const int &b): a(b){}
	~Base(){}
	protected:
	int a;
};

class A : public Base {
public:
	A(const int& b): Base(b){};
	~A(){};
};

class B : public Base {
public:
	B(const int& b): Base(b){};
	B (const A& ex): Base(0) {

		B& k = (B&)ex;
		this->a = k.a;
	}

	void Print() {
		std::cout << this->a << std::endl;
	}
	~B(){};
};


int main (void) {

	A a(5);

	B k(a);

	k.Print();

}