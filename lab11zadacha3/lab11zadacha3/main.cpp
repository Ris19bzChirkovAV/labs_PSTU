#include <C:\Users\Андрей\Desktop\Рис19семестр2\Информатика Основы Алгоритмизации Теории Алгоритмов\lab11proba2\lab11proba2\Time.h>
#include <vector>
#include <iostream>
#include <cstdlib>
#include "Vector.h"

using namespace std;

void main()
{
	Vector<Time>Vec(5);
	Vec.Print();
	cout << "Zadacha 3, Add max to First\n";
	Vec.AddToFirst(Vec.Max());
	Vec.Print();
	cout << "Zadacha 4, delete min\n";
	Vec.Del(Vec.Min());
	Vec.Print();
	cout << "zadacha 5, Add to all srednee\n";
	Vec.AddToAll(Vec.Average());
	Vec.Print();
}