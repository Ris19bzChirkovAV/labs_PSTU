#pragma once
#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

template<class T>

class Vector
{
	vector<T> v;
	int Size;
public:
	Vector(void);
	Vector(int n);
	void Print();
	T Average();
	void AddToFirst(T el);
	~Vector(void);
	T Max();
	void Del(T s);
	T Min();
	void Division();
	void AddToAll(T s);
};

template <class T>
Vector<T>::Vector()
{
	Size = 0;
}

template<class T>
Vector<T>::~Vector(void)
{
}

template<class T>
T Vector<T>::Max()
{
	T m = v[0];
	for (int i = 0; i < v.size(); i++)
	{
		if (m > v[i])
			m = v[i];
	}
	return m;
}

template<class T>
void Vector<T>::Del(T s)
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

template<class T>
T Vector<T>::Min()
{
	T m = v[0];
	for (int i = 0; i < v.size(); i++)
	{
		if (m < v[i])
		{
			m = v[i];
		}
	}
	return m;
}

template<class T>
void Vector<T>::Division()
{
	int m = Min();
	T min = v[m];
	for (int i = 0; i < v.size(); i++)
	{
		v[i] = v[i] / min;
	}
}

template<class T>
Vector<T>::Vector(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	Size = v.size();
}

template<class T>
void Vector<T>::Print()
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}

template<class T>
T Vector<T>::Average()
{
	T temp;
	int min = 0;
	int sec = 0;
	int min_sec;
	int n = 0;
	for (int i = 0; i < v.size(); i++)
	{
		min += v[i].get_min();
		sec += v[i].get_sec();
		n++;
	}
	min_sec = (min * 60 + sec) / n;
	temp.set_min_sec(min_sec / 60, min_sec % 60);
	return temp;
}

template<class T>
void Vector<T>::AddToFirst(T el)
{
	v.insert(v.begin(), el);
}

template<class T>

void Vector<T>::AddToAll(T s)
{
	int min = s.get_min();
	int sec = s.get_sec();
	T temp;
	for (int i = 0; i < v.size(); i++)
	{
		temp.set_min_sec(v[i].get_min() + min, v[i].get_sec() + sec);
		v[i] = temp;
	}
}