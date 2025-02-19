#include <iostream>
#include <cmath>

int main()
{
	const float PI = 3.14159265359;
	float sin = std::sinf(PI / 6);
	float cos = std::cosf(PI / 3);
	float tg = std::tanf(PI / 3);
	float ctg = powf(tg, -1);
	std::cout << "sin: " << sin << std::endl;
	std::cout << "cos: " << cos << std::endl;
	std::cout << "tg: " << tg << std::endl;
	std::cout << "ctg: " << ctg << std::endl;
}