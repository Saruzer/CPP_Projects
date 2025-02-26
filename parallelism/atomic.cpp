#include<iostream>
#include<queue>
#include<chrono>

#include<thread>
#include<atomic>
#include<mutex>

void AtomicObjects()
{
	std::atomic<int> variable1;
	std::atomic<char> variable2;

	std::atomic_int variable3;
	std::atomic_char variable4;

	std::atomic<int> variable5(10);
	std::atomic<char> variable6 = 'h';
}
void AtomicMethods()
{
	std::cout << "---- AtomicMethods ----\n\n";
	//load
	std::cout << "--- Load() ---\n";
	{
		std::atomic_int variable(10);
		std::cout << variable.load() << std::endl;
		std::cout << variable << std::endl;
	}
	std::cout << std::endl;

	//store
	std::cout << "--- Store() ---\n";
	{
		std::atomic_int variable(10);
		variable.store(20);
		std::cout << variable.load() << std::endl;
	}
	std::cout << std::endl;
	//exchange
	std::cout << "--- Exchange() ---\n";
	{
		std::atomic_int variable(10);
		int oldValue = variable.exchange(20);
		std::cout << oldValue << std::endl;
		std::cout << variable.load() << std::endl;
	}
	// compare_exchange
	{
		std::atomic<int> x{ 0 };
		std::cout << "--- compare_exchange_strong() ---\n";
		int expected = 0;
		bool successStrong = x.compare_exchange_strong(expected, 2);
		std::cout << successStrong << std::endl;
		std::cout << x << std::endl;

		std::cout << "--- compare_exchange_weak() ---\n";
		int expected2 = 2;
		bool successWeak = x.compare_exchange_weak(expected2, 2);
		std::cout << successWeak << std::endl;
		std::cout << x << std::endl;
	}
	//fetch
	{
		std::cout << "--- Fetch() ---\n";
		std::atomic<int> x{ 0 };
		x.fetch_add(30);
		x.fetch_add(40);
		std::cout << x << std::endl;
		x.fetch_add(40);
		std::cout << x << std::endl;
	}
}
std::atomic<unsigned int> processedBuildingCount = 0;

void ProcessBuildings(unsigned int count)
{
	for (unsigned int i = 0; i < count; i++)
	{
		processedBuildingCount++;
	}
}
void AtomicExample1()
{
	std::thread thread1(ProcessBuildings, 2000);
	std::thread thread2(ProcessBuildings, 7000);

	thread1.join();
	thread2.join();

	std::cout << "Count of processed buildings = " << processedBuildingCount << std::endl;
}

int main()
{
	AtomicMethods();
	AtomicExample1();
	return 0;
}