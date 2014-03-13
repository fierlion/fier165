/*******************************************
**Author: Ray Allan Foote
**Date: Oct 13, 2013
**Description: Guess the number game.  Computer
**picks a random number and gives the user a set
**number of guesses to find it.
**Input: guesses (int) and a 1 or 2 for repeat
**of game.
**Output: each guess gets feedback: a range
**based on user's input (userMin, userMax) and 
**a message when user wins or loses to ask if
**another game interests the user.
*******************************************/

#include <iostream>
#include <string>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>

using std::cout;
using std::cin;
using std::endl;
using std::string;

short repeat = 1;
int numTries = 5;
int secretNum;
int userGuess;
int userMin = 1;
int userMax = 50;

int getRand(int maxRand);
//returns a random number from 1 to maxRand
void startGame();
//Introduces game, initializes variables
void gameLoop(int numTry);
//prompts user to enter a guess 'numTry' number of times.  Outputs the current max/min guessed by the user each time.
//When the user either guesses the number or uses all 'numTry' guesses, the loop terminates.
void endGame();
//Game summary and prompt to repeat
int getPositiveInt();
//prompts user to enter an integer, if not integer, prompts again until user enters int.  Returns user int. 
bool isPositiveInt(string numIn);
//error check for user input

int main()
{
	while (repeat == 1)
	{
		startGame();
		gameLoop(numTries);
		endGame();
	}

	return 0;
}

int getRand(int maxRand)
{
	int randNum;
	srand(time(NULL));
	//initialize random seed
	randNum = rand() % maxRand + 1;
	//generate random number
	return randNum;
}

void startGame()
{
	//secretNum = 25;
	secretNum = getRand(50);
	numTries = 5;
	userMin = 1;
	userMax = 50;
	cout << "I\'m thinking of a number between 1 and 50" << endl;
	cout << "I'll give you 5 tries to guess what it is." << endl;
	cout << "Guess: ";
}

void gameLoop(int numTry)
{
	for (int i = numTry; i > 0; --i)
	{
		userGuess = getPositiveInt();
		if (userGuess < secretNum)
		{
			if (userGuess >= userMin)
			{
				userMin = userGuess;
				cout << "It's higher than " << userGuess << ", and less than " << userMax << endl;
				cout << "You have " << (i - 1) << " left." << endl;
			}
			else
			{
				cout << "It's higher than " << userGuess << ", and less than " << userMax << endl;
				cout << "You have " << (i - 1) << " left." << endl;
			}
		}
		else if (userGuess > secretNum)
		{
			if (userGuess <= userMax)
			{
				userMax = userGuess;
				cout << "It's less than " << userGuess << ", and more than " << userMin << endl;
				cout << "You have " << (i - 1) << " left." << endl;
			}
			else
			{
				cout << "It's less than " << userGuess << ", and more than " << userMin << endl;
				cout << "You have " << (i - 1) << " left." << endl;
			}
		}
		else
		{
			cout << "You got it." << endl;
			break;
		}
	}
}

void endGame()
{
	cout << endl << "My number is " << secretNum << "." << endl;
	cout << "Do you want to play again?" << endl;
	cout << "(press 1 for yes, 2 for no): ";
	cin >> repeat;
}

int getPositiveInt()
{
	int userNum;
	string userStrNum;
	cin >> userStrNum;
	isPositiveInt(userStrNum);
	while (!(isPositiveInt(userStrNum)))
	{
		cout << "Please enter a guess (an integer) 1-50: " << endl;
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

