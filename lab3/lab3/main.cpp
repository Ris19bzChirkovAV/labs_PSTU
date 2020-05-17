#include <iostream>
#include "Time.h"
#include <string>

using namespace std;

void main()
{
	setlocale(LC_ALL, "ru");
	Time first;
	Time second;
	Time third;
	cin >> second;
	third = second;
	first.set_min_sec(1213, 1410);
	cout << third << endl;
	cout << first + second << endl;
	if (first != second)
	{
		cout << " Не равны !" << endl;
	}
	else
	{
		cout << " Равны !" << endl;
	}
	cout << "First" << first << "\n" << "Second" << second << "\n" << "Third" << third << endl;
}