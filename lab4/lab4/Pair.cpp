#include "Pair.h"



Pair::Pair(void)
{
	first = 0;
	second = 0;
}


Pair::~Pair()
{
}

Pair::Pair(int F, int S)
{
	first = F;
	second = S;
}

Pair::Pair(const Pair& pair)
{
	first = pair.first;
	second = pair.second;
}

void Pair::Set_first(int F)
{
	first = F;
}

void Pair::Set_second(int S)
{
	second = S;
}

Pair& Pair::operator=(const Pair& c)
{
	if (&c == this)
	{
		return *this;
	}
	first = c.first;
	second = c.second;
	return *this;
}

bool Pair::operator>(const Pair& c)
{
	int temp1 = first + second;
	int temp2 = c.first + c.second;
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

bool Pair::operator<(const Pair& c)
{
	int temp1 = first + second;
	int temp2 = c.first + c.second;
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

bool Pair::operator==(const Pair& c)
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

istream& operator>>(istream& in, Pair& c)
{
	cout << "First: ";
	in >> c.first;
	cout << "\n Second: ";
	in >> c.second;
	return in;
}

ostream& operator<<(ostream& out, const Pair& c)
{
	out << " \n First : " << c.first;
	out << " \n Second : " << c.second << "\n";
	return out;
}
