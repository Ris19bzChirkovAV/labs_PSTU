#pragma once
#include <iostream>
#include <vector>
#include <stack>

template <class T>

class Vector
{
	stack <T> s;
	int len;
public:
	Vector();
	Vector(int n);
	Vector(const Vector<T>& t);
	void Print();
	T Max();
	T Min();
	T Average();
	void AddToAll(T t);
	void AddToFirst(T t);
	void DeleteMin(T t);
};

template<class T>
vector<T> CopyStackToVector(stack<T> s)
{
	vector<T> v;
	while (!s.empty())
	{
		v.push_back(s.top());
		s.pop();
	}
	return v;
};

template<class T>
stack<T> CopyVectorToStack(vector<T> v)
{
	stack<T> s;
	for (int i = 0; i < v.size(); i++)
	{
		s.push(v[i]);
	}
	return s;
};

template<class T>
Vector<T>::Vector(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		s.push(a);
	}
	len = s.size();
};

template<class T>
Vector<T>::Vector()
{
	len = 0;
};

template<class T>
Vector<T>::Vector(const Vector<T>& t)
{
	len = t.size();
	vector v = CopyStackToVector(t.s);
	s = CopyVectorToStack(t.v);
};

template<class T>
void Vector<T>::Print()
{
	vector<T> v = CopyStackToVector(s);
	while (!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}
	s = CopyVectorToStack(v);
};

template<class T>
T Vector<T>::Max()
{
	T m = s.top();
	vector<T> v = CopyStackToVector(s);
	while (!s.empty())
	{
		if (s.top() < m)
			m = s.top();
		s.pop();
	}
	s = CopyVectorToStack(v);
	return m;
};

template<class T>
T Vector<T>::Min()
{
	T m = s.top();
	vector<T> v = CopyStackToVector(s);
	while (!s.empty())
	{
		if (s.top() > m)
			m = s.top();
		s.pop();
	}
	s = CopyVectorToStack(v);
	return m;
};

template<class T>
void Vector<T>::AddToFirst(T t)
{
	vector<T> v = CopyStackToVector(s);
	v.insert(v.begin(), t);
	s = CopyVectorToStack(v);
};

template<class T>
void Vector<T>::DeleteMin(T t)
{
	vector<T> v = CopyStackToVector(s);
	int n = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (t == v[i])
			break;
		n++;
	}
	v.erase(v.begin() + n);
	s = CopyVectorToStack(v);
}

template<class T>
T Vector<T>::Average()
{
	vector<T> v = CopyStackToVector(s);
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
	s = CopyVectorToStack(v);
	return temp;
}

template<class T>
void Vector<T>::AddToAll(T t)
{
	vector<T> v = CopyStackToVector(s);
	int min = t.get_min();
	int sec = t.get_sec();
	T temp;
	for (int i = 0; i < v.size(); i++)
	{
		temp.set_min_sec(v[i].get_min() + min, v[i].get_sec() + sec);
		v[i] = temp;
	}
	s = CopyVectorToStack(v);
}