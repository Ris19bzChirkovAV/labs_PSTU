#include <C:\Users\Андрей\Desktop\Рис19семестр2\Информатика Основы Алгоритмизации Теории Алгоритмов\lab11proba2\lab11proba2\Time.h>
#include <stack>
#include <vector>
#include <iostream>

using namespace std;

typedef stack<Time>St;
typedef vector<Time>Vec;

St PrintStack(St& s)
{
	Vec v;
	while (!s.empty())
	{
		v.push_back(s.top());
		cout << s.top() << " ";
		s.pop();
	}
	for (int i = 0; i < v.size(); i++)
	{
		s.push(v[i]);
	}
	return s;
}

St make_stack(int n)
{
	St s;
	Time t;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		s.push(t);
	}
	return s;
}

Vec CopyStackToVector(St s)
{
	Vec v;
	while (!s.empty())
	{
		v.push_back(s.top());
		s.pop();
	}
	return v;
}

St CopyVectorToStack(Vec v)
{
	St s;
	for (int i = 0; i < v.size(); i++)
	{
		s.push(v[i]);
	}
	return s;
}

St MaxAddToFirst(St& s)
{
	Time m(0, 0);
	Vec v;
	while (!s.empty())
	{
		v.push_back(s.top());
		if (s.top() < m)
			m = s.top();
		s.pop();
	}
	s.push(m);
	for (int i = 0; i <v.size(); i++)
		s.push(v[i]);
	return s;
}

St DeleteMin(St& s)
{
	Time m(1000,1000);
	Vec v;
	while (!s.empty())
	{
		v.push_back(s.top());
		if (s.top() > m)
			m = s.top();
		s.pop();
	}
	for (int i = 0; i < v.size(); i++)
		if (v[i] != m)
			s.push(v[i]);
	return s;
}

St AddToAverage(St& s)
{
	Time temp;
	int min = 0;
	int sec = 0;
	int min_sec;
	Vec v;
	int n = 0;
	while (!s.empty())
	{
		v.push_back(s.top());
		s.pop();
	}
	for (int i = 0; i < v.size(); i++)
	{
		min += v[i].get_min();
		sec += v[i].get_sec();
		n++;
	}
	min = min / n;
	sec = sec / n;
	//temp.set_min_sec(min_sec / 60, min_sec % 60);
	for (int i = 0; i < v.size(); i++)
	{
		temp.set_min_sec(v[i].get_min() + min, v[i].get_sec() + sec);
		v[i] = temp;
		s.push(v[i]);
	}
	return s;
}

void main()
{
	Time t;
	St s;
	int n;
	cout << "N? >";
	cin >> n;
	s = make_stack(n);
	PrintStack(s);
	cout << endl;
	cout << "Zadacha 3, Add max to First\n";
	MaxAddToFirst(s);
	PrintStack(s);
	cout << endl;
	cout << "Zadacha 4, delete min\n";
	DeleteMin(s);
	PrintStack(s);
	cout << endl;
	cout << "zadacha 5, Add to all srednee\n";
	AddToAverage(s);
	PrintStack(s);
}