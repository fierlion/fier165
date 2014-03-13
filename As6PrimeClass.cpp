/********************************************************************
**Author: Ray Foote
**Date: Nov 11, 2013
**Description: This is a class of prime numbers with operators ++, --
**in namespace::fierlion
**input: test program provided
**output: prime number ++ will find next prime up, -- next prime down  
*********************************************************************/

#include <iostream>
#include <cmath>

using std::cout;
using std::cin;
using std::endl;

namespace fierlion{
	class PrimeNum
	{
	public:
		PrimeNum(int primeIn);
		//initializes to userInt if prime, or the next prime down if not
		PrimeNum();
		//initializes to '1'

		int getPrime();
		//returns prime number
		bool isPrime(int primeIn);
		//tests for prime
		PrimeNum operator ++();
		//finds next prime up
		PrimeNum operator --();
		//finds next prime down

	private:
		int prime;
	};


	PrimeNum::PrimeNum(int primeIn)
	{
		(isPrime(primeIn)) ? (prime = primeIn) : (prime = --primeIn);
	}
	PrimeNum::PrimeNum()
	{
		prime = 1;
	}

	int PrimeNum::getPrime()
	{
		return prime;
	}

	bool PrimeNum::isPrime(int primeIn)
	{
		int counter = primeIn - 1;
		while (counter > 2)
		{
			if (primeIn % counter == 0)
			{
				return false;
			}
			counter--;
		}
		return true;
	}

	PrimeNum PrimeNum::operator ++()
	{
		int next = prime + 1;
		while (!isPrime(next))
		{
			next++;
		}
		prime = next;
		return next;
	}

	PrimeNum PrimeNum::operator --()
	{
		int next = prime - 1;
		while (!isPrime(next))
		{
			next--;
		}
		prime = next;
		return next;
	}
}

int main()
{
	fierlion::PrimeNum prime1(8);
	fierlion::PrimeNum prime2(200);
	cout << prime1.getPrime() << endl;
	--prime1;
	cout << prime1.getPrime() << endl;
	++prime1;
	cout << prime1.getPrime() << endl;
	cout << prime2.getPrime() << endl;
	++prime2;
	cout << prime2.getPrime() << endl;
	++prime2;
	cout << prime2.getPrime() << endl;
	return 0;
}
