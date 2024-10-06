#include <iostream>
#include "Sort.cpp"
#include "Misc.cpp"

void (*GetRandomFunc())();

void Func1() {
	std::cout << "Func 1" << std::endl;
}
void Func2() {
	std::cout << "Func 2" << std::endl;
}
void Func3() {
	std::cout << "Func 3" << std::endl;
}

int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	void (*func)();
	func = GetRandomFunc();
	func();
	func = GetRandomFunc();
	func();
	func = GetRandomFunc();
	func();
	int* a;
}
void (*GetRandomFunc())()
{
	int funcNum = rand() % 3;
	switch (funcNum)
	{
	case 0:
		return Func1;
		break;
	case 1:
		return Func2;
		break;
	case 2:
		return Func3;
		break;
	default:
		return Func1;
		break;
	}
}