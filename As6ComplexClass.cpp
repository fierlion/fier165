/********************************************************************
**Author: Ray Foote
**Date: Nov 11, 2013
**Description: This is a class of complex numbers with operator overloads
**in namespace::fierlion (similar to rationalClass)
**input: test program provided
**output: various calculations for all defined operators for each - and +  
*********************************************************************/

#include <iostream>
#include <math.h>

using std::cout;
using std::cin;
using std::endl;
using std::istream;
using std::ostream;

namespace fierlion{
	class Complex
	{
	public:
		Complex(double realin, double imaginein);
		//initializes real to realin and imagine to imaginein
		Complex(double realin);
		//initializes real to realin and imagine to 0.0
		Complex();
		//initializes both real and imaginary to 0.0

		void input();
		void output() const;
		double getReal() const;
		double getImagine() const;
		void setReal(double realin);
		void setImagine(double imgainein);

		//operator overloads
		Complex & operator+=(const Complex &rhs);
		Complex & operator-=(const Complex &rhs);
		Complex & operator*=(const Complex &rhs);
		Complex & operator/=(const Complex &rhs);

		const Complex operator+(const Complex &other) const;
		const Complex operator-(const Complex &other) const;
		const Complex operator*(const Complex &other) const;
		const Complex operator/(const Complex &other) const;

		friend ostream &operator<<(ostream &out, Complex &comp);
		//overloaded << operator prints "numer/denom"
		friend istream &operator>>(istream &in, Complex &comp);
		//overloaded >> operator prommpts user to enter real number, then imaginary number, 

		Complex conjugate();
		//returns conujugate form of complex...(destructive)
		double abs();
		//returns sqrt(this->norm())
		double norm();
		//returns the conjugate of this-> complex number, (ie 5+3i becomes 5+(-3i))

	private:
		double real;
		double imagine;
	};

	Complex::Complex(double realin, double imaginein)
		: real(realin), imagine(imaginein)
	{}
	Complex::Complex(double realin)
		: real(realin), imagine(0.0)
	{}
	Complex::Complex()
		: real(0.0), imagine(0.0)
	{}

	void Complex::input()
	{
		double realin, imaginein;
		cout << "Enter number, real part: ";
		cin >> realin;
		cout << "Enter number, imaginary part: ";
		cin >> imaginein;
		setReal(realin);
		setImagine(imaginein);
	}
	void Complex::output() const
	{
		if (imagine >= 0)
		{
			cout << real << "+" << imagine << "i" << endl;
		}
		else
		{
			cout << real << "-" << imagine * -1 << "i" << endl;
		}
	}
	void Complex::setReal(double realin)
	{
		real = realin;
	}
	void Complex::setImagine(double imaginein)
	{
		imagine = imaginein;
	}
	double Complex::getReal() const
	{
		return real;
	}
	double Complex::getImagine() const
	{
		return imagine;
	}

	Complex & Complex::operator+=(const Complex &rhs)
	{
		real += rhs.real;
		imagine += rhs.imagine;
		return *this;
	}

	Complex & Complex::operator-=(const Complex &rhs)
	{
		real -= rhs.real;
		imagine -= rhs.imagine;
		return *this;
	}

	Complex & Complex::operator*=(const Complex &rhs)
	{
		//(a+bi)(c+di) --> (ac-bd) + (ad+bc)i
		Complex holden;
		holden.setReal((real * rhs.real) - (imagine * rhs.imagine));
		holden.setImagine((real * rhs.imagine) + (rhs.real * imagine));
		real = holden.real;
		imagine = holden.imagine;
		return *this;
	}

	Complex & Complex::operator/=(const Complex &rhs)
	{
		//multiply top/bottom by conjugate
		Complex holden;
		double divisor = (rhs.real*rhs.real) + (rhs.imagine*rhs.imagine);
		double conj = rhs.imagine*-1;
		holden.setReal(((real * rhs.real) - (imagine * conj)) / divisor);
		holden.setImagine(((real * conj) + (rhs.real * imagine)) / divisor);
		real = holden.real;
		imagine = holden.imagine;
		return *this;
	}

	const Complex Complex::operator+(const Complex &other) const
	{
		Complex result = *this;
		result += other;
		return result;
	}
	const Complex Complex::operator-(const Complex &other) const
	{
		Complex result = *this;
		result -= other;
		return result;
	}
	const Complex Complex::operator*(const Complex &other) const
	{
		Complex result = *this;
		result *= other;
		return result;
	}
	const Complex Complex::operator/(const Complex &other) const
	{
		Complex result = *this;
		result /= other;
		return result;
	}

	ostream &operator<<(ostream &out, Complex &comp)
	{
		if (comp.imagine >= 0)
		{
			out << comp.real << "+" << comp.imagine << "i" << endl;
		}
		else
		{
			out << comp.real << "-" << comp.imagine * -1 << "i" << endl;
		}
		return out;
	}

	istream &operator>>(istream &in, Complex &comp)
	{
		cout << "Enter number, real part: ";
		in >> comp.real;
		cout << "Enter number, imaginary part:";
		in >> comp.imagine;
		return in;
	}

	Complex Complex::conjugate()
	{
		imagine *= -1;
		return *this;
	}

	double Complex::abs()
	{
		double absolut;
		absolut = sqrt(this->norm());
		return absolut;
	}

	double Complex::norm()
	{
		double normal;
		normal = (real*real) + (imagine*imagine);
		return normal;
	}
}

int main()
{
	fierlion::Complex C1(-2, -2), C2(3, -4), C3;
	double real, imag, absolut;
	/*C1.output();
	absolut = C1.abs();
	cout << absolut << endl;
	C2.output();
	cout << endl;
	C1 /= C2;
	C1.output();
	C2.output();
	*/
	cin >> C3;
	cout << C3;
	C3 = C1 + C2;
	C1.output();
	C2.output();
	C3.output();
	cout << endl;
	real = C1.getReal();
	imag = C2.getImagine();
	cout << real << " " << imag << endl;

	return 0;
}