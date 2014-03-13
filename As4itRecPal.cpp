/**************************************************************
**Author: Ray Allan Foote
**Date: Oct 25, 2013
**Description: iterative/recursive reverse and palindrome check
**Input: word or phrase (alphanumeric, no caps or punctuation)
**       and an int to select which fuction to use
**Output: depending on function choice, outputs word/phrase
**       in reverse and / or tells whether it is a palindrome.
**************************************************************/

#include <iostream>
#include <string>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::string;

//iterative: reverses a string.
//precondition: doesn't check for punctuation or capitalization.  word or phrase is alphanumeric lowercase with spaces only.
//postcondition: returns string, the reverse of the input string
string itRever(string inStr);

//iterative: checks if word is palindrome
//precondition: doesn't check for punctuation or capitalization.  word or phrase is alphanumeric lowercase with spaces only.
//postcondition: returns true if word is a palindrome
bool itIsPal(string inStr);

//recursive: reverses a string.
//precondition: doesn't check for punctuation or capitalization.  word or phrase is alphanumeric lowercase with spaces only.
//postcondition: returns string, the reverse of the input string
string recRever(string inStr, int iter);

//recursive: checks if word is palindrome
//precondition: doesn't check for punctuation or capitalization.  word or phrase is alphanumeric lowercase with spaces only.
//postcondition: returns true if word is a palindrome
bool recIsPal(string inStr);

//switch statement for menu
//precondition: takes an int (checked by getInt()) and a string (alphanumeric lowercase and spaces only, no caps or punctuation)
void picker(int whichOne, string inStr);

//verification functions
//prompts the user to enter an int (1-5), recieved as string, tests with isInt() then returns the input as int
int getInt();

//checks if string input is int (1-5)
bool isInt(string numIn);

int main()
{
	bool repeat = 1;
	while (repeat == 1)
	{

		//main variables
		int whichOne;
		string inStr = "";

		cout << "   Checking for PALINDROME or REVERSING" << endl;
		cout << "1- Iterative word or phrase REVERSE for just $1" << endl;
		cout << "2- Recursive word or phrase REVERSE for only $2" << endl;
		cout << "3- Iterative PALINDROME check, and word or phrase REVERSE a mere $5" << endl;
		cout << "4- Grand slam: Recursive PALINDROME check, and word or phrase REVERSE $40" << endl;

		cout << "Please enter a word or phrase (alphanumeric only, no punctuation): " << endl;
		getline(cin, inStr);
		
		//function sanitizes numeric input
		whichOne = getInt();

		//main switch statement
		picker(whichOne, inStr);

		//check for repeat
		cout << "Would you like another one?" << endl;
		cout << "0- no / 1- yes" << endl;
		cin >> repeat;
	}
	return 0;
}

//iterative reverse
string itRever(string inStr)
{
	string reversed;
	for (int i = inStr.length() - 1; i >= 0; --i)
	{
		reversed += inStr[i];
	}
	return reversed;
}

//iterative palindrome
bool itIsPal(string inStr)
{
	int strPlace = 0;
	for (int i = inStr.length() - 1; i >= 0; --i)
	{
		if (!(inStr.at(strPlace) == inStr.at(i)))
			return 0;
			break;
		strPlace++;
	}
	return 1;
}

//recursive reverse
string recRever(string inStr, int iter)
{
	if (iter >= inStr.length())
		return inStr;
	else
		return recRever(inStr.substr(1, inStr.length() - 1), +iter) + inStr.at(0);
}

//recursive palindrome
bool recIsPal(string inStr)
{
	if (inStr.length() <= 2)
	{
		if (inStr.length() == 1)
			return 1;
		else if (inStr.at(0) == inStr.at(1))
			return 1;
		else
			return 0;
	}

	else
	{
		if (inStr.at(0) == (inStr.at(inStr.length() - 1)))
		{
			return recIsPal(inStr.substr(1, inStr.length() - 2));
		}
	}
	return 0;
}

void picker(int whichOne, string inStr)
{
	int iter = 1;
	switch (whichOne)
	{
	case (1) :
		cout << "\"" << inStr << "\" iteratively reversed is \"" << itRever(inStr) << "\"" << endl;
		cout << "$1 please." << endl;
		break;

	case (2) :
		cout << "\"" << inStr << "\" recursively reversed is \"" << recRever(inStr, iter) << "\"" << endl;
		cout << "$2 please." << endl;
		break;

	case (3) :
		if (itIsPal(inStr))
		{
			cout << "\"" << inStr << "\" is a palindrome (found iteratively). " << endl;
			cout << "Iteratively reversed it's \"" << itRever(inStr) << "\"" << endl;
			cout << "$5 please." << endl;
		}
		else
		{
			cout << "\"" << inStr << "\" is NOT a palindrome (found iteratively). " << endl;
			cout << "Iteratively reversed it's \"" << itRever(inStr) << "\"" << endl;
			cout << "$5 please." << endl;
		}
		break;

	case (4) :
		if (recIsPal(inStr))
		{
			cout << "\"" << inStr << "\" is a palindrome (found recursively). " << endl;
			cout << "Recursively reversed it's \"" << recRever(inStr, iter) << "\"" << endl;
			cout << "$40 bucks.  Now pay up." << endl;
		}
		else
		{
			cout << "\"" << inStr << "\" is NOT a palindrome (found recursively). " << endl;
			cout << "Recursively reversed it's \"" << recRever(inStr, iter) << "\"" << endl;
			cout << "$40 bucks.  Now pay up." << endl;
		}
		break;
	
	default:
		{
			cout << "Invalid inputs.  Please try again." << endl;
		}
	}

}

int getInt()
{
	int userNum;
	string userStrNum;
	cout << "Please choose from the menu above (1-4): ";
	cin >> userStrNum;
	isInt(userStrNum);
	while (!(isInt(userStrNum)))
	{
		cout << "That's not (1-4) Try again: ";
		cin >> userStrNum;
	}
	userNum = atoi(userStrNum.c_str());
	return userNum;
}

bool isInt(string numIn)
{
	bool isInt;

	(1 <= atoi(numIn.c_str()) && 4 >= atoi(numIn.c_str())) ? isInt = true : isInt = false;

	return isInt;
}