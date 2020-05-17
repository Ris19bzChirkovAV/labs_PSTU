#include "Time.h"



Time::Time()
{
	First = 0;
	Second = 0;
}

Time::Time(int F, int S)
{
	int temp = F * 60 + S;
	First = temp / 60;
	Second = temp  % 60;
}

Time::Time(const Time& t)
{
	First = t.First;
	Second = t.Second;
}

Time Time::operator=(const Time& t)
{
	if (&t == this)
		return *this;
	First = t.First;
	Second = t.Second;
	return *this;
}

Time Time::operator+(Time& t)
{
	int temp2 = t.First * 60 + t.Second;
	int temp3 = First * 60 + Second + temp2;
	First = temp3 / 60;
	Second = temp3 % 60;
	return *this;
}

Time Time::operator + (int k)
{
	int temp6 = First * 60 + Second + k;
	First = temp6 / 60;
	Second = temp6 % 60;
	return *this;
}

bool Time::operator==(Time& t)
{
	int temp4 = First * 60 + Second;
	int temp5 = t.First * 60 + t.Second;
	if (temp4 == temp5)
		return true;
	return false;
}

bool Time::operator!=(Time& t)
{
	int temp4 = First * 60 + Second;
	int temp5 = t.First * 60 + t.Second;
	if (temp4 != temp5)
		return true;
	return false;
}

Time::~Time()
{
}

ostream& operator<<(ostream & out, const Time& p)
{
	out << "\n Time = " << p.First << ":" << p.Second << "\n";
	return out;
}

istream& operator>>(istream & in, Time& p)
{
	int tempFirst;
	int tempSecond;
	cout << "First \n";
	in >> tempFirst;
	cout << "Second \n";
	in >> tempSecond;
	int temp1 = tempFirst * 60 + tempSecond;
	p.First = temp1 / 60;
	p.Second = temp1 % 60;
	return in;

}

fstream& operator>>(fstream & fin, Time& p)
{
	fin >> p.First;
	fin >> p.Second;
	return fin;
}

fstream& operator<<(fstream & fout, const Time & p)
{
	fout << p.First << "\n" << p.Second;
	return fout;
}