#pragma once
#include <iostream>
#include <map>

using namespace std;

template<class T>

class Container
{
	map<int, T> v;
	map<int, T> temp;
	int len;
public:
	Container(void);
	Container(int n);
	void Print();
	~Container(void);
	void AddToFirst(T n);
	Time Max();
	Time Min();
	void DeleteMin(T n);
	Time Srd();
	void AddToAll(T n);
};

template<class T>
Container<T>::Container()
{
	len = 0;
}

template<class T>
Container<T>::Container(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v[i] = a;
	}
	len = v.size();
}

template<class T>
void Container<T>::Print()
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << i << " : " << v[i] << endl;
	}
	cout << endl;
}

template<class T>
Container<T>::~Container(void)
{
}

template <class T>
Time Container<T>::Max()
{
	map<int, Time>::iterator i = v.begin();
	int nom = 0;
	Time m = (*i).second;
	while (i != v.end())
	{
		if (m > (*i).second)
		{
			m = (*i).second;
		}
		i++;
	}
	return m;
}

template <class T>
Time Container<T>::Min()
{
	map<int, Time>::iterator i = v.begin();
	int nom = 0;
	Time m = (*i).second;
	while (i != v.end())
	{
		if (m < (*i).second)
		{
			m = (*i).second;
		}
		i++;
	}
	return m;
}

template <class T>
void Container<T>::AddToFirst(T n)
{
	for (int i = 0; i < v.size(); i++)
	{
		temp[i] = v[i];
	}
	v[0] = n;
	for (int i = 1; i < temp.size() + 1; i++)
	{
		v[i] = temp[i - 1];
	}
}

template <class T>
void Container<T>::DeleteMin(T n)
{
	for (int i = 0; i < v.size(); i++)
	{
		temp[i] = v[i];
	}
	v.clear();
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i] != n)
			v.insert(make_pair(i, temp[i]));
	}
}

template <class T>
Time Container<T>::Srd()
{
	Time te;
	int min = 0;
	int sec = 0;
	int min_sec;
	for (int i = 0; i < v.size(); i++)
	{
		min += v[i].get_min();
		sec += v[i].get_sec();
	}
	min_sec = (min * 60 + sec) / 2;
	te.set_min_sec(min_sec / 60, min_sec % 60);
	return te;
}

template <class T>
void Container<T>::AddToAll(T n)
{
	int min = n.get_min();
	int sec = n.get_sec();
	Time te;
	for (int i = 0; i < v.size(); i++)
	{
		te.set_min_sec(v[i].get_min() + min, v[i].get_sec() + sec);
		v[i] = te;
	}
}
