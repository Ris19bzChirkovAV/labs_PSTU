#pragma once
#include <iostream>

using namespace std;

class Time
{
public:
	Time(void);
	Time(int, int);
	Time(const Time&);
	Time& operator = (const Time& a);
	Time operator + (Time k);
	Time operator + (int k);
	virtual ~Time(void);
	friend ostream& operator << (ostream& out, const Time& a);
	friend istream& operator >> (istream& in, Time& t);
private:
	int min;
	int sec;
};

