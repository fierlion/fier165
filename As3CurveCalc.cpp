/****************************************************************************
**Author: Ray Allan Foote
**Date: Oct 19, 2013
**Description: Calculates the area beneath a predefined curve
**Input: User inputs floats for x-axis start and end points and number 
**of slices to compute.  User also chooses from 5 curve functions.
**Output: The total area beneath the curve from x start - end. 
****************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;
using std::string;

//(functions for assignment 3)
float stringFloat(string userString);
//takes a string as an argument then within the function, prints the string, then gets a float from the user and returns it
float betweenFloat(float one, float two, float thr);
//A function that takes three floats and returns the first float if it is between (<=) the second and third floats, or returns a -1.0 if it isn't
float calcRect(float width, float height);
//takes two floats (width, height) and returns the product of these floats

//(program functions for specific curves)
float f1(float xIn);
//F1(x) = 2x ^ 5 + x ^ 3 - 10x + 2
float f2(float xIn);
//F2(x) = 6x ^ 2 - x + 10
float f3(float xIn);
//F3(x) = 5x + 3
float f4(float xIn);
//F4(x) = 2x ^ 3 + 120
float f5(float xIn);
//F5(x) = 2x ^ 2
float picker(int func, float input);
// Using 'func' with a switch statement to choose one of f1-f5(x) functions. 'input = x' to return the result of the chosen math function.
float curveCalc(float start, float totX, int slices, int fnum);
//main calculation. totX / slices gives the width of each slice.  'start' gives starting point on x-axis. 'fnum' is the function to be fed 
//into picker() with totX/slices as the f(x) input for 'x'--this returns the height.  The function then uses calcRect to find the area for
//each slice.  using slices as iterator, summer collects the totals for all while slices > 0.   
float xLengthCheck(float first, float secnd);
//helper function: returns length of x-axis to be calculated.  Allows for input 'first' to be larger or smaller than 'secnd' 

//verification functions
float getFloat();
//prompts the user to enter a positive float, recieved as string, tests with isFloat() then returns the input as float
int getInt();
//prompts the user to enter an int (1-5), recieved as string, tests with isInt() then returns the input as int
bool isFloat(string numIn);
//checks if string input is float
bool isInt(string numIn);
//checks if string input is int (1-5)

int main()
{
	int repeat = 1;
	while (repeat == 1)
	{
		double total;
		float xStart;
		float xEnd;
		float xLength;
		int slices;
		int fIn;

		//gather variables
		cout << "This program calculates the area under one of five curves." << endl;
		cout << "These are the available equations:" << endl;
		cout << "1.  2x^5 + x^3 - 10x + 2" << endl << "2.  6x^2 - x + 10" << endl << "3.  5x + 3" << endl;
		cout << "4.  2x^3 + 120" << endl << "5.  2x^2" << endl;
		fIn = getInt();
		cout << "Where you would like the X-axis to start?" << endl;
		xStart = getFloat();
		cout << "Where you would like the X-axis to end?" << endl;
		xEnd = getFloat();
		cout << "How many slices would like to dice the area into?" << endl;
		slices = getFloat();

		//do main calculation, return result
		xLength = xLengthCheck(xStart, xEnd);
		cout << "The total area is " << curveCalc(xStart, xLength, fIn, slices) << endl;
		
		//ask to repeat
		cout << "Would you like to repeat the calculations with" << endl;
		cout << "a different set of inputs? (1 -yes | 2 -no): ";
		cin >> repeat;
	}
    return 0;
}

//(assignment 3 function, not used)
float stringFloat(string userString)
{
	cout << userString;
	return getFloat();
}
//(assignment 3 function, not used)
float betweenFloat(float one, float two, float thr)
{
	float between;
	((two >= one && two <= thr) || (two >= thr && two <= one)) ? between = two : between = -1.0;
	return between;
}
//(assignment 3 function)
float calcRect(float width, float height)
{
	return width * height;
}

//function pre-defined curves
float f1(float xIn)
{
	//2x^5 + x^3 - 10x + 2
	return (pow(xIn, 5) * 2) + (pow(xIn, 3)) - (10 * xIn) + 2;
}

float f2(float xIn)
{
	//6x^2 - x + 10
	return (pow(xIn, 2) * 6) - xIn + 10;
}

float f3(float xIn)
{
	//5x + 3
	return (5 * xIn) + 3;
}

float f4(float xIn)
{
	//2x^3 + 120
	return (pow(xIn, 3) * 2) + 120;
}

float f5(float xIn)
{
	//2x^2
	return (pow(xIn, 2) * 2);
}

//switch statement for 5 curves above
float picker(int func, float input)
{
	switch (func)
	{
	case 1:
		return f1(input);
		break;
	case 2:
		return f2(input);
		break;
	case 3:
		return f3(input);
		break;
	case 4:
		return f4(input);
		break;
	case 5:
		return f5(input);
		break;
	//for debugging
	default:
		cout << "Function switch error" << endl;
	}
}

//helper for curveCalc() below
float xLengthCheck(float first, float secnd)
{
	float xLength;
	(first <= secnd) ? (xLength = secnd - first) : (xLength = first - secnd);
	return xLength;
}

//main calculation
float curveCalc(float start, float totX, int fnum, int slices)
{
	float summer = 0;
	float width = totX / slices;
	for (int i = 0; i < slices; i++)
	{
		float pickerXin = start + (width * i);
		float height = picker(fnum, pickerXin);
		summer += calcRect(height, width);
	}
	return summer;
}

//input check functions
float getFloat()
{
	float userNum;
	string userStrNum;
	cout << "Please enter a number: ";
	cin >> userStrNum;
	isFloat(userStrNum);
	while (!(isFloat(userStrNum)))
	{
		cout << "That's not a valid number.  Try again: ";
		cin >> userStrNum;
	}
	userNum = atof(userStrNum.c_str());
	return userNum;
}

int getInt()
{
	int userNum;
	string userStrNum;
	cout << "Please choose function (1-5): ";
	cin >> userStrNum;
	isInt(userStrNum);
	while (!(isInt(userStrNum)))
	{
		cout << "That's not (1-5) Try again: ";
		cin >> userStrNum;
	}
	userNum = atoi(userStrNum.c_str());
	return userNum;
}

bool isFloat(string numIn)
{
	bool isFloat;

	(numIn.find_first_not_of("1234567890.-") != string::npos) ? isFloat = false : isFloat = true;

	return isFloat;
}

bool isInt(string numIn)
{
	bool isInt;

	(1 <= atoi(numIn.c_str()) && 5 >= atoi(numIn.c_str())) ? isInt = true : isInt = false;

	return isInt;
}
