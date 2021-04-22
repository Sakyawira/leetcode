#include <iostream>

// Forward declaration
class A;
class B;

class B {
public:
	int x = 1;
	void print(A a) /*{
		std::cout << "B prints the variable of A: " << a.y << std::endl;
	}*/;
};

class A {
public:
	int y = 2;
	void print(B b);
};

int main()
{
	int i;
	A a;
	B b;

	a.print(b);
	b.print(a);
	std::cin >> i;
}

void B::print(A a) {
	std::cout << "B prints the variable of A: " << a.y << std::endl;
}
void A::print(B b) {
	std::cout << "A prints the variable of B: " << b.x << std::endl;
}
