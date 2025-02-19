#include<iostream>
template<typename T>
void Show(const T& param)
{
	std::cout << param << std::endl;
}
template<typename T, typename ... Args>
void Show(const T& param, const Args& ... args)
{
	std::cout << param << " ";
	Show(args...);
}

int main() 
{
	Show(1,2,"AGAGAHAHAH",'I',9999,-1);
	return 0;
}