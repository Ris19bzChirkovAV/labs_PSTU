#include "student.h"

student::student()
{
	surname = " ";
	group = 0;
	GPA = 0;
	cout << "Вызвался конструктор без параметров! >> " << this << endl;
}

student::student(string valueSurname, int valueGroup, float valueGPA)
{
	surname = valueSurname;
	group = valueGroup;
	GPA = valueGPA;
	cout << "Вызвался конструктор с параметрами! >> " << this << endl;
}

student::student(const student& t)
{
	surname = t.surname;
	group = t.group;
	GPA = t.GPA;
	cout << " Вызвался конструктор копирования ! >> " << this << endl;
}

student::~student()
{
	cout << "Вызвался деструктор! >> " << this << endl;
}

string student::get_surname()
{
	return surname;
}

void student::set_surname(string valueSurname)
{
	surname = valueSurname;
}

int student::get_group()
{
	return group;
}

void student::set_group(int valueGroup)
{
	group = valueGroup;
}

float student::get_GPA()
{
	return GPA;
}

void student::set_GPA(float valueGPA)
{
	GPA = valueGPA;
}

void student::show()
{
	cout << "Фамилия = \t" << surname << endl;
	cout << "Группа = \t" << group << endl;
	cout << "Средний балл = \t" << GPA << endl << endl;
}




