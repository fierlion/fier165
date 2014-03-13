/********************************************************************
**Author: Ray Foote
**Date: Nov 11, 2013
**Description: This is a class of rational numbers with operator overloads
**in namespace::fierlion
**input: test program provided
**output: various calculations for all defined operators for each - and +  
*********************************************************************/

#include <iostream>
#include <stdlib.h>

using std::cout;
using std::cin;
using std::endl;
using std::ostream;
using std::istream;

namespace fierlion{
	class Rational
	{
	public:
		Rational();
		//initializes to numer = 0, denom = 1
		Rational(int wholeNum);
		//initializes to numer = wholeNum, denom = 1
		Rational(int numerator, int denominator);
		//numerator to numer, denominator to denom

		friend ostream &operator<<(ostream &out, Rational &fract);
		//overloaded << operator prints "numer/denom"
		friend istream &operator>>(istream &in, Rational &fract);
		//overloaded >> operator prommpts user to enter numerator, then denominator, 
		//storing each in the named Rational object 
		Rational &operator+=(const Rational &rhs);
		Rational &operator-=(const Rational &rhs);
		Rational &operator*=(const Rational &rhs);
		Rational &operator/=(const Rational &rhs);
		const Rational operator+(const Rational &other) const;
		const Rational operator-(const Rational &other) const;
		const Rational operator*(const Rational &other) const;
		const Rational operator/(const Rational &other) const;

		//The reduce() and negCorrect() work together to normalize the output and input.  recuce() should always come 
		//before negCorrect().
		void reduce();
		//reduces numer/denom of Rational object by factorinng out the greatest common factor between numer/denom
		void negCorrect();
		//sets negative and positive for Rational object as a whole.  If numer/denom are both positive or both negative
		//then each is set to positive.  If exclusive or denom/numer are positive/negative then it sets each to negative.
		
		bool negative(int intIn);
		//determines if int is negative.  Returns true if negative

	private:
		int numer;
		int denom;
	};

	Rational::Rational()
	{
		numer = 0;
		denom = 1;
	}
	Rational::Rational(int wholeNum)
	{
		numer = wholeNum;
		denom = 1;
		negCorrect();
	}
	Rational::Rational(int numerator, int denominator)
	{
		numer = numerator;
		denom = denominator;
		reduce();
		negCorrect();
	}

	ostream &operator<<(ostream &out, Rational &fract)
	{
		fract.negCorrect();
		out << fract.numer << "/" << fract.denom;
		return out;
	}
	istream &operator>>(istream &in, Rational &fract)
	{
		cout << "numerator: ";
		in >> fract.numer;
		cout << "denominator:";
		in >> fract.denom;
		fract.negCorrect();
		fract.reduce();
		return in;
	}
	Rational &Rational::operator+=(const Rational &rhs)
	{
		int lcm = denom * rhs.denom;
		numer = ((numer * rhs.denom) + (denom * rhs.numer));
		denom = lcm;
		return *this;
	}
	Rational &Rational::operator-=(const Rational &rhs)
	{
		int lcm = denom * rhs.denom;
		numer = ((numer * rhs.denom) - (denom * rhs.numer));
		denom = lcm;
		return *this;
	}
	Rational &Rational::operator*=(const Rational &rhs)
	{
		denom *= rhs.denom;
		numer *= rhs.numer;
		reduce();
		return *this;
	}
	Rational &Rational::operator/=(const Rational &rhs)
	{
		if (numer < 0)
		{
			numer *= -1;
			denom *= -1;
		}
		denom *= rhs.numer;
		numer *= rhs.denom;
		reduce();
		return *this;
	}
	const Rational Rational::operator+(const Rational &other) const
	{
		Rational result = *this;
		result += other;
		return result;
	}
	const Rational Rational::operator-(const Rational &other) const
	{
		Rational result = *this;
		result -= other;
		return result;
	}
	const Rational Rational::operator*(const Rational &other) const
	{
		Rational result = *this;
		result *= other;
		return result;
	}
	const Rational Rational::operator/(const Rational &other) const
	{
		Rational result = *this;
		result /= other;
		return result;
	}

	void Rational::reduce()
	{
		//10/50
		int least;
		int lcm = 1;
		if (numer == denom)
		{
			numer = lcm;
			denom = lcm;
		}
		else
		{
			int num = abs(numer);
			int den = abs(denom);
			(num < den) ? (least = num) : (least = den);
			for (int i = 2; i <= least; i++)
			{
				if ((num%i == 0) && (den %i == 0))
				{
					lcm = i;
				}
			}
			numer = numer / lcm;
			denom = denom / lcm;
		}
	}
	void Rational::negCorrect()
	{
		if ((negative(denom))&&(negative(numer)) || (!negative(denom))&&(!negative(numer)))
		{
			numer = abs(numer);
			denom = abs(denom);
		}
		else
		{
			numer = -1 * abs(numer);
			denom = abs(denom);
		}
	}
	bool Rational::negative(int intIn)
	{
		bool isNeg;
		(intIn < 0) ? (isNeg = true) : (isNeg = false);
		return isNeg;
	}
}
int main()
{
	fierlion::Rational F1, F2(2, -4);

	cout << "Enter fraction" << endl;
	cin >> F1;
	cout << "Fraction entered is: ";
	cout << F1 << endl;
	cout << F2 << endl;
	fierlion::Rational F3 = F1 + F2;
	cout << F1 << " + " << F2 << " = " << F3 << endl;
	F3 = F1 - F2;
	cout << F1 << " - " << F2 << " = " << F3 << endl;
	F3 = F1 * F2;
	cout << F1 << " * " << F2 << " = " << F3 << endl;
	F3 = F1 / F2;
	cout << F1 << " / " << F2 << " = " << F3 << endl;
	return 0;
}