#include<iostream>
#include<vector>
int main()
{
	std::vector<int> vector{ 10,20,500,5,0 };

	std::cout << "vector[0] = " << vector[0] << std::endl;
	vector.front() = 100;
	std::cout << "vector[0] = " << vector[0] << std::endl;

	std::cout << "vector[4] = " << vector[4] << std::endl;
	vector.back() = 99999;
	std::cout << "vector[4] = " << vector[4] << std::endl;

	int* ptr = vector.data();
	std::cout << "vector[2] = " << vector[2] << std::endl;
	ptr[2] = -5;
	std::cout << "vector[2] = " << vector[2] << std::endl;

	vector[3] = 154;
	std::cout << "vector[3] = " << vector[3] << std::endl;
	std::cout << "-------------" << std::endl;
	vector.insert(vector.cbegin() + 4,200);
	vector.erase(vector.cbegin(), vector.cbegin() + 3);
	for(auto num : vector)
	{
		std::cout << num << " ";
	}
	std::cout << std::endl;

	return 0;
}