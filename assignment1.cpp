/****************************************************************
**Author: Ray Allan Foote
**Date: 10/05/2013
**Description: CS 165 Accelerated intro to CS Assignment 1: types
**Input: user inputs any number
**Output: the min/max of each of the basic variable types as
**        well as the user's number in dec, hex and oct.
*****************************************************************/

#include <iostream>
#include <climits>

using namespace std;

int main()
{
//user input variable
	long userInput;
//the 6 minimum required variables: used with typecasting to obtain min and max for each value.
	short shortMax = SHRT_MAX;
	unsigned short uShortMax = USHRT_MAX;
	int intMax = INT_MAX;
	unsigned int uIntMax = UINT_MAX;
	long longMax = LONG_MAX;
	unsigned long uLongMax = ULONG_MAX;

//prints each short, int, long out in decimal, hex, and oct.  Each variable has a single statement with all three conversions.
	cout << "Short Min in decimal is " << dec << static_cast<short>(shortMax + 1) << ", in hexadecimal is "
		 << hex << static_cast<short>(shortMax + 1) << ", and in octal is " << oct << static_cast<short>(shortMax + 1) << ". " << endl;
	cout << "Short Max in decimal is " << dec << shortMax << ", in hexadecimal is "
		 << hex << shortMax << ", and in octal is " << oct << shortMax << ". " << endl;
	cout << "Unsigned Short Min in decimal is " << dec << static_cast<unsigned short>(uShortMax + 1) << ", in hexadecimal is "
		 << hex << static_cast<unsigned short>(uShortMax + 1) << ", and in octal is " << oct << static_cast<unsigned short>(uShortMax + 1) << ". " << endl;
	cout << "Unsigned Short Max in decimal is " << dec << uShortMax << ", in hexadecimal is "
		 << hex << uShortMax << ", and in octal is " << oct << uShortMax << ". \n" << endl;

	cout << "Int Min in decimal is " << dec << static_cast<int>(intMax + 1) << ", in hexadecimal is "
		 << hex << static_cast<int>(intMax + 1) << ", and in octal is " << oct << static_cast<int>(intMax + 1) << ". " << endl;
	cout << "Int Max in in decimal is " << dec << intMax << ", in hexadecimal is "
		 << hex << intMax << ", and in octal is " << oct << intMax << ". " << endl;
	cout << "Unsigned Int Min in decimal is " << dec << static_cast<unsigned int>(uIntMax + 1) << ", in hexadecimal is "
		 << hex << static_cast<unsigned int>(uIntMax + 1) << ", and in octal is " << oct << static_cast<unsigned int>(uIntMax + 1) << ". " << endl;
	cout << "Unsigned Int Max in decimal is " << dec << uIntMax << ", in hexadecimal is "
		 << hex << uIntMax << ", and in octal is " << oct << uIntMax << ". \n" << endl;

	cout << "Long Min in decimal is " << dec << static_cast<long>(longMax + 1) << ", in hexadecimal is "
		 << hex << static_cast<long>(longMax + 1) << ", and in octal is " << oct << static_cast<long>(longMax + 1) << ". " << endl;
	cout << "Long Max in decimal is " << dec << longMax << ", in hexadecimal is "
		 << hex << longMax << ", and in octal is " << oct << longMax << ". " << endl;
	cout << "Unsigned Long Min in decimal is " << dec << static_cast<unsigned long>(uLongMax + 1) << ", in hexadecimal is "
		 << hex << static_cast<unsigned long>(uLongMax + 1) << ", and in octal is " << oct << static_cast<unsigned long>(uLongMax + 1) << ". " << endl;
	cout << "Unsigned Long Max in decimal is " << dec << uLongMax << ", in hexadecimal is "
		 << hex << uLongMax << ", and in octal is " << oct << uLongMax << ". \n" << endl;

//Add 1 to all max, subtract 1 from all min and print the decimal result (overflow)
	cout << "Short Min overflow: " << dec << static_cast<short>((shortMax + 1) - 1) << endl;
	cout << "Short Max overflow: " << dec << static_cast<short>(shortMax + 1) << endl;
	cout << "Unsigned Short Min overflow: " << static_cast<unsigned short>((uShortMax + 1) - 1) << endl;
	cout << "Unsigned Short Max overflow: " << static_cast<unsigned short>(uShortMax + 1) << endl;

	cout << "Int Min overflow: " << dec << static_cast<int>((intMax + 1) - 1) << endl;
	cout << "Int Max overflow: " << dec << static_cast<int>(intMax + 1) << endl;
	cout << "Unsigned Int Min overflow: " << dec << static_cast<unsigned int>((uIntMax + 1) - 1)<< endl;
	cout << "Unsigned Int Max overflow: " << dec << static_cast<unsigned int>(uIntMax + 1) << endl;

	cout << "Long Min overflow: " << dec << static_cast<long>((longMax + 1) - 1) << endl;
	cout << "Long Max overflow: " << dec << static_cast<long>(longMax + 1) << endl;
	cout << "Unsigned Long Min overflow: " << dec << static_cast<unsigned long>((uLongMax + 1) - 1) << endl;
	cout << "Unsigned Long Max overflow: " << dec << static_cast<unsigned long>(uLongMax + 1) << "\n" << endl;

//Prompt user for numerical input, output that as dec, hex and oct
	cout << "Now you try.\nEnter any number: ";
	cin >> userInput;
	cout << "Your number: " << dec << userInput << "\nin decimal is " << dec << userInput << ", in hexadecimal is "
		<< hex << userInput << ", and in octal is " << oct << userInput << ". \n" << endl;

	return 0;
}
