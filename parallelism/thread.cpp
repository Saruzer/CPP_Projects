#include<iostream>
#include<thread>
#include<chrono>
#include<ctime>
#include<vector>

void ChronoExample1()
{
	auto now = std::chrono::system_clock::now();
	char* const mytime = new char[40];
	std::time_t current_time = std::chrono::system_clock::to_time_t(now);
	std::cout << "Current time(unformatted) = " << current_time << std::endl;
	ctime_s(mytime, sizeof(char) * 40, &current_time);
	std::cout << "Current time(formatted) = " << mytime << std::endl;
}
void ChronoExample2()
{
	auto start = std::chrono::system_clock::now();
	for (size_t i = 0; i < 1000000; i++) {}
	auto end = std::chrono::system_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::cout << "work time: " << duration.count() << std::endl;
}

void ShowMessageHello()
{
	std::cout << "Thread #2 has start\n";
	std::string hello = "hello";
	for (size_t i = 0; i < 5; i++)
	{
		std::cout << hello[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Thread #2 has ended\n";
}
void LongProcess()
{
	for (size_t i = 0; i < 100'000'000; i++)
	{
		i = i + 1 - 1;
		std::cout << i << " ";
	}
}
void ShowMessage(int threadIndex)
{
	std::cout << "Thread: " << threadIndex << " is running\n";
}
void ChangeName(std::string& name)
{
	name = "NoName";
}
void ThreadExample1()
{
	std::cout << "Thread #1 has start\n";

	std::thread someThread;
	for (size_t i = 0; i < 1000; i++)
	{

	}
	someThread = std::thread(ShowMessageHello);

	for (size_t number = 0; number < 20; number++)
	{
		std::cout << number << " ";
	}
	std::cout << std::endl;

	someThread.join();

	std::cout << "Thread #1 has ended\n";
}
void ThreadExample2()
{
	std::cout << "Main thread has start\n";

	const int THREADS_COUNT= 5;
	std::vector<std::thread> threads(THREADS_COUNT);

	for (size_t ThreadIndex = 0; ThreadIndex < THREADS_COUNT; ThreadIndex++)
	{
		threads[ThreadIndex] = std::thread(ShowMessage, ThreadIndex);
	}
	for(std::thread& thread : threads)
	{
		thread.join();
	}
	std::cout << "Main thread has ended\n";
}
void ThreadExample3()
{
	
	std::string name;
	std::thread thread(ChangeName,std::ref(name));

	thread.join();

	std::cout << "Name: [ " << name << " ]\n";
	
}
int main()
{
	ThreadExample3();
}