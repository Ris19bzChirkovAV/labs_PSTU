#pragma once
#include <iostream>
#include "Object.h"
#include "Event.h"

using namespace std;

class Person:
	public Object
{
public:
	Person(void);
	Person(string, int);
	virtual ~Person(void);
	void input();
	void show();
	Person(const Person& c);
	Person& operator = (const Person& c);
	void HandleEvent(const TEvent& e);
protected:
	string Name;
	int Age;
};

