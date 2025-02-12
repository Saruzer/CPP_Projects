#include <iostream>
#include <assert.h>
struct MyException {

	char description[50];

	MyException(const char* description)
	{
		strcpy_s(this->description,50, description);
	}
};
template<typename T>
class List {

private:
	T* objects;
	size_t length;

public:
	List() : length(0), objects(nullptr) { std::cout << "Default constructor\n"; }
	T& Get(int idx) {
		try 
		{
			if (idx > length || idx < 0) {
				throw MyException("Wrong index value\n");
			}
		}
		catch (MyException ex) {
			std::cout << ex.description;
			assert(0);
		}
		return objects[idx];
	}
	void Clear() {
		delete[] objects;
		objects = nullptr;
		length = 0;
	}
	void Remove(int idx) {
		try
		{
			if (idx > length || idx < 0) {
				throw MyException("Wrong index value\n");
			}
		}
		catch (MyException ex) {

			std::cout << ex.description;
			assert(0);
		}

		T* temp = new T[length];
		for (size_t i = 0; i < length; i++)
		{
			temp[i] = objects[i];
		}

		delete[] objects;
		objects = new T[length - 1];
		int step = 0;
		for (size_t i = 0; i < length; i++)
		{
			if (i != idx) {
				objects[i - step] = temp[i];
			}
			else {
				step = 1;
			}
		}
		delete[] temp;
		--length;
	}
	void Add(T newObject) {
		T* temp = new T[length];
		for (size_t i = 0; i < length; i++)
		{
			temp[i] = objects[i];
		}
		delete[] objects;
		objects = new T[length + 1];
		for (size_t i = 0; i < length; i++)
		{
			objects[i] = temp[i];
		}
		objects[length] = newObject;
		++length;
	}
	void Show() {
		if (length == 0) {
			std::cout << "List is empty\n";
			return;
		}
		for (size_t i = 0; i < length; i++)
		{
			std::cout << objects[i] << " ";
		}
		std::cout << std::endl;
	}
	void AddAt(T newObject, int idx) {
		try
		{
			if (idx > length || idx < 0) {
				throw MyException("Wrong index value\n");
			}
		}
		catch (MyException ex) {

			std::cout << ex.description;
			assert(0);
		}

		T* temp = new T[length];
		for (size_t i = 0; i < length; i++)
		{
			temp[i] = objects[i];
		}

		delete[] objects;
		objects = new T[length + 1];
		int step = 0;
		for (size_t i = 0; i <= length; i++)
		{
			if (i == idx) 
			{
				objects[i] = newObject;
				step = 1;
			}
			else {
				objects[i] = temp[i - step];

			}
		}
		delete[] temp;
		++length;
	}
	~List()
	{
		delete[] objects;
		objects = nullptr;
	}
};
class Slave {
private:
	int health;
	int attack;
	int price;
	char name[30];
public:
	Slave() = default;
	Slave(int health, int attack, const char* name) : health(health), attack(attack) {
		strcpy_s(this->name,30,name);
	}
	friend std::ostream& operator<<(std::ostream& stream, Slave& slave) {
		stream << "----Slave info----\n";
		stream << "Name: " << slave.name << std::endl;
		stream << "Health: " << slave.health << std::endl;
		stream << "Attack: " << slave.attack << std::endl;
		stream << "------------------\n";
		return stream;
	}
};
int main() {
	List<Slave> myList;
	myList.Add(Slave(10, 0, "Weak"));
	myList.Add(Slave(15, 2, "Medium"));
	myList.Add(Slave(1, 100, "BDSM"));
	myList.Add(Slave(100, 0b0100100, "Diddy"));
	myList.Add(Slave(100, 0xF, "Temu child"));
	myList.Show();

	return 0;
}