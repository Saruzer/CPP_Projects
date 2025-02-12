#include<iostream>

int main() {
	int a = 10;
	double b = 30.5;

	void* test;
	std::cout << "type of test variable:" << typeid(test).name() << std::endl;

	if (typeid(a) == typeid(b)) {
		std::cout << "type a == type b\n";
	}
	else
		std::cout << "type a != type b\n";
}