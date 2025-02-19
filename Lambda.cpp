#include<iostream>
template<typename T, typename Func>
void DoForAllElements(T arr[], size_t size, Func function)
{
	for (size_t i = 0; i < size; i++)
	{
		function(arr[i]);
	}
}


int main()
{
	int a = 10;
	int b = 20;
	int sum = [](int a, int b) { return a + b; } (a,b);
	std::cout << "sum: " << sum << std::endl;
	
	const size_t SIZE1 = 2;
	int arr1[SIZE1] = { 1,2 };

	const size_t SIZE2 = 5;
	double arr2[SIZE2] = { 1.2,2.7,3.67, 5.12,1.0 };

	const size_t SIZE3 = 3;
	char arr3[SIZE3] = { 'A','D','L'};

	auto show = [](auto T) {std::cout << T << " "; };

	DoForAllElements(arr1, SIZE1, show);
	std::cout << std::endl;
	DoForAllElements(arr2, SIZE2, show);
	std::cout << std::endl;
	DoForAllElements(arr3,SIZE3,show);
	std::cout << std::endl;

	auto Powa = [a]() mutable { a *= a; std::cout << a << std::endl; };
	Powa();
}	