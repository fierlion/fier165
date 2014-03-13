/*****************************************************************************************************************************
**Author: Ray Allan Foote
**Date: Nov 2, 2013
**Description: Populates a square or rectangular grid with random numbers, dimensions given by command line input formatted as 
**[program name] -r [int #rows] -c [int #cols]
**Searches grid using tetris block shaped bubbles, returning the highest product of the 4 numbers, the 
**position of this product in the grid, the orientation of the tetris block in 0-3 clockwise rotations
**and the 4 individual numbers which make the shape.
**Input: 2 integers (>= 4).  Command line input formatted as [program name] -r [int #rows] -c [int #cols]
**Output: Example return: "Max Product: 209189234, Position: 4, 7, Shape: T-block, Orientation (in # clockwise rotations): 2,
**Numbers: 56 54 60 51"
*****************************************************************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <time.h>

using std::cout;
using std::cin;
using std::endl;
using std::setw;
using std::string;
using std::ios;

struct tetris
{
	int greatest;
	int col;
	int row;
	int shape;
	int maxOrient;
};
 //global variables
tetris largest;
int row;
int col;
int bigger;
int orient = 0;
const int width = 3;

//Latham Fell from class posted this awesome start.  Helped me immensely!
//this elegant little number gets the command line args and pipes them through
//errorCheck()
void GetCmdLineArgs(int argc, char *argv[], int &row, int &col);
//Quick error checks, using errorSwitch() to output error messages
void errorCheck(int argc, char *argv[]);
//switch statement containing cout messages
void errorSwitch(int errNum);


//Array initialize function.  For square arrays initializes to row/col dimensions.  
//for rectangular arrays it uses 'bigger' global var to set dimensions and pads 
//excess array space with '0' so the rotation functions will work.
int **createTable(int col, int row);

//arrRev() and arrRot() work together to rotate the array 90 degrees counterclockwise
//take in initialized array (with createTable()) and outputs a rotated array.
//caution--this process mutates the innitial array, so have another copy.
int **arrRev(int **arrIn, int **arrOut);
int **arrRot(int **arrIn, int **arrOut);
//makes main() prettier by combining arrRev() and arrRot()
void flip(int **arrIn, int **arrOut);
//helper function for arrRev() takes in a 2d array and returns the reverse array
int *ReverseArray(int*orig, unsigned short int b);

//returns translated coordinates from rotated grid to initial grid orientation based on largest.maxOrient
void unwind(tetris &largest);
//formats and prints results with call to printSwitchType()
void printOut(tetris &largest);
//translates int type into string block-type
string printSwitchType(int type);

//tetris shape functions
//getLargestL() tests for 'L' -0 'T' -1 and 'backL' -2, with the associated int (0,1,2) input to 'lShape' 
//all tests send result to &largest 
void getLargestL(int **arrIn, int lShape, tetris &largest);
//getLargestS() tests for the square shape
void getLargestS(int **arrIn, tetris &largest);
//getLargestI() tests for the horizontal 4line shape
void getLargestI(int **arrIn, tetris &largest);
//a combined function to run through 3 variants of getLargestL(), getLargestS(), and getLargestI() 
void testAll(int **arrIn, tetris &largest);

//prints array without padding.  Caution--only prinnts dimensions of initial array
//and truncates view of any rotated array
void arrPrint(int **pArr);
//cleanup function
void deleteTable(int **pArr);
//pritties up main() by combining deleteTable() calls for all initialized arrays 
void deleteAll(int **pArr, int **pArr1);

int main(int argc, char *argv[]) 
{
	GetCmdLineArgs(argc, argv, row, col);

	bigger = (row > col) ? (bigger = row) : (bigger = col);

		//declaration
	int **pArr0 = createTable(col, row);
	int **pArr1 = createTable(col, row);

	arrPrint(pArr0);
	testAll(pArr0, largest);
	flip(pArr0, pArr1);
	testAll(pArr1, largest);	
	flip(pArr1, pArr0);
	testAll(pArr0, largest);
	flip(pArr0, pArr1);
	testAll(pArr1, largest);
	unwind(largest);
	printOut(largest);
	deleteAll(pArr0, pArr1);
	return 0;
}

void GetCmdLineArgs(int argc, char *argv[], int &row, int &col)//thanks latham!
{
   errorCheck(argc, argv); //checks for any errors in input
   
   for(int i = 1; i < 4; i += 2) {
      if(argv[i][1] == 'r') {
         row = atoi(argv[i+1]);
      } else if(argv[i][1] == 'c') {
         col = atoi(argv[i+1]);
      }
   }
}

int **createTable(int col, int row)
{
	int **pArr;
	int count;
	//initialize random seed
	srand(time(NULL));
	//allocation
	pArr = new int*[bigger];
	for (int i = 0; i < bigger; i++)
	{
		pArr[i] = new int[bigger];
	}
	for (int i = 0; i < bigger; i++)
	{
		for (int j = 0; j < bigger; j++)
		{
			pArr[i][j] = 0;
		}
	}
	//initialization of table with random numbers
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			pArr[i][j] = rand() % (row * col) + 1;
		}
	}
	return pArr;
}

void getLargestL(int **arrIn, int lShape, tetris &largest)
{
	for (int i = 0; i < (bigger - 1); i++)
	{
		for (int j = 0; j < (bigger - 2); j++)
		{
			if (arrIn[i][j] * arrIn[i][j + 1] * arrIn[i][j + 2] * arrIn[i + 1][j + lShape] > largest.greatest)
			{
				largest.greatest = (arrIn[i][j] * arrIn[i][j + 1] * arrIn[i][j + 2] * arrIn[i + 1][j + lShape]);
				largest.row = i;
				largest.col = j;
				largest.shape = lShape;
				largest.maxOrient = orient;
			}
		}
	}
}

void getLargestS(int **arrIn, tetris &largest)
{
	for (int i = 0; i < (bigger - 1); i++)
	{
		for (int j = 0; j < (bigger - 1); j++)
		{
			if (arrIn[i][j] * arrIn[i][j + 1] * arrIn[i + 1][j] * arrIn[i + 1][j + 1] > largest.greatest)
			{
				largest.greatest = (arrIn[i][j] * arrIn[i][j + 1] * arrIn[i + 1][j] * arrIn[i + 1][j + 1]);
				largest.row = i;
				largest.col = j;
				largest.shape = 3;
				largest.maxOrient = orient;
			}
		}
	}
}

void getLargestI(int **arrIn, tetris &largest)
{
	for (int i = 0; i < (bigger); i++)
	{
		for (int j = 0; j < (bigger - 3); j++)
		{
			if (arrIn[i][j] * arrIn[i][j + 1] * arrIn[i][j + 2] * arrIn[i][j + 3] > largest.greatest)
			{
				largest.greatest = (arrIn[i][j] * arrIn[i][j + 1] * arrIn[i][j + 2] * arrIn[i][j + 3]);
				largest.row = i;
				largest.col = j;
				largest.shape = 4;
				largest.maxOrient = orient;
			}
		}
	}
}

void testAll(int **arrIn, tetris &largest)
{
	getLargestI(arrIn, largest);
	getLargestL(arrIn, 0, largest);
	getLargestL(arrIn, 1, largest);
	getLargestL(arrIn, 2, largest);
	getLargestS(arrIn, largest);
}

void arrPrint(int **pArr)
{
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << setw(width);
			cout << pArr[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

int **arrRev(int **arrIn, int **arrOut)
{
	for (int i = 0; i < bigger; i++)
	{
		ReverseArray(arrIn[i], bigger);
		for (int j = 0; j < bigger; j++)
		{
			arrOut[i][j] = arrIn[i][j];
		}
	}
	return arrOut;
}

int **arrRot(int **arrIn, int **arrOut)
{
	for (int i = 0; i < bigger; i++)
	{
		for (int j = 0; j < bigger; j++)
		{
			arrOut[i][j] = arrIn[j][i];
		}
	}
	return arrOut;
}

void flip(int **arrIn, int **arrOut)
{
	arrRev(arrIn, arrOut);
	arrRot(arrIn, arrOut);
	orient++;
}

int *ReverseArray(int*orig, unsigned short int b)
{
	unsigned short int a = 0;
	int swap;

	for (a; a < --b; a++)
	{
		swap = orig[a];
		orig[a] = orig[b];
		orig[b] = swap;
	}

	return orig;
}

void unwind(tetris &largest)
{
	int temp;
	for (int i = 0; i < largest.maxOrient; i++)
	{
		temp = (bigger - 1) - largest.row;
		largest.row = largest.col;
		largest.col = temp;
	}
}

void printOut(tetris &largest)
{
	// "Max Product: 209189234, Position: 4, 7, Shape: T-block, Orientation (in # clockwise rotations): 2, Numbers: 56 54 60 51
	cout << "Max Product: " << largest.greatest << endl << "Position: row " << largest.row << " col ";
	cout << largest.col << endl << "Shape: " << printSwitchType(largest.shape) << endl;
	cout << "Orientation (# clockwise 90 degree rotations): " << largest.maxOrient << endl;
}

string printSwitchType(int type)
{
	switch (type)
	{
		case (0):
		return "L-block";
		break;

		case (1):
		return "T-block";
		break;

		case (2):
		return "Inverse L-block";
		break;

		case (3):
		return "Square block";
		break;

		case (4):
		return "4-long block";
		break;
	}
}

void errorCheck(int argc, char *argv[])
{
	int userNum1;
	int userNum2;
	if(argc >= 5) 
  	{
      if ((isdigit(argv[2][0]))&&(isdigit(argv[4][0])))
      {
      	userNum1 = atoi (argv[2]);
      	userNum2 = atoi (argv[4]);
      	if (userNum1 < 4)
      	{
      		errorSwitch(3);
      	}
      	else if (userNum2 < 4)
      	{
      		errorSwitch(3);
      	}
      }
      else
      {
      	errorSwitch(2);
      }
  	}
    else
    {
      errorSwitch(1);
    }

}

void errorSwitch(int errNum)
{
	switch (errNum)
	{
		case (1):
		cout << "Error 1: Please supply 5 command line arguments, input format:" << endl;
		cout << "[program name] -r [int #rows] -c [int #cols]" << endl;
		exit(1);
		break;

		case (2):
		cout << "Error 2: Incorrect input format, input format:" << endl;
		cout << "[program name] -r [int #rows] -c [int #cols]" << endl;
		exit(1);
		break;

		case (3):
		cout << "Error 3: Rows/Columns must be >= 4" << endl;
		cout << "Please enter an integer >= 4" << endl;
		exit(1);
		break;

		case (4):
		cout << "Error 4: Numeric input must be integer"  << endl;
		cout << "None of this string or float or double (or whatever else you are throwing at me) business!" << endl;
		exit(1);
		break;
	}
}


void deleteTable(int **pArr)
{
	//deletion
	for (int i = 0; i < bigger; i++)
	{
		delete[] pArr[i];
	}
	delete[] pArr;
}

void deleteAll(int **pArr, int **pArr1)
{
	deleteTable(pArr);
	deleteTable(pArr1);
}

