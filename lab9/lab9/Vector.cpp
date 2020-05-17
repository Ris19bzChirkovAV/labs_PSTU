#include "Vector.h"
#include "error.h"

Vector::Vector()
{
	size = 0;
	beg = 0;
}

Vector::Vector(int s)
{
	if (s < 0)
		throw error("Error! s < 0!");
	size = s;
	beg = new int[s];
	for (int i = 0; i < size; i++)
	{
		beg[i] = (rand() % 10);
	}
}

Vector::Vector(int s, int* mas)
{
	size = s;
	if (s < 0)
		throw error("s <=0!");
	beg = new int[size];
	for (int i = 0; i < size; i++)
	{
		beg[i] = mas[i];
	}
}

Vector::Vector(const Vector& v)
{
	size = v.size;
	beg = new int[size];
	for (int i = 0; i < size; i++)
	{
		beg[i] = v.beg[i];
	}
}

Vector::~Vector()
{
	if (beg != 0)
		delete[] beg;
}

const Vector& Vector::operator=(const Vector& v)
{
	if (this == &v)
		return *this;
	if (beg != 0)
		delete[] beg;
	size = v.size;
	beg = new int[size];
	for (int i = 0; i < size; i++)
	{
		beg[i] = v.beg[i];
	}
	return *this;
}

int Vector::operator[](int i)
{
	if (i < 0 || i >= size)
		throw error("Error! Fail index!");
	return beg[i];
}

Vector Vector::operator+(int a)
{
	for (int i = 0; i < size; i++)
	{
		beg[i] = beg[i] + a;
	}
	return *this;

}

Vector Vector::operator-(int a)
{
	Vector temp(size, beg);
	delete[] beg;
	size = size - a;
	beg = new int[size];
	for (int i = 0; i < size; i++)
	{
		beg[i] = temp.beg[i];
	}
	return *this;
}

Vector Vector::operator()()
{
	cout << "Vector = " << size << endl;
	return size;
}

ostream& operator<<(ostream& out, const Vector& v)
{
	if (v.size == 0)
		out << "Empty!" << endl;
	else
	{
		for (int i = 0; i < v.size; i++)
		{
			out << v.beg[i] << " " << endl;
		}
	}
	return out;
}

istream& operator>>(istream& in, Vector& v)
{
	for (int i = 0; i < v.size; i++)
	{
		cout << ">";
		in >> v.beg[i];
	}
	return in;
}
