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
		std::cout << count << std::endl;
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
#pragma region std::timed_mutex

std::timed_mutex timedMutex;

void UseResource(int threadindex)
{
	auto timeOut = std::chrono::seconds(2);
	bool isLockedAcquired = false;
	auto startTime = std::chrono::high_resolution_clock::now();

	while(!isLockedAcquired)
	{
		isLockedAcquired = timedMutex.try_lock_until(startTime + timeOut);
		if(isLockedAcquired)
		{
			std::cout << "Resource used by thread #" << threadindex << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(5));
			timedMutex.unlock();
		}
		else
		{
			std::cout << "Thread # " << threadindex << " is waiting..." << std::endl;
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
		}
	}
}
void TimedMutexExample()
{
	std::thread thread1(UseResource, 1);
	std::thread thread2(UseResource, 2);
	std::thread thread3(UseResource, 3);
	std::thread thread4(UseResource, 4);

	thread1.join();
	thread2.join();
	thread3.join();
	thread4.join();
}
#pragma endregion
#pragma region std::locked_guard
std::mutex mutex2;

void PrintNumbers5(int count)
{
	std::lock_guard<std::mutex> guard(mutex2);

	for (int number = 0; number <= count; number++)
	{
		std::cout << number << std::endl;
	}
}

void MutexExample()
{
	std::thread thread1(PrintNumbers5, 50);
	std::thread thread2(PrintNumbers5, 50);

	thread1.join();
	thread2.join();
}

#pragma endregion


int main()
{
	TimedMutexExample();
	return 0;
}
