#include <C:\Users\Андрей\Desktop\Рис19семестр2\Информатика Основы Алгоритмизации Теории Алгоритмов\lab11proba2\lab11proba2\Time.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

typedef vector<Time> TVector;
Time s;

TVector MakeVector(int n)
{
	Time a;
	TVector v;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	return v;
}

void PrintVector(TVector v)
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << endl;
}

struct GreaterS
{
	bool operator()(Time t)
	{
		if (t > s)
			return true;
		else
			return false;
	}
		
	
};

Time Srd(TVector v)
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

void Replace(Time& t)
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
	cout << "N? >";
	cin >> n;
	TVector v;
	v = MakeVector(n);
	PrintVector(v);
	TVector::iterator i;
	i = min_element(v.begin(), v.end());
	cout << "Max = " << *(i) << endl;
	Time el;
	cout << "New element? >";
	cin >> el;
	cout << "Zamena max na tekyshee\n";
	replace(v.begin(), v.end(), *(i), el);
	PrintVector(v);
	cout << endl;
	i = max_element(v.begin(), v.end());
	cout << "Delete minimal\n";
	remove(v.begin(), v.end(), *i);
	v.erase(v.end() - 1);
	PrintVector(v);
	cout << Srd(v) << endl;
	s = Srd(v);
	cout << "add average\n";
	for_each(v.begin(), v.end(), Replace);
	PrintVector(v);
}
