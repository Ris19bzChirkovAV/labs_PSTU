#include <C:\Users\Андрей\Desktop\Рис19семестр2\Информатика Основы Алгоритмизации Теории Алгоритмов\lab11proba2\lab11proba2\Time.h>
#include <stack>
#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

typedef stack<Time>St;
typedef vector<Time>Vec;

Time s;

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

St MakeStack(int n)
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

Time Srd(Vec v)
{
	Time s;
	int min = 0;
	int sec = 0;
	int min_sec;
	for (int i = 0; i < v.size(); i++)
	{
		min += v[i].get_min();
		sec += v[i].get_sec();
	}
	min_sec = (min * 60 + sec) / 2;
	s.set_min_sec(min_sec / 60, min_sec % 60);
	return s;
}

void Replace(Time & t)
{
	int min = t.get_min();
	int sec = t.get_sec();
	int min1 = s.get_min();
	int sec1 = s.get_sec();
	t.set_min_sec(min + min1, sec + sec1);
}

void main()
{
	int n;
	cout << "How much? >";
	cin >> n;
	St Stack;
	Vec Vector;
	Stack = MakeStack(n);
	PrintStack(Stack);
	cout << endl;
	Vec::iterator i;
	Vector = CopyStackToVector(Stack);
	i = min_element(Vector.begin(), Vector.end());
	cout << "Max = " << *(i) << endl;
	Time el;
	cout << "New element? >";
	cin >> el;
	cout << "Zamena max na tekyshee\n";
	replace(Vector.begin(), Vector.end(), *(i), el);
	Stack = CopyVectorToStack(Vector);
	PrintStack(Stack);
	cout << endl;
	Vector = CopyStackToVector(Stack);
	i = max_element(Vector.begin(), Vector.end());
	cout << "Delete minimal\n";
	remove(Vector.begin(), Vector.end(), *i);
	Vector.erase(Vector.end() - 1);
	Stack = CopyVectorToStack(Vector);
	PrintStack(Stack);
	cout << endl;
	Vector = CopyStackToVector(Stack);
	s = Srd(Vector);
	cout << "add average\n";
	for_each(Vector.begin(), Vector.end(), Replace);
	Stack = CopyVectorToStack(Vector);
	PrintStack(Stack);
}