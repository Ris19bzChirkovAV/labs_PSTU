#include <map>
#include <iostream>

using namespace std;

typedef map<int, double>TMap;
typedef TMap::iterator it;

TMap MakeMap(double n)
{
	TMap m;
	int a;
	for (int i = 0; i < n; i++)
	{
		cout << "? \n";
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

int Srd(TMap v)
{
	int s = 0;
	for (int i = 0; i < v.size(); i++)
		s += v[i];
	int n = v.size();
	return s / n;
}

int Max(TMap v)
{
	it i = v.begin();
	int nom = 0;
	int k = 0;
	int m = (*i).second;
	while (i != v.end())
	{
		if (m < (*i).second)
		{
			m = (*i).second;
			nom = k;
		}
		i++;
		k++;
	}
	return m;
}

void AddToFirst(TMap &v)
{
	double n = Max(v);
	TMap temp = v;
	v.clear();
	v.insert(make_pair(0, n));
	for (int i = 1; i < temp.size() + 1; i++)
		v.insert(make_pair(i, temp[i - 1]));
}



int Min(TMap v)
{
	it i = v.begin();
	int nom = 0;
	int k = 0;
	int m = (*i).second;
	while (i != v.end())
	{
		if (m > (*i).second)
		{
			m = (*i).second;
			nom = k;
		}
		i++;
		k++;
	}
	return nom;
}

void DeleteMin(TMap& v)
{
	v.erase(Min(v));
}

void AddToAll(TMap& v)
{
	for (int i = 0; i < v.size(); i++)
	{
		v[i] = v[i] + Srd(v);
	}
}

void main()
{
	int n;
	cout << "Kol-vo? >";
	cin >> n;
	TMap m = MakeMap(n);
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
	AddToAll(m);
	PrintMap(m);
}