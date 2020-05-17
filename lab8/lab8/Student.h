#pragma once
#include "Person.h"
#include <iostream>

using namespace std;

class Student :
	public Person
{
public:
	Student(void);
	Student(string,int,float);
	void input();
	void show();
	Student(const Student& c);
	~Student(void);
	Student& operator = (const Student& c);
private:
	int Rate;
};

