#include "Time.h"

Time::Time(void)
{
	min = 0;
	sec = 0;
}

Time::Time(int M, int S)
{
	min = M;
	sec = S;
}

Time::Time(const Time& a)
{
	min = a.min;
	sec = a.sec;
}


Time& Time::operator=(const Time& a)
{
	min = a.min;
	sec = a.sec;
	return *this;
}

Time Time::operator+(Time k)
{
	int t = min * 60 + sec;
	int kt = k.min * 60 + k.sec;
	t += kt;
	Time temp(t / 60, t % 60);
	return temp;
}

Time Time::operator+(int k)
{
	Time temp(min + k, sec + k);
	return temp;

}

Time::~Time()
{
}

ostream& operator<<(ostream& out, const Time& a)
{
	int tempmin = a.min * 60 + a.sec;
	out << tempmin / 60 << " : " << tempmin % 60 << endl;
	return out;
}

istream& operator>>(istream& in, Time& t)
{
	cout << "\n min? ";
	in >> t.min;
	cout << "\n sec? ";
	in >> t.sec;
	return in;
}
