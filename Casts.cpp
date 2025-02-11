#include<iostream>
#include<Windows.h>
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
#pragma region 2.dynamic_cast
namespace DynamicCast
{

	class Vehicle {
	private:
		// як≥сь загальн≥ пол€ дл€ транспорт≥в
	public:
		virtual ~Vehicle() = default;
	};

	class Apple : public Vehicle { };

	class Car : public Vehicle {
	public:
		void Drive() { std::cout << "Car is driving!\n"; }

	};
	class Bike : public Vehicle {
	public:
		void Pedal() { std::cout << "Bike is pedaling!\n"; }
	};
}

void Dynamic_CastTestVehicle(DynamicCast::Vehicle** v, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		DynamicCast::Car* car = dynamic_cast<DynamicCast::Car*>(v[i]);
		DynamicCast::Bike* bike = dynamic_cast<DynamicCast::Bike*>(v[i]);
		if (car != nullptr) {
			car->Drive();
		}
		else if (bike != nullptr) {
			bike->Pedal();
		}
		else {
			std::cout << "Unknown vehicle\n";
		}
	}
}
void Dynamic_CastTest()
{
	DynamicCast::Car car1;
	DynamicCast::Car car2;
	DynamicCast::Bike bike;
	DynamicCast::Apple APPLE;

	DynamicCast::Car* car1Ptr = &car1;
	DynamicCast::Car* car2Ptr = &car2;
	DynamicCast::Bike* bikePtr = &bike;
	DynamicCast::Apple* APPLEPtr = &APPLE;

	DynamicCast::Vehicle* v[4] = { car1Ptr ,bikePtr,car2Ptr,APPLEPtr };
	Dynamic_CastTestVehicle(v, 4);
}
#pragma endregion
#pragma region 3.const_cast
const int evil = 42;

namespace ConstCast
{
	
}
void Const_castTest()
{
	const int var = 100;
	std::cout << var << std::endl;
	int* ptr = const_cast<int*>(&var);
	*ptr = 0;
	std::cout << var << std::endl;

}
#pragma endregion



int main() {
	Const_castTest();
	return 0;
}