#include <iostream>
#include "Sort.cpp"
#include "Misc.cpp"
template<typename T>
void ShowBinaryNumber(T number) {


	const int byte = 8; // byte = bit[8]

	size_t size = sizeof(number) * byte;
	std::cout << number << " = \t";
	for (size_t i = size; i >= 1; i--)
	{

		if (i % 4 == 0 && i % 8 != 0)
			std::cout << " ";
		if (i % 8 == 0)ןרו
			std::cout << " | ";
		if ((number & (static_cast<unsigned long long>(1) << i - 1)))
			std::cout << 1;
		else
			std::cout << 0;
	}
	std::cout << " | " << std::endl;
}
int main()
{
	char a = 10; // 1010
	short c = 13; // 1101
	int b = 20; // 0001 0100
	unsigned long long d = 8593; //0010 0001 1001 0001
	ShowBinaryNumber(a);
	ShowBinaryNumber(b);
	ShowBinaryNumber(c);
	ShowBinaryNumber(d);
}
