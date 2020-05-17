#include <iostream>
#include <map>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <stack>

using namespace std;

typedef map<int, int>TMap;
typedef vector<int>TVector;
typedef stack<TMap> TStack;

TVector Vector;
TStack Stack;

TStack MakeStack(TMap Map)
{
	Stack.push(Map);
	return Stack;
}

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

void MakePair(TMap &Map)
{
	for (int i = 1; i < 32; i++)
		Map.insert(make_pair(i, 0));
}

TMap PrintPair(TMap &Map)
{
	TVector::iterator i;
	cout << "Средняя температура за апрель\n";
	for (int i = 1; i < Map.size(); i++)
		cout << i << ".04 = " << Map[i] << "\n";
	Vector = CopyMapToVector(Map);
	i = max_element(Vector.begin(), Vector.end());
	cout << "Пик температуры: " << *i << endl;
	Map = CopyVectorToMap(Vector);
	int sum = 0;
	int k = 0;
	for (int i = 1; i < Map.size(); i++)
	{
		if (Map[i] < 0)
		{
			sum++;
			if (k < sum)
				k = sum;
		}
		else
			sum = 0;
	}
	cout << "Максимальное количество дней с температурой ниже нуля: " << k << endl;
	return Map;
}

void PairAdd(TMap &Map, int day, int value)
{
	for (int i = 1; i < Map.size(); i++)
	{
		if (i == day)
			Map[i] = value;
	}
}

void DeleteOfDay(TMap &Map, int day)
{
	for (int i = 1; i < Map.size(); i++)
	{
		if (i == day)
			Map[i] = 0;
	}
}

int DeleteOfValue(TMap &Map, int value)
{
	int num = 0;
	for (int i = 1; i < Map.size(); i++)
	{
		if (Map[i] == value)
		{
			num = i;
			Map[i] = 0;
			break;
		}
			
	}
	return num;
}

void ostreamFile(TMap Map)
{
	ofstream stream;
	stream.open("File1.txt", ios_base::trunc);
	if (!stream)
	{
		cout << "Error! file is not open!";
	}
	for (int i = 0; i < Map.size(); i++)
	{
		stream << i << " " << Map[i] << endl;
	}
	stream.close();
}

TMap istreamFile(TMap &Map)
{
	Map.clear();
	ifstream stream;
	int a[30][30];
	stream.open("File1.txt");
	if (!stream)
	{
		cout << "Error! file is not open!";
	}
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			stream >> a[i][j];
			if (j == 1)
				Map.insert(make_pair(i, a[i][j]));
		}
	}
	stream.close();
	return Map;
}

void SaveLast(TMap &Map, TStack Stack, int SaveDay)
{
	TMap map1 = Stack.top();
	for (int i = 1; i < Map.size(); i++)
	{
		if (SaveDay == i)
			Map[i] = map1[i];
	}
		

}

void main()
{
	setlocale(LC_ALL, "ru");
	TMap Map;
	int choose;
	cout << "1. Создать новый файл \n";
	cout << "2. Использовать имеющийся \n";
	cin >> choose;
	if (choose == 1)
		MakePair(Map);
	if (choose == 2)
		istreamFile(Map);
	int day;
	int value;
	int c;
	TMap tempMap;
	int SaveDay = 0;

	do
	{
		cout << "1.Добавить элемент" << endl;
		cout << "2.Удалить по дню" << endl;
		cout << "3.Удалить по значению" << endl;
		cout << "4.Вывод на экран" << endl;
		cout << "5.Сохранить в файл" << endl;
		cout << "6.Отмена последней операции" << endl;
		cout << "0.Выход" << endl;
		cin >> c;
		
		switch (c)
		{
		case 1:
			cout << "Вы выбрали добавление" << endl;
			cout << "Day number?" << endl;
			cin >> day;
			if (day > 31)
			{
				cout << "Error! Day > 30!" << endl;
				break;
			}
			cout << "Tемпература?" << endl;
			cin >> value;
			PairAdd(Map, day, value);
			break;
		case 2:
			cout << "Вы выбрали удаление по дню" << endl;
			cout << "Day Number?" << endl;
			cin >> day;
			if (day > 31 || day < 0)
			{
				cout << "Error! Day!" << endl;
				break;
			}
			tempMap.insert(make_pair(day, Map[day]));
			Stack = MakeStack(tempMap);
			SaveDay = day;
			DeleteOfDay(Map, day);
			break;
		case 3:
			cout << "Вы выбрали удаление по значению" << endl;
			cout << "Температура? ?" << endl;
			cin >> value;
			SaveDay = DeleteOfValue(Map, value);
			tempMap.insert(make_pair(SaveDay, value));
			Stack = MakeStack(tempMap);
			break;
		case 4:
			PrintPair(Map);
			break;
		case 5:
			cout << "Сохранение.. " << endl;
			ostreamFile(Map);
			break;
		case 6:
			cout << "Вы выбрали отмену последней операции" << endl;
			SaveLast(Map, Stack, SaveDay);
			break;
		case 0:
			c = 0;
			break;
		default:
			break;
		}
	} while (c != 0);
	
	
}