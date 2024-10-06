#include <iostream>
#include "Sort.cpp"
#include "Misc.cpp"
bool IsAllNegative(int* arr, int size) {
	for (int i = 0; i < size; i++)
	{
		if (arr[i] != -1) {
			return false;
		}
	}
	return true;
}
int& RandElement(int* arr, int size)
{
	int idx = rand() % size;
	while (arr[idx] == -1 && !IsAllNegative(arr, size))
		idx = rand() % size;
	return arr[idx];
}
int main()
{
	srand(static_cast<unsigned int>(time(nullptr)));
	const int SIZE = 5;
	int arr[SIZE];
	Initialize(arr, SIZE);
	Show(arr, SIZE);
	RandElement(arr, SIZE) = -1;
	RandElement(arr, SIZE) = -1;
	RandElement(arr, SIZE) = -1;
	Show(arr, SIZE);

}

