#include <iostream>
#include "Sort.cpp"
#include "Misc.cpp"
#include <Windows.h>
int Sum(int a, int b)
{
	return a + b;
}
int Multiply(int a, int b)
{
	return a * b;
}
int Subtract(int a, int b)
{
	return a - b;
}
int MathOperations(int a, int b, int (*CurrentOperation)(int, int))
{
	return CurrentOperation(a, b);
}

int main()
{
	SetConsoleOutputCP(1251);

	int a = 5;
	double ad = 5.5;
	int b = 10;

	int* p = &a;

	const int f = 100;

	const int* cp;
	cp = &f;
	//*cp = 1;
	cp = &b;

	const int c = 24;
	const int* const ccp = &c;
	//*ccp = 1;
	//ccp = &b;
	int** pp = &p;

	int arr[3]{ 1,2,3 };

	int* ap = arr;
	int* nullp = nullptr;

	void* v;
	v = &a;
	std::cout << R"(-----Підключаємо потрібні дериктиви------
#include <iostream>
#include "Sort.cpp"
#include "Misc.cpp"

-----Функція суми чисел------

int Sum(int a, int b)
{
	return a + b;
}

-----Функція множення чисел------

int Multiply(int a, int b)
{
	return a * b;
}

-----Функція віднімання чисел------

int Subtract(int a, int b)
{
	return a - b;
}

-----Функція мат. операцій, в аргументи передаємо вказіник на одну з функцій для операцій над числами------

int MathOperations(int a, int b, int (*CurrentOperation)(int,int)) 
{
	return CurrentOperation(a, b);
}

-----Початок програми------

int main()
{
	int a = 5; ---- Ініціалізуємо int змінну а
	double ad = 5.5; ---- Ініціалізуємо double змінну  ad 
	int b = 10; ---- Ініціалізуємо int змінну b

	int* p = &a; ---- Створюємо в оперативній пам'яті вказівник p на адресу змінної а

	const int f = 100;

	const int* cp; ---- Створюємо вказівник на константу cp
	cp = &f; ---- Присвоюємо адресу змінної f до вказівника на константу cp
	!----! *f = 1; ! - цей код буде неможливий, оскільки у нас вказівник на константу  
	cp = &a; ---- Можемо змінювати адресу яку зберігає в собі вказівник, наівть на не константну змінну.

	[ТОБТО ВКАЗІВНИК НА КОНСТАНТУ НЕ ДОЗВОЛЯЄ НАМ ЗМІНЮВАТИ ЗНАЧЕННЯ ЗМІННОЇ, НА ЯКУ ПОСИЛАЄТЬСЯ ВКАЗІВНИК]
	[АЛЕ МОЖНА ВІЛЬНО ЗМІНЮВАТИ АДРЕС, НА ЯКИЙ ПОСИЛАЄТЬСЯ ВКАЗВІВНИК]

	const int c = 24; ---- Створємо константу змінну c

	const int* const ccp = &c; -- створюємо константний вказівник на константу ccp.

	[ОСКІЛЬКИ ВКАЗІВНИК НА КОНСТАНТУ ТУТ Є ЩЕ Й КОНСТАНТНОЮ, ТО ТРЕБА ЗАДАТИ ЗНАЧЕННЯ НА ЕТАПІ КОМПІЛЯЦІЇ] 

		{ Цей блок коду не спрацює, оскільки вказівник на константу є константним
		*ccp = 1; ---- Ми не можемо присвоїти значення, оскільки це вказівник на константу
		ccp = &b; ---- Ми не можемо змінити адресу, яку зберігає в собі вказівник, оскільки вказівник є константним
		}

	int** pp = &p; ---- Створюємо вказівник pp на вказівник p

	int arr[3]{ 1,2,3 }; ---- Створюємо масив arr з 3 значень: 1,2,3

	int *ap = arr; ---- Створюємо вказівник ap, який буде посилатися на arr. знак & для arr не потрібен, оскільки фактично масив є вказівником 
	int* nullp = nullptr; ---- Створюємо вказівник nullp, який не буде посилатися ні на яку адресу

	void* v; ---- Створюємо void вказівник v
	v = &a; ---- Можемо присвоїти адресу int змінної а, та потім вивести її  

	std::cout << "void* for int = " << *(static_cast<int*>(v)) << std::endl;
	output: void* for int = 5

	v = &ad; ---- Можемо присвоїти адресу double змінної ad, та потім вивести її  

	std::cout << "void* for double = " << *(static_cast<double*>(v)) << std::endl;
	output: void* for double = 5.5
	
	std::cout << *(ap) << " " << *(ap + 1) << " " << *(ap + 2) << std::endl; ---- Виводимо на екран числа масива завдяки арифметики вказівників
	output: 1 2 3

	----Проводимо математичні операції з числами----

	(Тут ми робимо всякі математичні операції з числами.)
	(Використовуючи MathOperations(int a, int b, (*CurrentOperation)(int,int)) 
	- ми в аргументи закидуємо значення, над якими будуть проводитися дії, та сам аргумнт адресу функції, 
	що буде виконувати дії над числами))

	std::cout << a << " + " << b << " = " << MathOperations(a, b, Sum) << std::endl;
	output: 5 + 10 = 15
	
	std::cout << a << " - " << b << " = " << MathOperations(a, b, Subtract) << std::endl;
	output: 5 - 10 = -5

	std::cout << a << " * " << b << " = " << MathOperations(a, b, Multiply) << std::endl;
	output: 5 * 10 = 50
}
)";
	/*std::cout << "void* for int = " << *(static_cast<int*>(v)) << std::endl;
	v = &ad;
	std::cout << "void* for double = " << *(static_cast<double*>(v)) << std::endl;
	std::cout << *(ap) << " " << *(ap + 1) << " " << *(ap + 2) << std::endl;
	std::cout << a << " + " << b << " = " << MathOperations(a, b, Sum) << std::endl;
	std::cout << a << " - " << b << " = " << MathOperations(a, b, Subtract) << std::endl;
	std::cout << a << " * " << b << " = " << MathOperations(a, b, Multiply) << std::endl;*/



}
