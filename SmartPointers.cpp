#include <iostream>
#pragma region Self Made Pointer
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
#pragma endregion
#pragma region Unique_ptr
class MyClass 
{
public:
	void Method(const char* text) const
	{
		std::cout << text;
	}
	MyClass() 
	{
		std::cout << "Constructor of MyClass\n";
	}
	~MyClass() 
	{
		std::cout << "Destructor of MyClass\n";
	}
};

struct MyDeleter {
	void operator()(int* ptr) {
		std::cout << "Deleting ptr\n";
		delete ptr;
	}
	void SAYHI() {
		std::cout << "Hi(from deleter!)\n";
	}
};

void UniquePtrTest() {
	std::unique_ptr<int, MyDeleter> ptr1{ new int(5), MyDeleter() };
	std::cout << "<std::move> ptr1 to ptr2\n";
	std::unique_ptr<int, MyDeleter> ptr2{std::move(ptr1)};

	std::unique_ptr<MyClass> ptr3{ new MyClass{} };
	
	ptr3->Method("Method called from ptr3\n");

	if (ptr3) {
		std::cout << "ptr3 pointer points to out object\n";
	}
	ptr3.get()->Method("Method called from ptr3.get()\n");

	//Get Deleter
	MyDeleter deleter;
	deleter = ptr1.get_deleter();
	deleter.SAYHI();
	
	//Release
	MyClass* UsualPtr;
	UsualPtr = ptr3.release();
	UsualPtr->Method("Method called from UsualPtr\n");
	delete UsualPtr;

	//Reset
	ptr2.reset();
}
#pragma endregion
#pragma region Shared_ptr
class Person
{
private:
	int age = 0;
	char name[20] = "NoName";
public:
	void SayHi() {
		std::cout << "Hi!\n";
	}
	Person() 
	{
		std::cout << "Default Consrtuctor\n";
	}
	Person(int age, const char* name) : age(age), name("SomeName")
	{
		std::cout << "Age/Name Consrtuctor\n";
	}
	~Person() 
	{
		std::cout << "Default Desrtuctor\n";
	}
};
void SharedPtrTest() {
	Person* somePerson = new Person{10,"name"};

	std::shared_ptr<Person> ptr1{somePerson};
	std::shared_ptr<Person> ptr2{ptr1};
	std::shared_ptr<Person> ptr3{ptr1};
	
	std::cout << ptr1 << std::endl;
	std::cout << ptr2 << std::endl;
	std::cout << ptr3 << std::endl;
	std::cout << "-----------"  << std::endl;
	ptr1.reset();
	std::cout << ptr1 << std::endl;
	std::cout << ptr2 << std::endl;
	std::cout << ptr3 << std::endl;
	ptr2.reset();
	ptr3->SayHi();
	ptr3.reset();
}
#pragma endregion

int main() {
	SharedPtrTest();
	return 0;
}