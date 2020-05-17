#pragma once
#include <iostream>

using namespace std;

class Iterator
{
	friend class Vector;
public:
	Iterator()
	{
		elem = 0;
	}
	Iterator(const Iterator& t)
	{
		elem = t.elem;
	}
	bool operator == (const Iterator &it)
	{
		return elem == it.elem;
	}
	bool operator != (const Iterator& it)
	{
		return elem != it.elem;
	}
	void operator ++ (int)
	{
		++elem;
	};
	void operator -- (int)
	{
		--elem;
	};
	int& operator * () const
	{
		return*elem;
	}
private:
	int* elem;
};
class Vector
{
public:
	Vector(int s, int k = 0);
	Vector(const Vector&);
	~Vector();
	Vector& operator = (const Vector&);
	int& operator[] (int index);
	Vector operator + (const int k);
	int operator()();
	friend istream& operator >> (istream& in, Vector& a);
	friend ostream& operator << (ostream& out, const Vector& a);
	Iterator first()
	{
		return beg;
	}
	Iterator last()
	{
		return end;
	}
private:
	int size;
	int* data;
	Iterator beg;
	Iterator end;
};

