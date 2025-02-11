#include<iostream>
#pragma region 1.static_cast
namespace StaticCast
{
	class A 
	{
	private:
		int variableA;
	public:
		void MethodA() 
		{ 
			std::cout << "MethodA was called! \n"; 
			variableA = 10;
		}
		void CnstMethodA() const
		{
			std::cout << "Const MethodA was called! \n";
		}
	};
	class B : public A
	{
	private:
		int variableB;
	public:
		void MethodB() 
		{ 
			std::cout << "MethodB was called! \n"; 
			variableB = 10;
		}
		void CnstMethodB() const 
		{
			std::cout << "Const MethodB was called! \n";
		}
	};
	class Number {
	private:
		int num = 1000;
	public:
		explicit operator int() const { return num; }
	};
}
void Func(const StaticCast::A* objects, size_t size) 
{
	for (size_t i = 0; i < size; i++)
	{
		objects[i].CnstMethodA();
	}
	const StaticCast::B objectB = static_cast<const StaticCast::B&>(objects[size - 1]);
	objectB.CnstMethodB();
	objectB.CnstMethodA();
}
void Static_CastTest() 
{
	StaticCast::A objectA;
	StaticCast::B objectB;
	//Upcast
	StaticCast::A* ptrA = &objectB;
	ptrA->MethodA();
	//Downcast
	StaticCast::B* ptrB = static_cast<StaticCast::B*>(&objectA);
	ptrB->MethodA();
	//ptrB->MethodB(); //Error

	int num{};
	StaticCast::Number numberClass;
	num = static_cast<int>(numberClass);
	std::cout << num;
}

#pragma endregion



int main() {

	Static_CastTest();
	
	return 0;
}