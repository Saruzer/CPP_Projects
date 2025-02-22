#include<iostream>
#include<map>
#include<vector>

int main()
{
	std::vector<std::pair<int, std::string>> vec
	{ 
		{1, "Hello World!"}, 
		{3, "Goofy ahhh text"},
		{6, "Goodbye world!"}
	};

	std::map<int, std::string> myMap(vec.cbegin(), vec.cend());

	myMap[4] = "aaaaaaaaaaaaa";
	for(auto iter = myMap.cbegin(); iter != myMap.cend();++iter)
	{
		std::cout << iter->first << ": " << iter->second << std::endl;
	}
	return 0;
}
