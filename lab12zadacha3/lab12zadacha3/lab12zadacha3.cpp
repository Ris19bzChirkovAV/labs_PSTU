#include <map>
#include <iostream>
#include <C:\Users\Андрей\Desktop\Рис19семестр2\Информатика Основы Алгоритмизации Теории Алгоритмов\lab11proba2\lab11proba2\Time.h>
#include "Container.h"

using namespace std;

void main()
{
	int n;
	cout << "N? >";
	cin >> n;
	Container <Time> v(n);
	Container <Time> temp(0);
	v.Print();
	cout << endl;
	cout << "Zadacha 3, Add max to First\n";
	v.AddToFirst(v.Max());
	v.Print();
	cout << endl;
	cout << "Zadacha 4, delete min\n";
	v.DeleteMin(v.Min());
	v.Print();
	cout << endl;
	cout << "zadacha 5, Add to all srednee\n";
	v.AddToAll(v.Srd());
	v.Print();

}