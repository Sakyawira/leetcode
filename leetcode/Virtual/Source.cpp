#include <iostream>

class machine {
public:
	virtual void StartEngine() = 0;
};

class vehicle : public machine {
public:
	void StartEngine() override{
		std::cout << "vehicle!" << std::endl;
	}
};

class car : public vehicle {
public:
	void StartEngine() override{
		std::cout << "Car!" << std::endl;
	}
};


int main(){
	vehicle v;
	v.StartEngine();

	car c;
	c.StartEngine();

	std::cin.get();
}