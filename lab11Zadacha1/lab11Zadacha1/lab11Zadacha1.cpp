#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

typedef vector<double>Vec;

Vec MakeVector(int n)
{
	Vec v;
	for (int i = 0; i < n; i++)
	{
		double a = rand() % 10;
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

int Max(Vec v)
{
	double max = v[0];
	for (int i = 0; i < v.size(); i++)
	{
		if (max < v[i])
			max = v[i];
	}
	return max;
}

int Min(Vec v)
{
	double min = v[0];
	int n = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (min > v[i])
		{
			min = v[i];
			n = i;
		}
			
	}
	return n;
}

void AddToFirst(Vec &v, double s)
{
	v.insert(v.begin(), s);
}

void DeleteMin(Vec &v, int pos)
{
	v.erase(v.begin() + pos);
}

double Average(Vec v)
{
	double Srd = 0;
	for (int i = 0; i < v.size(); i++)
	{
		Srd += v[i];
	}
	return Srd / v.size();
}

void AddToAll(Vec& v, double srd)
{
	for (int i = 0; i < v.size(); i++)
	{
		v[i] = v[i] + srd;
	}
}

void main()
{
	vector<double> v;
	int n;
	cout << "How many? >";
	cin >> n;
	v = MakeVector(n);
	PrintVector(v);
	cout << "zadacha 3 \n Max element to first\n";
	AddToFirst(v, Max(v)); //zadacha 3
	PrintVector(v);
	cout << "zadacha 4 \n Min element delete\n";
	DeleteMin(v, Min(v)); // zadacha 4
	PrintVector(v);
	cout << "zadacha 5 \n Add to all elemenst const\n";
	AddToAll(v, Average(v)); //zadacha 5
	PrintVector(v);

}