#include "Student.h"



Student::Student(void) :Person()
{
	Rate = 0;
}

Student::Student(string N, int A, float R):Person(N, A)
{
	Rate = R;
}

Student::Student(const Student& c)
{
	Rate = c.Rate;
}

void Student::input()
{
	cout << "\n Name:";
    cin >> Name;
	cout << "\n Age:";
	cin >> Age;
	cout << "\n Rate:";
	cin >> Rate;
	
}

void Student::show()
{
	cout << "\n Name: \t" << Name << " Age: \t" << Age << " Rate: \t" << Rate << endl;
}

Student::~Student(void)
{
}

Student& Student::operator=(const Student& c)
{
	if (&c == this)
	{
		return *this;
	}
	Rate = c.Rate;
	return* this;
}
