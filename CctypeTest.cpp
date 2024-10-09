#include <iostream>
#include <cctype>

union textInfo {
	int letterCounter;
	int lowLetterCounter;
	int upLetterCounter;
	int numCounter;
};
int main()
{
	char* text = new char[36] { "V3ry 10ng t3xt..)) just an Ex@mple!" };
	const int SIZE = std::strlen(text);

	std::cout << "Text template: " << text << std::endl;
	std::cout << "-------------------" << std::endl;

	for (int i = 0; i < SIZE; i++)
		std::cout << (char)tolower(text[i]);

	std::cout << std::endl;

	for (int i = 0; i < SIZE; i++)
		std::cout << (char)toupper(text[i]);

	std::cout << std::endl;
	textInfo counter{};
	std::cout << "-------------------" << std::endl;
	for (int i = 0; i < SIZE; i++)
		if (isalpha(text[i]))
			counter.letterCounter++;

	std::cout << "Letters in text: " << counter.letterCounter << std::endl;
	counter.letterCounter = 0;
	for (int i = 0; i < SIZE; i++)
		if (islower(text[i]))
			counter.lowLetterCounter++;

	std::cout << "Lowercase letters in text: " << counter.lowLetterCounter << std::endl;
	counter.letterCounter = 0;
	for (int i = 0; i < SIZE; i++)
		if (isupper(text[i]))
			counter.upLetterCounter++;

	std::cout << "Uppercase letters in text: " << counter.upLetterCounter << std::endl;
	counter.letterCounter = 0;

	for (int i = 0; i < SIZE; i++)
		if (isdigit(text[i]))
			counter.numCounter++;

	std::cout << "Numbers in text: " << counter.numCounter << std::endl;

	std::cout << "-------------------\n";

}
