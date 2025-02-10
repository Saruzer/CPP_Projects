#include <iostream>
#pragma region 1. Encapsulation
class User {
private:
	int age;
public:
	void SetAge(int age) {
		if (age > 0) {
			this->age = age;
		}
	}
};
#pragma endregion
#pragma region 2. Inheritance realization
class Human {
private:
	int age;
public:
	void Rest() { std::cout << "Resting\n"; }
};
class Worker : public Human {
public:
	void Work() { std::cout << "Working\n"; }
};
void Test2InheritanceRealization() {
	Human h;
	Worker w;
	std::cout << "Class Human: \n";
	h.Rest();
	std::cout << "Class Worker : public Human: \n";
	w.Work();
	w.Rest();

}
#pragma endregion
#pragma region 3. Protected
class A {
private:
	void Method1() { std::cout << "Called private Method1\n"; }
protected:
	void Method2() { std::cout << "Called protected Method2\n"; }
public:
	A() { Method1(); }
	void Method3() { std::cout << "Called public Method3\n"; }
};
class B : public A {
public:
	B() { Method2(); }
};
void Test3Protected() 
{
	std::cout << "Class A: \n";
	A a;
	a.Method3();
	std::cout << "Class B: \n";
	B b;
	b.Method3();

}
		

#pragma endregion
#pragma region 4. Inheritance & Constructor
class Array {
private:
	int* arr;
	size_t size;
public:
	Array(size_t size) : size(0), arr(nullptr)
	{
		if (size > 0) {
			this->size = size;
			arr = new int[size] {};
		}
	};
	Array(const Array& other) : size(other.size), arr(nullptr)
	{
		if (other.size > 0) {
			this->arr = new int[other.size];
			for (size_t i = 0; i < size; i++) {
				this->arr[i] = other.arr[i];
			}
		}
	};
	~Array() 
	{
		delete[] arr;
		arr = nullptr;
	};

	size_t Size() const { return size; }
	Array operator=(const Array& other) 
	{
		if (this != &other) 
		{
			this->~Array();

			this->size = other.size;

			if (other.size > 0) {
				this->arr = new int[other.size];
				for (size_t i = 0; i < size; i++) {
					this->arr[i] = other.arr[i];
				}
			}
		}
		return *this;
	};
	int& operator[](size_t index) 
	{
		if (index < size) {
			return arr[index];
		}
		std::exit(1);
	};
	const int& operator[](size_t index) const
	{
		if (index < size) {
			return arr[index];
		}

		std::exit(1);
	};
};
class MathArray : public Array {
public:
	MathArray(size_t size) : Array(size) {}
	int Sum() const 
	{
		if (Size() == 0) {
			return 0;
		}
		int sum = 0;

		for (size_t i = 0; i < Size(); i++)
		{
			sum += (*this)[i];
		}

		return sum;
	}
	int Product() const 
	{
		if (Size() == 0) {
			return 0;
		}
		int product = 1;

		for (size_t i = 0; i < Size(); i++)
		{
			product *= (*this)[i];
		}

		return product;
	}
	int Max() const
	{
		if (Size() == 0) {
			return 0;
		}
		int max = (*this)[0];

		for (size_t i = 0; i < Size(); i++)
		{
			if (max < (*this)[i])
				max = (*this)[i];
		}

		return max;
	}
	int Min() const
	{
		if (Size() == 0) {
			return 0;
		}
		int min = (*this)[0];

		for (size_t i = 0; i < Size(); i++)
		{
			if (min > (*this)[i])
				min = (*this)[i];
		}

		return min;
	}
	double Average() const
	{
		if (Size() == 0)
			return 0;
		
		double sum = Sum();
		return sum / Size();
	}

};

class C 
{
public:
	C() { std::cout << "C::C()\n"; }
	C(int a) { std::cout << "C::C(int a)\n"; }
	C(int a, int b) { std::cout << "C::C(int a, int b)\n"; }
	C(const C& other) { std::cout << "C::C(const C& other)\n"; }
	C(C&& other) { std::cout << "C::C(C&& other)\n"; }
	void operator=(const C& other) { std::cout << "operator=(const C& other)\n"; }
};

class D : public C 
{
public:
	D() : C() { std::cout << "D::D()\n"; }
	D(int a) : C(a) { std::cout << "D::D(int a)\n"; }
	D(int a, int b) : C(a,b) { std::cout << "D::D(int a, int b)\n"; }
	D(const D& other) : C(other) { std::cout << "D::D(const D& other)\n"; }
	D(D&& other) : C(std::move(other)) { std::cout << "D::D(D&& other)\n"; }
	void operator=(const D& other) { C::operator=(other); std::cout << "operator=(const D& other)\n"; }

};
void CDTest4InheritanceConstructor() {

	C object0;
	C object1(1);
	D object2(4, 4);
	D object3(5);
	D object4;

	object4 = object2;
	
	D object5(std::move(object2));
	D object6(object3);

	C object7(object3);
	object0 = object1;


}
void Test4InheritanceConstructor() {

	MathArray myMathArray(5);
	for (size_t i = 0; i < myMathArray.Size(); i++) {
		myMathArray[i] += i + 1;
		std::cout << myMathArray[i] << " ";
	}
	int sum = myMathArray.Sum();
	std::cout << std::endl;
	std::cout << sum;
}
#pragma endregion

int main() 
{
	CDTest4InheritanceConstructor();
	return 0;
}