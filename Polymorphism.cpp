#include<iostream>
#pragma region 1. Parametic Polymorphism
template<typename T>
void ShowArr(const T arr[], size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << "arr[" << i << "]: " << arr[i] << " ";
	}
	std::cout << std::endl;
}
void Test1ParameticPolymorphism()
{
	int arr1[] = { 1,2,3 };
	double arr2[] = { 1.1,2.2,3.3 };
	char arr3[] = { 'A','B','C'};
	ShowArr(arr1,3);
	ShowArr(arr2,3);
	ShowArr(arr3,3);
}

#pragma endregion
#pragma region 2. Ad-hoc Polymorphism
void Show(int number) {
	std::cout << number << std::endl;
}
void Show(const char* str) {
	size_t size = std::strlen(str);

	for (size_t i = 0; i < size; i++)
	{
		std::cout << str[i] << " ";
	}
	std::cout << std::endl;
}
void Test2Ad_hocPolymorphism()
{
	int number = 10;
	char str[] = "Hello world!";
	Show(10);
	Show(str);
}
#pragma endregion
#pragma region 3. Subtyping Polymorphism
class Human {
private:
	int age;
	char* name;
public:
	virtual ~Human() { std::cout << "Human Destructor: " << name << "\n"; };
	Human() : age(0) { strcpy_s(this->name,7,"NoName"); std::cout << "Human Constructor" << name << "\n"; };
	Human(int age, const char* name) : age(age > 0 ? age : 1)
	{
		if (name != nullptr) {
			size_t lenght = strlen(name);
			this->name = new char[lenght + 1];
			strcpy_s(this->name,lenght + 1,name);
		}
		else
		{
			this->name = new char[7];
			strcpy_s(this->name,7,"NoName");
		}
		std::cout << "Human Constructor: " << name << "\n";
	}
	virtual void ShowInfo() {
		std::cout << "Human info: \n";
		std::cout << "Age: " << this->age << std::endl;
		std::cout << "Name: " << this->name << std::endl;
	}
	const char* GetName() { return name; };
};
class Worker : public Human
{
private:
	int salary;
	int workHours;
public:
	Worker(int age, const char* name, int salary, int workHours) : Human(age,name)
		, workHours(workHours >= 0 ? workHours : 0), salary(salary) 
	{
		std::cout << "Worker Constructor: " << name << "\n";
	}
	virtual void ShowInfo() override 
	{
		Human::ShowInfo();
		std::cout << "Worker info: \n";
		std::cout << "Salary: " << this->salary << std::endl;
		std::cout << "Work hours: " << this->workHours << std::endl;
	}
	virtual ~Worker() override {
		std::cout << "Worker Destructor: " << GetName() << "\n";
	}
};
class Bigboss : public Human {
private:
	Human** slaves;
	int numberOfSlaves;
public:
	Bigboss(int age, const char* name, Human** slaves, int numberOfSlaves) : Human(age, name), numberOfSlaves(numberOfSlaves >= 0 ? numberOfSlaves : 0)
	{
		this->slaves = slaves;
		std::cout << "Bigboss Constructor: " << name << "\n";

	}
	virtual ~Bigboss() override {
		
		std::cout << "Bigboss Destructor: " << GetName() << "\n";
		for (size_t i = 0; i < numberOfSlaves; i++)
		{
			delete[] *(slaves + i);
			*(slaves + i) = nullptr;

		}
		slaves = nullptr;
	}
	int GetSlaveNumber() { return numberOfSlaves; }
	virtual void ShowInfo() override
	{
		Human::ShowInfo();
		std::cout << "Bigboss info: \n";
		std::cout << "Slaves in order: " << this->numberOfSlaves << std::endl;
	}
	void ShowAllSlaveInfo() {
		for (size_t i = 0; i < numberOfSlaves; i++)
		{
			std::cout << "Slave name:" << slaves[i]->GetName() << std::endl;
		}
	}
};
void Test3SubtypingPolymorphism() {
	Human regular(20, "Regular human");

	Human* lox = new Human(30, "lox");
	Worker* oldMan = new Worker(56, "Grandmaster", 240, 9999);
	Worker* temuChild = new Worker(3, "Temu Child", 1, 500);
	Human* slaves[3] = { lox, oldMan, temuChild };
	{
		Bigboss BOSS(48, "Boss", slaves, 3);
		BOSS.ShowAllSlaveInfo();
	}
	std::cout << "\n\n";
}
#pragma endregion

int main() 
{
	Test3SubtypingPolymorphism();
	return 0xAAAAAAAl;
}