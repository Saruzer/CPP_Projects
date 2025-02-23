#include<ios>
#include<iostream>
#include<ostream>
#include<istream>
#include<fstream>
#include<string>
#include<vector>

void streamStateAndFix() 
{
	std::cout << "Enter a number: ";
	int number;
	std::cin >> number;
	if(std::cin.good())
	{
		std::cout << "Your number: " << number << std::endl;
	}
	else
	{
		std::cout << "Oops. Something went wrong.\n";
		if(std::cin.bad())
		{
			std::cout << "cin.bad() == true.\n";
		}
		if (std::cin.fail())
		{
			std::cout << "cin.fail() == true.\n";
		}
		if (std::cin.eof())
		{
			std::cout << "cin.eof() == true.\n";
		}
		while (!std::cin.good() && std::cin.fail()) 
		{
			std::cin.clear();
			std::cout << "You entered incorrect value. Enter only one integer number.\n";

			std::cin.ignore(LLONG_MAX,'\n');

			std::cout << "Enter a number: ";
			std::cin >> number;
		}
	}
}
int readFromFile1()
{
	std::string filename = "file.txt";
	std::ifstream fileStream(filename);

	if (!fileStream.is_open())
	{
		std::cerr << "Couldn't open the file :(\n";
		return 1;
	}

	char character;

	while(fileStream.get(character))
	{
		std::cout << character;
	}
	if (fileStream.eof()) 
	{
		std::cout << "\n\nWe reached the end of the file.\n";
	}
}
int readFromFile2()
{
	std::string filename = "file.txt";
	std::ifstream fileStream(filename);

	if (!fileStream.is_open())
	{
		std::cerr << "Couldn't open the file :(\n";
		return 1;
	}
	std::string line;
	while(std::getline(fileStream,line,'\r'))
	{
		std::cout << line;
	}
	if (fileStream.eof())
	{
		std::cout << "\n\nWe reached the end of the file.\n";
	}
}
int readFromFile3()
{
	std::string filename = "file.txt";
	std::ifstream fileStream(filename,std::ios::binary);

	if (!fileStream.is_open())
	{
		std::cerr << "Couldn't open the file :(\n";
		return 1;
	}

	fileStream.seekg(0, std::ios::end);
	size_t fileSize = fileStream.tellg();
	fileStream.seekg(0, std::ios::beg);	

	size_t bufferLength = fileSize + 1;
	char* buffer = new char[bufferLength];
	fileStream.read(buffer, fileSize);
	buffer[fileSize] = '\0';
	
	if(fileStream.gcount() != fileSize)
	{
		std::cerr << "Error reading file. :(\n";
		return 1;
	}
	std::cout << buffer;
	delete[] buffer;
}
int readFromFileSpecial()
{
	int variable;
	double array[3];

	class Point
	{
	private:
		float x;
		float y;
	public:
		Point(float x = 0, float y = 0) : x(x), y(y) {}
		float X() const { return x; }
		float Y() const { return y; }
	};
	Point myPoint;
	std::vector<int> myVector(5);

	std::string filename = "myData.bin";
	std::ifstream fileStream(filename, std::ios::binary);

	if (!fileStream.is_open())
	{
		std::cerr << "Couldn't open the file :(\n";
		return 1;
	}

	fileStream.read(reinterpret_cast<char*>(&variable), sizeof(variable));
	fileStream.read(reinterpret_cast<char*>(&array), sizeof(double) * 3);
	fileStream.read(reinterpret_cast<char*>(&myPoint), sizeof(Point));
	fileStream.read(reinterpret_cast<char*>(myVector.data()), sizeof(int)* myVector.size());

	std::cout << "variable = " << variable << std::endl;
	std::cout << "array = ";
	for (size_t i = 0; i < 3; i++)
	{
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;

	std::cout << "Point: [x = " << myPoint.X() << ", y = " << myPoint.Y() << "]\n";
	std::cout << "vector = ";
	for (int elements : myVector)
	{
		std::cout << elements << " ";
	}
	std::cout << std::endl;
}

int writeInFile1()
{
	std::string filename = "file2.txt";
	std::ofstream fileStream(filename, std::ios::out);
	
	if(!fileStream.is_open())
	{
		std::cerr << "Couldn't open the file :(\n";
		return 1;
	}
	
	std::cout << "Enter some text: ";
	std::string text;
	std::getline(std::cin,text);

	size_t textLength = text.length();
	for (size_t i = 0; i < textLength; i++)
	{
		fileStream.put(text[i]);
	}
}
int writeInFile2()
{
	std::string filename = "file2.txt";
	std::ofstream fileStream(filename, std::ios::out);

	if (!fileStream.is_open())
	{
		std::cerr << "Couldn't open the file :(\n";
		return 1;
	}
	std::string line1 = "SOME TEXT AAAA";
	std::string line2 = ".....It's a some line of text";
	fileStream << line1 << '\n' << line2 << '\n';
}
int writeInFile3()
{
	std::string filename = "file2.txt";
	std::ofstream fileStream(filename, std::ios::out);

	if (!fileStream.is_open())
	{
		std::cerr << "Couldn't open the file :(\n";
		return 1;
	}

	std::string text{"Some text"};
	fileStream.write(text.c_str(), text.length());
}
int WriteInFileNOTaText() {
	int variable = 10;
	double array[3] = { 1.123,2.456,3.789 };

	class Point
	{
	private:
		float x;
		float y;
	public:
		Point(float x = 0, float y = 0) : x(x), y(y) {}
		float X() const { return x; }
		float Y() const { return y; }
	};
	Point myPoint(12.3f, 54.6f);
	std::vector<int> myVector = { 1,2,3,4,5 };
	
	std::string filename = "myData.bin";
	std::ofstream fileStream(filename, std::ios::binary);

	if(!fileStream.is_open())
	{
		std::cerr << "Couldn't open the file :(\n";
		return 1;
	}

	fileStream.write(reinterpret_cast<const char*>(&variable), sizeof(variable));
	fileStream.write(reinterpret_cast<const char*>(array), sizeof(double) * 3);
	fileStream.write(reinterpret_cast<const char*>(&myPoint), sizeof(Point));
	fileStream.write(reinterpret_cast<const char*>(myVector.data()), sizeof(int) * myVector.size());
}


int main()
{
	readFromFileSpecial();
	return 0;
}
