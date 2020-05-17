#include "Time.h"
#include <iostream>

Time& Time::operator=(const Time& t)
{
	min = sec / 60 + t.min;
	sec = t.sec % 60;
	cout << " Оператор присвоения !" << endl;
	return *this;
}

Time Time::operator+(const Time& t)
{
	int temp1 = min * 60 + sec;
	int temp2 = t.min * 60 + t.sec;
	Time p;
	p.min = (temp1 + temp2) / 60;
	p.sec = (temp1 + temp2) % 60;
	cout << " Оператор сложения!" << endl;;
	return p;
}

bool Time::operator!=(const Time& t)
{
	cout << " Оператор сравнения " << endl;
	int temp1 = min * 60 + sec;
	int temp2 = t.min * 60 + t.sec;
	if (temp1 != temp2)
	{
		return true;
	}
	return false;
}

istream& operator>>(istream& in, Time& t)
{
	cout << "Оператор ввода" << endl;
	cout << " min " << endl;
	in >> t.min;
	cout << " sec " << endl;
	in >> t.sec;
	return in;
}

ostream& operator<<(ostream& out, const Time& t)
{
	cout << " Оператор вывода ";
	return (out << t.min << " : " << t.sec);
}
