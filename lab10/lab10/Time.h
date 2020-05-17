#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Time
{
public:
	Time();
	Time(int, int);
	Time(const Time&);
	Time operator = (const Time&);
	Time operator + (Time& t);
	bool operator == (Time& t);
	bool operator != (Time& t);
	Time operator + (int k);
	friend ostream& operator << (ostream& out, const Time& p);
	friend istream& operator >> (istream& in, Time& p);
	friend fstream& operator >> (fstream& fin, Time& p);
	friend fstream& operator << (fstream& fout, const Time& p);
	~Time();
private:
	int First;
	int Second;
};