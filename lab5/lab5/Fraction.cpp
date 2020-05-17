#include "Fraction.h"



Fraction::Fraction(void) :Pair()
{
	first = 0;
	second = 0;
}


Fraction::~Fraction(void)
{
}

void Fraction::show()
{
	cout << "\n First : " << first;
	cout << "\n Second : " << second << "\n";
}

Fraction::Fraction(float F, float S) : Pair(F, S)
{
	first = F;
	second = S;
}

Fraction::Fraction(const Fraction& F)
{
	first = F.first;
	second = F.second;
}

void Fraction::Set_first(float F)
{
	first = F;
}

void Fraction::Set_second(float S)
{
	second = S;
}

Fraction& Fraction::operator=(const Fraction& F)
{
	if (&F == this)
	{
		return *this;
	}
	first = F.first;
	second = F.second;
	return *this;
}

bool Fraction::operator>(const Fraction& c)
{
	float temp1 = first + second;
	float temp2 = c.first + c.second;
	if (temp1 > temp2)
	{
		cout << "Первая пара больше!" << endl;
		return true;
	}
	else
	{
		return false;
	}
}

bool Fraction::operator<(const Fraction& c)
{
	float temp1 = first + second;
	float temp2 = c.first + c.second;
	if (temp1 < temp2)
	{
		cout << "Вторая пара больше!" << endl;
		return true;
	}
	else
	{
		return false;
	}
}

bool Fraction::operator==(const Fraction& c)
{
	if (first == c.first && second == c.second)
	{
		cout << "Пары равны!" << endl;
		return true;
	}
	else
	{
		return false;
	}
}

istream& operator>>(istream& in, Fraction& c)
{
	cout << "First Fraction: ";
	in >> c.first;
	cout << "\n Second Fraction: ";
	in >> c.second;
	return in;
}

ostream& operator<<(ostream& out, const Fraction& c)
{
	out << " \n Fraction First : " << c.first;
	out << " \n Fraction Second : " << c.second << "\n";
	return out;
}