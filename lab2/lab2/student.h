#pragma once
#include <iostream>
#include <string>

using namespace std;

class student
{
private:
	string surname;
	int group;
	float GPA;
public:
	student();
	student(string, int, float);
	student(const student& t);
	~student();
	string get_surname();
	void set_surname(string);
	int get_group();
	void set_group(int);
	float get_GPA();
	void set_GPA(float);
	void show();
	
};