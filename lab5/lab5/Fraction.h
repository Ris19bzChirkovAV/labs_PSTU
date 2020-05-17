#pragma once
#include "Pair.h"
class Fraction :
	public Pair
{
public:
	Fraction(void);
public:
	~Fraction(void);
	Fraction(float, float);
	Fraction(const Fraction&);
	void show();
	float Get_first()
	{
		return first;
	}
	float Get_second()
	{
		return second;
	}
	void Set_first(float);
	void Set_second(float);
	Fraction& operator= (const Fraction&);
	bool operator> (const Fraction&);
	bool operator< (const Fraction&);
	bool operator== (const Fraction&);
	friend istream& operator >> (istream& in, Fraction& c);
	friend ostream& operator << (ostream& out, const Fraction& c);
protected:
	float first;
	float second;

};