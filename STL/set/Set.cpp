#include<iostream>
#include<set>
#include<vector>

int main()
{
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	std::vector<int> numbers(100);
	for (size_t i = 0; i < numbers.size(); i++)
	{
		numbers[i] = rand() % 100;
	}
	std::set<int> uniqueNumber(numbers.cbegin(), numbers.cend());
	for (int number : uniqueNumber)
	{
		std::cout << number << " ";
	}
	std::cout << std::endl;

	return 0;
}
