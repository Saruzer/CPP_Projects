#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<numeric>
#include<random>
#include<algorithm>

template<typename Container>
void Show(const Container& container)
{
	for(typename Container::value_type element : container)
	{
		std::cout << element << " ";
	}
	std::cout << std::endl;
}
void all_of()
{
	std::cout << "\n----- " << __func__ << " -----\n\n";
	std::vector<int> number = { 10,2,9,3,5,6 };

	bool isEveryNumberGreaterThan5 = std::all_of(number.begin(), number.end(), [](int value) {return value > 5; });
	if(isEveryNumberGreaterThan5 == true)
		std::cout << "Every value in container greater then 5\n";
	else
		std::cout << "Container has values equal or greater than 5\n";
}
void for_each()
{
	std::cout << "\n----- " << __func__ << " -----\n\n";

	std::vector<int> number = { 10,2,9,3,5,6 };

	auto showFunction = [](int value) {std::cout << value << " "; };
	std::for_each(number.begin(), number.end(), showFunction);
	std::cout << std::endl;
}
void count()
{
	std::cout << "\n----- " << __func__ << " -----\n\n";

	std::vector<int> number = { 10,2,9,3,5,6 };

	size_t countOf3 = std::count(number.begin(), number.end(), 3);
	std::cout << "Container has" << countOf3 << "values that equal 3.\n";
}
void count_if()
{
	std::cout << "\n----- " << __func__ << " -----\n\n";

	std::vector<int> number = { 10,2,9,3,5,6 };

	auto predicate_IsEven = [](int value) {return value % 2 == 0; };
	size_t evenNumberCount = std::count_if(number.begin(), number.end(), predicate_IsEven);
	std::cout << "Container has" << evenNumberCount << "values that equal 3.\n";
}
void mismatch()
{
	std::cout << "\n----- " << __func__ << " -----\n\n";

	std::vector<int> container1 = { 10,2,9,3,5,6 };
	std::vector<int> container2 = { 10,2,9,3,5,6 };

	auto mismatchIters = std::mismatch(container1.begin(), container1.end(), container2.begin(), container2.begin());
	if (mismatchIters.first != container1.end())
	{
		std::cout << "Mismatch value in first container: " << *mismatchIters.first << std::endl;
	}
	else if (mismatchIters.second != container2.end())
	{
		std::cout << "Mismatch value in second container: " << *mismatchIters.second << std::endl;
	}
	else
	{
		std::cout << "Containers are same\n";
	}
}
void find()
{
	std::cout << "\n----- " << __func__ << " -----\n\n";

	std::vector<int> c = { 10,2,9,3,5,2 };
	auto first = std::find(c.begin(), c.end(), 2);
	auto last = std::find(first + 1, c.end(), 2);

	if(last != c.end())
	{
		++last;
	}
	for (; first != last; ++first)
		*first *= 3;

	auto ShowFunction = [](int value) {std::cout << value << " "; };
	std::for_each(c.begin(), c.end(), ShowFunction);
	std::cout << std::endl;
}
void find_if()
{
	std::cout << "\n----- " << __func__ << " -----\n\n";
	std::vector<int> c = { 10,2,9,3,5,2 };
	auto predicate_IsNegative = [](int value) {return value < 0; };

	auto negativeValueIter = std::find_if(c.begin(), c.end(), predicate_IsNegative);
	

	if (negativeValueIter != c.end())
	{
		*negativeValueIter = std::abs(*negativeValueIter);
	}

	auto ShowFunction = [](int value) {std::cout << value << " "; };
	std::for_each(c.begin(), c.end(), ShowFunction);
	std::cout << std::endl;
}
void search()
{
	std::cout << "\n----- " << __func__ << " -----\n\n";
	std::vector<int> c1 = { 10,2,9,3,5,2 };
	std::vector<int> c2 = { 2,9,3 };

	auto foundIter = std::search(c1.begin(), c1.end(), c2.begin(), c2.end());
	if(foundIter != c1.end())
	{
		std::cout << "Container1 has all values from container2\n";
	}

}
void copy()
{
	std::cout << "\n----- " << __func__ << " -----\n\n";
	std::vector<int> c1 = { 1,2,3,4,5 };
	std::vector<int> c2 = { 100,200,300,400,500,600};

	std::copy(c1.begin() + 1, c1.end() - 1, c2.begin() + 2);

	Show(c1);
	Show(c2);
}
void move()
{
	std::cout << "\n----- " << __func__ << " -----\n\n";
	std::vector<int> c1 = { 43,55,12};
	std::vector<int> c2 = { 100,200,300,400,500,600 };

	std::move(c1.begin(), c1.end(), c2.begin());

	Show(c1);
	Show(c2);
}
void fill()
{
	std::cout << "\n----- " << __func__ << " -----\n\n";
	std::vector<int> c1 = {1,2,3,4,4,5,56}; 

	std::fill(c1.begin(), c1.end(), 1000);

	Show(c1);
}
void transform()
{
	std::cout << "\n----- " << __func__ << " -----\n\n";
	std::string str = "hello";

	std::cout << "str = " << str << std::endl;
	std::transform(str.begin(), str.end(), str.begin(), [](unsigned char c) { return std::toupper(c); });
	std::cout << "str = " << str << std::endl;
}
void generate()
{
	std::cout << "\n----- " << __func__ << " -----\n\n";
	std::vector<int> c1(10);
	std::generate(c1.begin(), c1.end(), std::rand);
	Show(c1);
}
void remove()
{
	std::cout << "\n----- " << __func__ << " -----\n\n";
	std::vector<int> c1 = { 1,2,3,2,4,2,5 };

	auto removingSequenceFirstIter = std::remove(c1.begin(), c1.end(), 2);
	c1.erase(removingSequenceFirstIter, c1.end());

	Show(c1);
}
void swap()
{
	std::cout << "\n----- " << __func__ << " -----\n\n";
	std::vector<int> c1 = { 43,55,12 };
	std::vector<int> c2 = { 100,200,300,400,500,600 };

	Show(c1);
	Show(c2);
	std::swap(c1, c2);
	Show(c1);
	Show(c2);

}
void reverse()
{
	std::cout << "\n----- " << __func__ << " -----\n\n";
	std::vector<int> c1 = { 1,2,3,4,5,6,7 };
	
	Show(c1);

	std::reverse(c1.begin(),c1.end());
	
	Show(c1);
}
void rotate()
{
	std::cout << "\n----- " << __func__ << " -----\n\n";
	std::vector<int> c1 = { 1,2,3,4,5,6,7 };

	Show(c1);

	std::rotate(c1.begin(), c1.begin() + 4,c1.end());

	Show(c1);
}
void unique()
{
	std::cout << "\n----- " << __func__ << " -----\n\n";
	std::vector<int> c1 = { 1,1,2,3,4,2,5,6,5,7 };

	Show(c1);

	auto last = std::unique(c1.begin(), c1.end());
	Show(c1);
	c1.erase(last, c1.end());
	std::sort(c1.begin(),c1.end());
	last = std::unique(c1.begin(), c1.end());
	c1.erase(last, c1.end());
	Show(c1);

}
void sort()
{
	std::cout << "\n----- " << __func__ << " -----\n\n";
	std::vector<int> c1 = { 4,5,7,2,4,78,1,0};

	Show(c1);

	std::sort(c1.begin(), c1.end());

	Show(c1);
}
void binary_search()
{
	std::cout << "\n----- " << __func__ << " -----\n\n";
	std::vector<int> c1 = { 1,2,3,4,5,6,7 };
	std::vector<int> c2 = { 1,2,3,41,45,645,876,1244 };

	for (int num : c1)
	{
		std::cout << "Searching for " << num << "\n";
		if (std::binary_search(c2.begin(), c2.end(), num))
			std::cout << "Found" << num << std::endl;
		else
			std::cout << "Not found\n";

	}
}
int main()
{
	all_of();
	for_each();
	count();
	count_if();
	mismatch();
	find();
	find_if();
	search();
	copy();
	move();
	fill();
	transform();
	generate();
	remove();
	swap();
	reverse();
	rotate();
	unique();
	sort();
	binary_search();
	return 0;
}