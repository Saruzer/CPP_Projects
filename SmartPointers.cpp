#include <iostream>
class A {
private:
	/* Fields */
public:
	A() 
	{
		std::cout << "Constructor\n";
	}
	~A() {
		std::cout << "Destructor\n";
	}
	void Hello() {
		std::cout << "Hello!\n";
	}
	/*Other methods*/
};
template<typename T>
class SmartPointer {
private:
	T* ptr;

public:
	SmartPointer(T* object) : ptr(object) {}
	~SmartPointer() {
		delete ptr;
	}
	T* operator->() {
		return ptr;
	}
	T& operator*() {
		return *ptr;
	}
};

void Function() {
	std::cout << "Function Started\n";
	
	SmartPointer<A> smartPtr1(new A());

	smartPtr1->Hello();

	std::cout << "Function Ended\n";
}

int main() {
	
	Function();
	SmartPointer<int> smartPtr2(new int{5});
	std::cout << *smartPtr2 << std::endl;
	
	return 0;
}