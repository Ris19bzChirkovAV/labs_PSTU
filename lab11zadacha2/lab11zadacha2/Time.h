#pragma once
#include <iostream>


using namespace std;

class Time
{
	int min;
	int sec;
public:
	Time() // конструктор без параметров
	{
		min = 0;
		sec = 0;
	}
	Time(int valueMin, int valueSec) // конструктор с параметрами
	{
		min = valueMin;
		sec = valueSec;
	}
	Time(const Time& t) // конструктор копирования
	{
		min = t.min;
		sec = t.sec;
	}
	~Time() // деструктор
	{}
	int get_min()
	{
		return min;
	}
	int get_sec()
	{
		return sec;
	}
	void set_min_sec(int m, int s) // сеттер выравнивает минуты, секунды
	{
		min = m + s / 60;
		sec = s % 60;
	}
	Time& operator = (const Time& t);
	Time& operator + (const Time& t);
	Time& operator / (const Time& t);
	Time& operator / (int t);
	Time& operator += (const Time& t);
	bool operator == (const Time& t);
	friend istream& operator >> (istream& in, Time& t);
	friend ostream& operator << (ostream& out, const Time& t);
	bool operator >(const Time& t);
	bool operator <(const Time& t);
};