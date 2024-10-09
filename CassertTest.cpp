#include <iostream>
#include <cassert>


int main()
{
	short num;
	std::cout << "Enter number bigger than 10: ";
	std::cin >> num;

	if (num >= 10) {
		assert(false);
	}
	else
		_wassert(_CRT_WIDE("Your PC gonna blow up! GG"), _CRT_WIDE("NO FILE BRO YOUR PC DIED"), (unsigned)(666));
}
