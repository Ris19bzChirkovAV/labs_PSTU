#include <iostream>
#include <string>
#include "student.h"

using namespace std;

student make_student()
{
	string valueSurname;
	int valusGroup;
	float valueGPA;
	cout << "Введите Фамилию студента" << endl;
	cin >> valueSurname;
	cout << " Введите номер группы" << endl;
	cin >> valusGroup;
	cout << " Введите средний балл " << endl;
	cin >> valueGPA;
	student t(valueSurname, valusGroup, valueGPA);
	return t;
}

void main_show(student valueS)
{
	valueS.show();
}



void main()
{
	setlocale(LC_ALL, "ru");
	student s1 = make_student();
	student s2 = s1;
	student s3;
	s3.set_surname("Петров");
	s3.set_group(5);
	s3.set_GPA(3.7);
	s1.show();
	s2.show();
	main_show(s3);
}
