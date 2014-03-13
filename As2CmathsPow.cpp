/************************************************
**Author: Ray Foote
**Date: Oct 12, 2013
**Description: outputs to console signed/unsigned
**max/min for each short, int and long using pow
**function
**Input: n/a
**Output: see description
************************************************/

#include <iostream>
#include <math.h>

using std::cout;
using std::cin;
using std::endl;

int main()
{
	cout << "signed short min: " << pow(-2, 15) + 1 << endl;
	cout << "signed short max: " << pow(2, 15) - 1 << endl;
	cout << "unsigned short min: " << 0 << endl;
	cout << "unsigned short min: " << pow(2, 16) - 1 << endl;
	cout << endl;

	cout << "signed int min: " << pow(-2, 15) + 1 << endl;
	cout << "signed int max: " << pow(2, 15) - 1 << endl;
	cout << "unsigned int min: " << 0 << endl;
	cout << "unsigned int max: " << pow(2, 16) - 1 << endl;
	cout << endl;

	cout << "signed long min: " << pow(-2, 31) + 1 << endl;
	cout << "signed long max: " << pow(2, 31) - 1 << endl;
	cout << "unsigned long min: " << 0 << endl;
	cout << "unsigned long max: " << pow(2, 32) - 1 << endl;
	cout << endl;
 
    return 0;
}

