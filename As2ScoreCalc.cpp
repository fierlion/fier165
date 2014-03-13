/********************************************
**Author: Ray Foote
**Date: Oct. 12, 2013
**Description: percentage calculator for user 
**defined number of scores.
**Input: number of total scores, earned scores 
**and possible total score for each.
**Output: total points summed from all earned 
**scores, from total possible, then percent of
**earned/total. 
*********************************************/

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

long totalScores = 0;
double totalPoss = 0.0;
double percent = 0.0;
int numEx = 0;

void getScoNum();
//asks user to input an integer of how many scores they would like to input
void collectNums(int numScores);
//cycles numScores value through scores/totalpossible dialogue.  Each collected number is summed to the global variables
double percenter(double scores, double poss);
//takes two global cumulative values and returns the percent of 'scores' out of 'poss' formatted to two decimal points
void resultPrint(double scores, double poss);
//prints the total points entered, the possible total and the percent
int getPositiveInt();
//prompts user to enter an integer, if not integer, prompts again until user enters int.  Returns user int
bool isPositiveInt(string numIn);
//error check for user input

int main()
{	
	getScoNum();
	collectNums(numEx);
	resultPrint(totalScores, totalPoss);

    return 0;
}

void getScoNum()
{
	cout << "How many scores would you like to input?" << endl;
	numEx = getPositiveInt();
}

void collectNums(int numScores)
{
	for (int i = 0; i < numScores; ++i)
	{
		cout << "please enter total number " << i + 1 << ": ";
		totalScores += getPositiveInt();
		cout << "out of how many points: ";
		totalPoss += getPositiveInt();
	}
}

double percenter(double scores, double poss)
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	return (scores / poss) * 100;
}

void resultPrint(double scores, double poss)
{
	cout << "Total points earned: " << scores << endl;
	cout << "Out of a possible    " << poss << endl;
	cout << "That's " << percenter(scores, poss) << "%" << endl;
}

int getPositiveInt()
{
	int userNum;
	string userStrNum;
	cin >> userStrNum;
	isPositiveInt(userStrNum);
	while (!(isPositiveInt(userStrNum)))
	{
		cout << "Please enter an integer: " << endl;
		cin >> userStrNum;
	}
	userNum = atoi(userStrNum.c_str());
	return userNum;
}

bool isPositiveInt(string numIn)
{
	bool positive;
	(0 < atoi(numIn.c_str())) ? positive = true : positive = false;
	return positive;
}