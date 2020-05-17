#include <map>
#include <iostream>
#include <C:\Users\Андрей\Desktop\Рис19семестр2\Информатика Основы Алгоритмизации Теории Алгоритмов\lab11proba2\lab11proba2\Time.h>

using namespace std;

typedef map<int, Time> TMap;
typedef TMap::iterator it;

TMap MakeMap(int n)
{
	TMap m;
	Time a;
	for (int i = 0; i < n; i++)
	{
		//cout << "? \n";
		cin >> a;
		m.insert(make_pair(i, a));
	}
	return m;
}

void PrintMap(TMap m)
{
	for (int i = 0; i < m.size(); i++)
	{
		cout << i << ": " << m[i] << " \n";
	}

}


Time Max(TMap v)
{
	Time a = v[0];
	for (int i = 0; i < v.size(); i++)
	{
		if (a > v[i])
			a = v[i];
	}
	return a;
}

void AddToFirst(TMap& v)
{
	Time n = Max(v);
	TMap temp = v;
	v.clear();
	v.insert(make_pair(0, n));
	for (int i = 1; i < temp.size() + 1; i++)
		v.insert(make_pair(i, temp[i - 1]));
}

Time Min(TMap v)
{
	Time a = v[0];
	for (int i = 0; i < v.size(); i++)
	{
		if (a < v[i])
			a = v[i];
	}
	return a;
}

void DeleteMin(TMap& v)
{
	Time n = Min(v);
	TMap temp = v;
	v.clear();
	for (int i = 0; i < temp.size(); i++)
		if (temp[i] != n)
			v.insert(make_pair(i, temp[i]));
}

Time Srd(TMap v)
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

void AddToAll(TMap& v, Time s)
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
	cout << "N? >";
	cin >> n;
	map<int, Time> m = MakeMap(n);
	PrintMap(m);
	cout << endl;
	cout << "Zadacha 3, Add max to First\n";
	AddToFirst(m);
	PrintMap(m);
	cout << endl;
	cout << "Zadacha 4, delete min\n";
	DeleteMin(m);
	PrintMap(m);
	cout << endl;
	cout << "zadacha 5, Add to all srednee\n";
	AddToAll(m, Srd(m));
	PrintMap(m);
	cout << endl;
}
