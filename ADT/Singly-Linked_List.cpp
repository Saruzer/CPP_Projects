#include<iostream>
#include"List.h"

int main() {
	List<int> list1;

	for (size_t i = 0; i < 10; i++)
	{
		list1.PushBack(i);
	}

	for(List<int>::Iterator it = list1.Begin(); it != list1.End();++it)
	{
		*it += 50;
		std::cout << *it << " ";
	}
	return 0;

}