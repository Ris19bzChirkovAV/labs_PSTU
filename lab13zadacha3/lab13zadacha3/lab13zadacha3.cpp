#include <map>
#include <iostream>
#include <C:\Users\Андрей\Desktop\Рис19семестр2\Информатика Основы Алгоритмизации Теории Алгоритмов\lab11proba2\lab11proba2\Time.h>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

typedef map<int, Time> TMap;
typedef vector<Time> TVector;
//typedef TMap::iterator it;

Time s(0,0);

TVector CopyMapToVector(TMap s)
{
	TVector v;
	for (int i = 0; i < s.size(); i++)
	{
		v.push_back(s[i]);
	}
	s.clear();
	return v;
}

TMap CopyVectorToMap(TVector v)
{
	TMap s;
	for (int i = 0; i < v.size(); i++)
		s.insert(make_pair(i, v[i]));
	v.clear();
	return s;
}
TMap MakeMap(int n)
{
	TMap m;
	Time a;
	for (int i = 0; i < n; i++)
	{
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
	TVector::iterator i;
	int n;
	TVector Vector;
	cout << "How much? >";
	cin >> n;
	map<int, Time> Map = MakeMap(n);
	PrintMap(Map);
	cout << endl;
	/*Time as = Max(Map);
	Time el;
	cout << "New element? >";
	cin >> el;*/
	Vector = CopyMapToVector(Map);
	i = min_element(Vector.begin(), Vector.end());
	cout << "Max = " << *(i) << endl;
	Time el;
	cout << "New element? >";
	cin >> el;
	cout << "Zamena max na tekyshee\n";
	replace(Vector.begin(), Vector.end(), *(i), el);
	Map = CopyVectorToMap(Vector);
	PrintMap(Map);
	cout << endl;
	Vector = CopyMapToVector(Map);
	cout << "Delete minimal\n";
	i = max_element(Vector.begin(), Vector.end());
	remove(Vector.begin(), Vector.end(), *i);
	Vector.erase(Vector.end() - 1);
	Map = CopyVectorToMap(Vector);
	PrintMap(Map);
	cout << endl;
	Vector = CopyMapToVector(Map);
	s = Srd(Vector);
	cout << "add average\n";
	for_each(Vector.begin(), Vector.end(), Replace);
	Map = CopyVectorToMap(Vector);
	PrintMap(Map);
}