#pragma once
#include "Time.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int MakeFile(const char* f_name)
{
	fstream stream(f_name, ios::out | ios::trunc);
	if (!stream)
		return -1;
	int n;
	int l = 0;
	Time t;
	cout << "How many? \n";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		stream << t << "\n";
		l++;
	}
	stream.close();
	return l;
}

int PrintFile(const char* F_name)
{
	fstream stream(F_name, ios::in);
	if (!stream)
		return -1;
	Time p;
	int i = 0;
	while (stream >> p)
	{
		if (stream.eof())
			break;
		cout << p << "\n";
		i++;
	}
	stream.close();
	return i;
}

int DeleteValue(const char* f_name, Time k)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream)
		return -1;
	Time t;
	int i = 0;
	while (stream >> t)
	{
		if (stream.eof())
			break;
		if (t != k)
		{
			temp << t << "\n";
			i++;
		}
	}
	stream.close();
	temp.close();
	remove(f_name);
	if (rename("temp", f_name) == 0)
		return i;
	return i;
}

int AddEnd(const char* f_name, int k)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream)
		return -1;
	Time p;
	int l = 0;
	while (stream >> p)
	{
		if (stream.eof())
			break;
		temp << p << "\n";
		l++;
	}
	for (int i = 0; i < k; i++)
	{
		cin >> p;
		temp << p << "\n";
		l++;
	}
	stream.close();
	temp.close();
	remove(f_name);
	if (rename("temp", f_name) == 0)
		return l;
	return l;
}

int IncreaseValue(const char* f_name, int k)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream)
		return -1;
	Time t;
	Time t1;
	int i = 0;
	while (stream >> t)
	{
		if (stream.eof())
			break;
		t1 = t + k;
		temp << t1 << "\n";
		i++;
	}
	stream.close();
	temp.close();
	remove(f_name);
	if (rename("temp", f_name) == 0)
		return i;
	return i;

}