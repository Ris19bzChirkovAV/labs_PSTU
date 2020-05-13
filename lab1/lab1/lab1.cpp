#include <iostream>
#include "Fractional_Part.h"

using namespace std;

fractional MakeFraction(int first, int second)
{
	fractional temp;
	temp.init(first, second);
	temp.show();
	return temp;
}

int main()
{
	setlocale(LC_ALL, "rus");
	fractional trial;
	int first;
	int second;
	cout << "Введите числитель" << endl;
	cin >> first;
	cout << "Введите знаменатель" << endl;
	cin >> second;
	if (second <= 0 || first <= 0) 
	{
		cout << " Введите целое положительное число! " << endl << endl;
		return main();
	}
	trial.init(first, second); // метод инициализации 
	trial.show(); // вывод на экран
	trial.ipart(); // метод деления без остатка
	MakeFraction(5, 10);

	return 0;
}