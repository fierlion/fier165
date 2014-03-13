/*****************************************************************
**Name: Ray Allan Foote
**Date: Nov. 24, 2013
**Description: This program takes user input for various dice,
**number of die sides and number of rolls and prints out a 
**histogram of values based on those inputs.
**Input: User inputs dice by diceSides: each die is an independent 
**object.  User then inputs number of rolls to roll all the dice.
**Output: A histogram of percentages for each possible sum over 
**all rolled dice.
******************************************************************/

#include <iostream>
#include <list>
#include <map>
#include <cstdlib>
#include <time.h>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::ios;
using std::list;
using std::map;
using std::setw;
using std::setprecision;

class Die
{
public:
	Die();
	//initializes die to 6 sides.  Used if user doesn't input die side.
	Die(int numSidesIn);
	//initializes die to have numSidesIn sides
	int getSides();
	int getRoll();
	void rollDie();
	//returns a random number between 1 and numSides to "roll" private variable
private:
	int numSides;
	int roll;
};

Die makeDie(int dieSides);
void getDieNums(list<int> &dieSides, list<Die> &dieList);
//asks user to input dice by dieSides, then puts these into the dieList
void rollSum(list<Die> &dieList, int &rollCount);
//asks user to enter numRolls, runs rollDie() on each element in dieList numRolls times then pushes the results into map "hist" 
void histPrint(int &rollCount);
//prints out a histogram of percentages for each possible sum over all rolled dice.
map<int, int> hist;
//contains the number of times each sum is rolled

list<Die>::iterator d;
list<int>::iterator i;

int main()
{
	int rollCount = 0;
	//int dieCount = 0;
	list<Die> dieList;
	list<int> dieSides;
	srand(time(NULL));
	getDieNums(dieSides, dieList);
	rollSum(dieList, rollCount);
	histPrint(rollCount);

    return 0;
}

Die::Die()
{
	numSides = 6;
}

Die::Die(int numSidesIn)
{
	numSides = numSidesIn;
}

int Die::getSides()
{
	return numSides;
}

int Die::getRoll()
{
	return roll;
}

void Die::rollDie()
{
	roll = (rand() % numSides + 1);
}

Die makeDie(int dieSides)
{
	Die newDie(dieSides);
	return newDie;
}

void getDieNums(list<int> &dieSides, list<Die> &dieList)
{
	int dieNum;
	cout << "Enter each die, by number of sides, followed by \"enter\""<< endl;
	cout << "When you have finished inputs, enter \'0\' sides to continue." <<endl;

	while (dieNum != 0)
	{
		cout << "die (enter # sides, or \'0\' when done): ";
		cin >> dieNum;
		if (dieNum != 0)
		{
			dieSides.push_back(dieNum);
		}
	}
	if (dieSides.size()==0)
	{
		dieList.push_back(Die());
	}
	else
	{
		for (i = dieSides.begin(); i != dieSides.end(); i++)
		{
			dieList.push_back(makeDie(*i));
		}
	}
}

void rollSum(list<Die> &dieList, int &rollCount)
{
	int rollSum = 0;
	cout << "Enter number of rolls: " << endl;
	cin >> rollCount;
	for (int i = 0; i < rollCount; i++)
	{
		for (d = dieList.begin(); d != dieList.end(); d++)
		{
			(*d).rollDie();
		}
		for (d = dieList.begin(); d != dieList.end(); d++)
		{
			rollSum += (*d).getRoll();
		}
		if (hist.find(rollSum) == hist.end())
		{
		
			hist[rollSum] = 0;
		}
		++hist[rollSum];
		rollSum = 0;
	}
}
void histPrint(int &rollCount)
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	for (int i = 1; i <= hist.size(); i++)
	{
		cout << i << ": " << (static_cast<double>(hist[i]) / rollCount)*100 << "%" << endl;
	}
}