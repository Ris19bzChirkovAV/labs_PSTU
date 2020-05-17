#include "Vector.h"
#include "Student.h"
#include <iostream>

using namespace std;

Vector::Vector()
{
}

Vector::Vector(int n)
{
	beg = new Object * [n];
	cur = 0;
	size = n;
}


Vector::~Vector(void)
{
	if (beg != 0)
	{
		delete[] beg;
	}
	beg = 0;
}

void Vector::Add()
{
	Object* p;
	cout << "Student: " << endl;
	Student* a = new Student;
	a->input();
	p = a;
	if (cur < size)
	{
		beg[cur] = p;
		cur++;
	}
	else
		return;

}

void Vector::Del()
{
	if (cur == 0)
		return;
	cur--;
}

void Vector::show()
{
	if (cur == 0)
		cout << " Empty! " << endl;
	Object** p = beg;
	for (int i = 0; i < cur; i++)
	{
		(*p)->show();
		p++;
	}
}

void Vector::show(int n)
{
	if (cur == 0)
		cout << " Empty! " << endl;
	Object** p = beg;
	for (int i = 0; i < cur; i++)
	{
		if (n == i)
		{
			(*p)->show();
		}
		p++;
	}
}

void Vector::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		Object** p = beg;
		for (int i = 0; i < cur; i++)
		{
			(*p)->HandleEvent(e);
			p++;
		}
	}
}
