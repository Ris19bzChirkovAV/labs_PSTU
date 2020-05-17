#pragma once
#include <iostream>

using namespace std;

class Vector
{
public:
	Vector();
	Vector(int s);
	Vector(int s, int* mas);
	Vector(const Vector& v);
	~Vector();
	const Vector& operator =(const Vector& v);
	int operator [] (int i);
	Vector operator+ (int a);
	Vector operator- (int a);
	Vector operator() ();
	friend ostream& operator <<(ostream& out, const Vector& v);
	friend istream& operator >>(istream& in, Vector& v);
private:
	int size;
	int* beg;
};
