#include <ctime>
#include <iostream>
static void Initialize(int arr[], const int size)
{
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 10;
	}
}
static void Initialize(double arr[], const int size, int digits)
{
	double division;
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 10;
		division = 10;
		for (int j = 0; j < digits; j++)
		{
			arr[i] += (rand() % 10) / division;
			division *= 10;
		}
	}

}
template<typename T>
void Show(T arr[], const int SIZE)
{
	for (int i = 0; i < SIZE; i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
template<typename T>
bool BinarySearch(const T arr[], int size, T key)
{
	int leftBound = 0, rightBound = size - 1;
	do
	{
		T middle = (leftBound + rightBound) / 2;

		if (key < arr[middle])
			rightBound = middle - 1;
		else if (key > arr[middle])
			leftBound = middle + 1;
		else
			return true;
	} while (leftBound <= rightBound);
	return false;

}