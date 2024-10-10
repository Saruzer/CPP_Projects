#include <iostream>
#include <cstring>


int main()
{
#pragma region strcpy_s
	{
		char str1[] = "Some random text!";
		const size_t SIZE = 50;
		char str2[SIZE];
		std::cout << "------strcpy_s------" << std::endl;
		std::cout << str1 << std::endl;
		strcpy_s(str2, SIZE, str1);
		std::cout << str2 << std::endl;
	}
#pragma endregion
#pragma region strncpy_s
	{
		char str1[] = "Em, actually, i thought about my very big...";
		const size_t SIZE = 50;
		char str2[SIZE];
		std::cout << "------strncpy_s------" << std::endl;
		std::cout << str1 << std::endl;
		strncpy_s(str2, SIZE, str1, 23);
		std::cout << str2 << std::endl;
	}
#pragma endregion
#pragma region strcat_s
	{
		const size_t SIZE = 50;
		char str1[SIZE] = "I am so s";
		char str2[SIZE];
		std::cout << "------strcat_s------" << std::endl;
		std::cout << str1 << std::endl;
		strcpy_s(str2, SIZE, str1);
		strcat_s(str1, SIZE, "tupid");
		std::cout << str1 << std::endl;
		strcat_s(str2, SIZE, "mart");
		std::cout << str2 << std::endl;

	}
#pragma endregion
#pragma region strncat_s
	{
		const size_t SIZE = 50;
		char str1[SIZE] = "What a beautiful day outside. ";
		std::cout << "------strncat_s------" << std::endl;
		std::cout << str1 << std::endl;
		strncat_s<SIZE>(str1, "Birds are sining", 10);
		std::cout << str1 << std::endl;

	}
#pragma endregion
#pragma region strlen
	{
		const size_t SIZE = 50;
		char str1[SIZE] = "YOU NEVER CAN FOUND MY LENGTH >:) ";
		std::cout << "------strlen------" << std::endl;
		std::cout << str1 << std::endl;
		std::cout << "len of str: " << strlen(str1) << std::endl;

	}
#pragma endregion
#pragma region strcmp
	{
		char str1[] = "abc";
		char str2[] = "def";
		char str3[] = "abd";
		std::cout << "------strcmp------" << std::endl;
		if (!strcmp(str1, str2))
			std::cout << str1 << " == " << str2 << std::endl;
		else
			std::cout << str1 << " != " << str2 << std::endl;

		if (!strcmp(str2, str3))
			std::cout << str2 << " == " << str3 << std::endl;
		else
			std::cout << str2 << " != " << str3 << std::endl;

		if (!strcmp(str1, str3))
			std::cout << str1 << " == " << str3 << std::endl;
		else
			std::cout << str1 << " != " << str3 << std::endl;
		int compResult = strcmp(str1, str3);
		if (compResult < 0)
			std::cout << str1 << " < " << str3 << std::endl;
	}
#pragma endregion
#pragma region strncmp
	{
		char fullname1[] = "Some Name";
		char fullname2[] = "Some surname";

		size_t nameLength = strlen("Some");

		std::cout << "------strncmp------" << std::endl;
		if (!strncmp(fullname1, fullname2, nameLength))
			std::cout << fullname1 << " and " << fullname2 << " have the same name." << std::endl;
	}
#pragma endregion
#pragma region strrchr
	{
		char str[] = "Who am i? WHO AM I?";


		std::cout << "------strrchr------" << std::endl;
		std::cout << str << std::endl;
		char* foundPlace = strrchr(str, '?');
		if (foundPlace != nullptr) {
			size_t idx = foundPlace - str;

			std::cout << "The last character '?' has " << idx << " index" << std::endl;
		}
	}
#pragma endregion
#pragma region strspn
	{
		char digits[] = "0123456789";
		char str[] = "11123 I am about to call 666";

		std::cout << "------strspn------" << std::endl;

		std::cout << str << std::endl;
		size_t foundDigitsCount = strspn(str, digits);
		std::cout << "str starts with " << foundDigitsCount << " digits" << std::endl;
	}
#pragma endregion
#pragma region strcspn
	{
		char digits[] = "0123456789";
		char str[] = "I am about to call 666";

		std::cout << "------strcspn------" << std::endl;

		std::cout << str << std::endl;
		size_t foundDigitsCount = std::strcspn(str, digits);
		std::cout << "str digits starts with index: " << foundDigitsCount << std::endl;
	}
#pragma endregion
}
