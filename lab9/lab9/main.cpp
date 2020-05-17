#include <iostream>
#include "Vector.h"
#include "error.h"

using namespace std; // добавить исключения

void main()
{
	try
	{
		Vector vector(5); // создаем контейнер на 5 ед
		cin >> vector; // ввод
		cout << vector << endl;
		cout << vector[2] << endl; // вывод контейнера с индексом
		vector()();
		Vector vector1(0);
		vector1 = vector + 5; // + константа
		cout << vector1 << endl;
		Vector vector2(0);
		vector2 = vector1 - 2; // удаление елементов с конца
		cout << vector2;
		Vector vector3(-1);
		cout << vector[100] << endl;
		
	}

	catch (error e)
	{
		e.what();
	}

	
}