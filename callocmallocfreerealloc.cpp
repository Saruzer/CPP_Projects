#include<iostream>
void malloc()
{
	int* variable = static_cast<int*>(std::malloc(sizeof(int)));
	if (variable == nullptr) {
		throw std::bad_alloc();
	}
	*variable = 10;
	std::cout << *variable << std::endl;

	const size_t SIZE = 5;
	int* arr = static_cast<int*>(std::malloc(sizeof(int) * SIZE));
	if(arr == nullptr)
	{
		throw std::bad_alloc();
	}
	for(size_t i = 0; i < SIZE;i++)
	{
		arr[i] = i;
		std::cout << arr[i] << " ";
	}
}
void calloc()
{
	const size_t SIZE = 5;
	int* arr = static_cast<int*>(std::calloc(SIZE, sizeof(int)));
	if (arr == nullptr)
	{
		throw std::bad_alloc();
	}
	for (size_t i = 0; i < SIZE; i++)
	{
		arr[i] = i;
		std::cout << arr[i] << " ";
	}

}
void realloc()
{
	size_t oldSize = 5;
	int* arr = static_cast<int*>(std::calloc(oldSize, sizeof(int)));
	for (size_t i = 0; i < oldSize; i++)
	{
		arr[i] = i;
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	size_t newSize = 10;
	int* newarr = static_cast<int*>(std::realloc(arr, newSize * sizeof(int)));
	for (size_t i = oldSize; i < newSize; i++)
	{
		newarr[i] = 0;
	}
	for (size_t i = 0; i < newSize; i++)
	{
		std::cout << newarr[i] << " ";
	}
}
int main()
{
	return 0;
}