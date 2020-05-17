#include "Time.h"
#include <vector>
#include <cstdlib>
#include <iostream>

using namespace std;

typedef vector<Time> Vec;

Vec MakeVector(int n)
{
	Vec v;
	for (int i = 0; i < n; i++)
	{
		Time a(rand() % 10, rand() % 10);
		v.push_back(a);
	}
	return v;
}

void PrintVector(Vec v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

Time Max(Vec v)
{
	Time a = v[0];
	for (int i = 0; i < v.size(); i++)
	{
		if (a > v[i])
			a = v[i];
	}
	return a;
}

void AddToFirst(Vec& v, Time s)
{
	v.insert(v.begin(), s);
}

Time Min(Vec v)
{
	Time a = v[0];
	for (int i = 0; i < v.size(); i++)
	{
		if (a < v[i])
			a = v[i];
	}
	return a;
}

void DeleteTime(Vec& v, Time s)
{
	int n = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (s == v[i])
			break;
		n++;
	}
	v.erase(v.begin() + n);
}

Time Average(Vec v)
{
	Time temp;
	int min = 0;
	int sec = 0;
	int min_sec;
	for (int i = 0; i < v.size(); i++)
	{
		min += v[i].get_min();
		sec += v[i].get_sec();
	}
	min_sec = (min * 60 + sec) / 2;
	temp.set_min_sec(min_sec / 60, min_sec % 60);
	return temp;
}

void AddToAll(Vec& v, Time s)
{
	int min = s.get_min();
	int sec = s.get_sec();
	Time temp;
	for (int i = 0; i < v.size(); i++)
	{
		temp.set_min_sec(v[i].get_min() + min, v[i].get_sec() + sec);
		v[i] = temp;
	}
}

void main()
{
	int n;
	cout << "How many? >";
	cin >> n;
	Vec v = MakeVector(n);
	PrintVector(v);
	cout << "zadacha 3 \n Max element to first\n";
	AddToFirst(v, Max(v));
	PrintVector(v);
	cout << "zadacha 4\n min element delete\n";
	DeleteTime(v, Min(v));
	PrintVector(v);
	cout << "zadacha 5\n +Srednee to all \n";
	AddToAll(v, Average(v));
	PrintVector(v);
}