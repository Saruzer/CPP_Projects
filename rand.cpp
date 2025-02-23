#include <iostream>
#include <chrono>
#include <random>
#include <algorithm>

int main()
{
	unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
	std::mt19937 generator(seed);
	std::uniform_int_distribution<int> intDistribution;
	std::uniform_real_distribution<double> doubleDistribution;

	int intRand = intDistribution(generator);
	double doubleRand = doubleDistribution(generator);
	
	std::cout << "int: " << intRand << std::endl;
	std::cout << "double: " << doubleRand << std::endl;

	return 0;
}