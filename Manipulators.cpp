#include<iostream>
#include<iomanip>
#include<ios>
#include<string>

int main()
{
	//1.boolalpha/noboolalpha
	{
	//	std::cout << "--- boolalpha & noboolalpha --- \n";
	//	bool someExpression = true;
	//	std::cout << "someExpression = " << someExpression << std::endl;
	//	std::cout << std::boolalpha;
	//	std::cout << "someExpression = " << someExpression << std::endl;
	//	std::cout << "someExpression = " << false << std::endl;
	//	std::cout << std::noboolalpha;
	//	std::cout << "someExpression = " << false << std::endl;
	}
	//2.dec,hex,oct
	{
		/*std::cout << "--- dec & hex & oct --- \n";
		int value = 100;
		std::cout << "value = " << value << std::endl;
		std::cout << std::dec;
		std::cout << "value = " << value << std::endl;
		std::cout << std::hex;
		std::cout << "value = " << value << std::endl;
		std::cout << std::oct;
		std::cout << "value = " << value << std::endl;*/
	}
	//3.showbase/noshowbase
	{
		//std::cout << "--- showbase & noshowbase --- \n";

		//int value = 100;

		//std::cout << std::dec << "value = " << value << std::endl;
		//std::cout << std::hex << "value = " << value << std::endl;
		//std::cout << std::oct << "value = " << value << std::endl;

		//std::cout << std::showbase;
		//
		//std::cout << std::dec << "value = " << value << std::endl;
		//std::cout << std::hex << "value = " << value << std::endl;
		//std::cout << std::oct << "value = " << value << std::endl;
	}
	//4.uppercase/nouppercase
	{
		//std::cout << "--- uppercase & nouppercase ---\n";
		//std::cout << std::hex << 0xff << std::endl;
		//std::cout << 1e51 << std::endl;

		//std::cout << std::uppercase;

		//std::cout << std::hex << 0xff << std::endl;
		//std::cout << 1e51 << std::endl;

		//std::cout << std::nouppercase;

		//std::cout << std::hex << 0xff << std::endl;
		//std::cout << 1e51 << std::endl;

		//std::cout << std::dec;
	}
	//5.showpos/noshowpos
	{
	/*	std::cout << "--- showpos & noshowpos ---\n";

		int positive = 100;
		int negative = -100;

		std::cout << "Positive value: " << positive << std::endl;
		std::cout << "Negative value: " << negative << std::endl;

		std::cout << std::showpos;

		std::cout << "Positive value: " << positive << std::endl;
		std::cout << "Negative value: " << negative << std::endl;

		std::cout << std::noshowpos;

		std::cout << "Positive value: " << positive << std::endl;
		std::cout << "Negative value: " << negative << std::endl;*/
	}
	//6.showpoint/noshowpoint
	{
		//std::cout << "--- showpoint & noshowpoint ---\n";

		//float fraction1 = 1.0f;
		//float fraction2 = 1.123f;

		//std::cout << "fraction1 = " << fraction1 << std::endl;
		//std::cout << "fraction2 = " << fraction2 << std::endl;
		//std::cout << std::showpoint;
		//std::cout << "fraction1 = " << fraction1 << std::endl;
		//std::cout << "fraction2 = " << fraction2 << std::endl;
	}
	//7.skipws/noskipws
	{
		//std::cout << "--- skipws & noskipws ---\n";

		//std::cout << "Enter a number: ";
		//int num;
		//std::cin >> std::noskipws;
		//std::cin >> num;
		//std::cout << "num = " << num << std::endl;
	}
	//8.unitbuf/nounitbuf
	{
	/*	std::cout << "--- unitbuf & nounitbuf ---\n";

		int someNumber = 10;

		std::cout << "Some information " << "Another information " << someNumber << "\n";
		std::cout << std::unitbuf;
		std::cout << "Some information\n";
		std::cout << std::flush;
		std::cout << "Another information\n";
		std::cout << someNumber << "\n";
		std::cout << std::flush;*/
	}
	//9.internal/left/right
	{
		/*std::cout << "--- internal & left & right ---\n";

		std::cout.imbue(std::locale("en_US.utf8"));

		std::cout << "Default position:\n";
		std::cout << std::setw(12) << -1.23 << "\n";
		std::cout << std::setw(12) << std::hex << std::showbase << 42 << "\n";
		std::cout << std::setw(12) << std::put_money(123,true) << "\n\n";

		std::cout << "left position:\n" << std::left;
		std::cout << std::setw(12) << -1.23 << "\n";
		std::cout << std::setw(12) << std::hex << std::showbase << 42 << "\n";
		std::cout << std::setw(12) << std::put_money(123, true) << "\n\n";

		std::cout << "Internal position:\n" << std::internal;
		std::cout << std::setw(12) << -1.23 << "\n";
		std::cout << std::setw(12) << std::hex << std::showbase << 42 << "\n";
		std::cout << std::setw(12) << std::put_money(123, true) << "\n\n";

		std::cout << "Right position:\n" << std::right;
		std::cout << std::setw(12) << -1.23 << "\n";
		std::cout << std::setw(12) << std::hex << std::showbase << 42 << "\n";
		std::cout << std::setw(12) << std::put_money(123, true) << "\n\n";*/
	}
	//10.fixed/scientific
	{
		/*std::cout << "--- fixed & scientific ---\n";

		double a = 3.1415926534;
		double b = 2006.0;
		double c = 1.0e-10;

		std::cout << "Default:\n";
		std::cout << a << '\n' << b << '\n' << c << '\n';

		std::cout << '\n';

		std::cout << "Fixed:\n" << std::fixed;
		std::cout << a << '\n' << b << '\n' << c << '\n';

		std::cout << '\n';

		std::cout << "Scientific:\n" << std::scientific;
		std::cout << a << '\n' << b << '\n' << c << '\n';

		std::cout << '\n';*/
	}
	//11.hexfloat/defaultfloat
	{
	/*	std::cout << "--- hexfloat & defaultfloat---\n";

		double a = 0.0;
		double b = 123.0;
		double c = 0.123;
		double d = 123.456;

		std::cout << "Default:\n";
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
		std::cout << "c = " << c << std::endl;
		std::cout << "d = " << d << std::endl;

		std::cout << std::endl;
		std::cout << std::hexfloat;

		std::cout << "hexfloat:\n";
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
		std::cout << "c = " << c << std::endl;
		std::cout << "d = " << d << std::endl;*/
	}
	//12.ws
	{
	/*	std::cout << "--- ws ---\n";
		std::cout << "Enter your age: ";
		int age;
		std::cin >> age;

		std::cout << "Enter your fullname: ";
		std::string fullname;
		
		std::cin >> std::ws;
		std::getline(std::cin, fullname);

		std::cout << "Your fullname: [" << fullname << "]\n";*/
	}
	//13.setbase
	{
		//std::cout << "--- setbase ---\n";

		//int number = 255;

		//std::cout << "number = " << number << std::endl;
		//std::cout << std::setbase(16);
		//std::cout << "number = " << number << std::endl;
		//std::cout << std::setbase(10);
		//std::cout << "number = " << number << std::endl;
		//std::cout << std::setbase(8);
		//std::cout << "number = " << number << std::endl;

	}
	//14.setw
	{
	/*	std::cout << "--- setw ---\n";

		int intNum = 123;
		double doubleNum = 123.456;
		char character = '$';

		std::cout << "default:\n";
		std::cout << "int = [" << intNum << "]\n";
		std::cout << "double = [" << doubleNum << "]\n";
		std::cout << "char = [" << character << "]\n";

		std::cout << "Width 10:\n";

		std::cout << "int = [" << std::setw(10) <<intNum << "]\n";
		std::cout << "double = [" << std::setw(10) << doubleNum << "]\n";
		std::cout << "char = [" << std::setw(10) << character << "]\n";*/

	}
	//15.setfill
	{
		/*std::cout << "--- setfill ---\n";

		int intNum = 123;
		double doubleNum = 123.456;
		char character = '$';

		std::cout << "default:\n";
		std::cout << "int = [" << intNum << "]\n";
		std::cout << "double = [" << doubleNum << "]\n";
		std::cout << "char = [" << character << "]\n";

		std::cout << "Width 10:\n";

		std::cout << std::setfill('+');
		std::cout << "int = [" << std::setw(10) << intNum << "]\n";
		std::cout << "double = [" << std::setw(10) << doubleNum << "]\n";
		std::cout << "char = [" << std::setw(10) << character << "]\n"; */
	}
	//16.setprecision
	{
		std::cout << "--- setprecision ---\n";

		double num = 0.12345678987654321;

		std::cout << num << std::endl;
		std::cout << std::setprecision(10);
		std::cout << num << std::endl;
		std::cout << std::setprecision(3);
		std::cout << num << std::endl;
		std::cout << std::setprecision(17);
		std::cout << num << std::endl;

	}
}