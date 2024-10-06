#include <iostream>
template<typename T>
void QuickSort(T arr[], int first, int last)
{
	T middle = arr[(first + last) / 2];
	int i = first;
	int j = last;
	do
	{
		while (arr[i] < middle)
			i++;
		while (arr[j] > middle)
			j--;
		if (i <= j)
		{
			std::swap(arr[i], arr[j]);
			i++;
			j--;
		}
	} while (i <= j);
	if (i < last)
		QuickSort(arr, i, last);
	if (j > first)
		QuickSort(arr, first, j);
}
template<typename T>
void SelectionSort(T arr[], const int SIZE)
{
	for (int i = 0; i < SIZE - 1; i++)
	{
		for (int j = i + 1; j < SIZE; j++)
		{
			if (arr[i] > arr[j]) {
				std::swap(arr[i], arr[j]);
			}
		}
	}
}
template<typename T>
void BubbleSort(T arr[], int SIZE) {
	for (int i = 0; i < SIZE - 1; i++)
	{
		for (int j = SIZE - 1; j > i; j--)
		{
			if (arr[j] < arr[j - 1]) {
				std::swap(arr[j], arr[j - 1]);
			}
		}
	}
}
template<typename T>
void InsertionSort(T arr[], int SIZE) {
	for (int i = 1; i < SIZE; i++)
	{
		int key = arr[i];

		int j;
		for (j = i - 1; j >= 0 && arr[j] > key; j--)
			arr[j + 1] = arr[j];

		arr[j + 1] = key;
	}
}