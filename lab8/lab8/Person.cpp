#include "Person.h"



Person::Person(void)
{
	Name = "";
	Age = 0;
}

Person::Person(string N, int A)
{
	Name = N;
	Age = A;
}


Person::~Person(void)
{
}

void Person::input()
{
	cout << "\n Name:";
	cin >> Name;
	cout << "\n Age: ";
	cin >> Age;
}

void Person::show()
{
	cout << "\n Name: \t" << Name << " Age: \t" << Age << endl;
}

Person::Person(const Person& c)
{
	Name = c.Name;
	Age = c.Age;
}

Person& Person::operator=(const Person& c)
{
	if (&c == this)
	{
		return *this;
	}
	Name = c.Name;
	Age = c.Age;
	return *this;

}

void Person::HandleEvent(const TEvent& e)
{
	if (e.what == evMessage)
	{
		switch (e.command)
		{
		case cmGet:
			cout << "Name = " << Name << endl;
			break;
		}
	}
}
