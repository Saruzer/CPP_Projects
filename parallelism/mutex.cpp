#include<iostream>
#include<thread>
#include<mutex>
#include<chrono>
#include<vector>

#pragma region std::mutex

std::mutex mutex;

void PrintNumbers1(int count) 
{
	mutex.lock();
	for (int number = 0; number <= count; number++)
	{
		std::cout << number << std::endl;
	}
	mutex.unlock();
}
void PrintNumbers2(int count)
{
	if (mutex.try_lock())
	{
		for (int number = 0; number <= count; number++)
		{
			std::cout << number << std::endl;
		}
		mutex.unlock();
	}
	else
	{
		std::cout << "Mutex is already locked\n";
	}

}


void MutexExample() 
{
	std::thread thread1(PrintNumbers2, 50);
	std::thread thread2(PrintNumbers2, 50);

	thread1.join();
	thread2.join();
}
#pragma endregion
#pragma region std::recursive_mutex
std::recursive_mutex recursiveMutex;

void PrintNumbers3(int count)
{
	recursiveMutex.lock();
	if(count > 0)
	{
		PrintNumbers3(count - 1);
	}
	recursiveMutex.unlock();
}
void RecursiveMutexExample()
{
	std::thread thread1(PrintNumbers3, 50);
	std::thread thread2(PrintNumbers3, 50);
		
	thread1.join();
	thread2.join();
}
#pragma endregion


int main()
{
	RecursiveMutexExample();
	return 0;
}
