#include <iostream>
#include "HashTable.h"
#include <vector>

using namespace std;

HashTable MakeTable()
{
	int size;
	cout << "Размер?\n";
	cin >> size;
	cin.get();

	vector<string> names = { "Ivanov", "Petrov", "Sidorov", "Lukashenko", "Clinton", "Obama", "Cartman", "Broflovsky", "March", "McCormick" };
	vector<string> surnames = { "Ivan", "Kenny", "Eric", "Stan", "Kyle","Fedor", "Ippolit", "Andre", "Nikola","Barak"};
	vector<string> patronymics = { "Vasilevich", "Semenovich", "Mikhailovich", "Andreevich", "Nikolaich","Abdulaevich", "Fedorovich", "Sidorovich", "Ivanovich", "Petrovich" };
	HashTable temp(size);
	for (int i = 0; i < size; i++)
		temp.Add({ names[rand() % names.size()] + ' ' + surnames[rand() % surnames.size()] + ' ' + patronymics[rand() % patronymics.size()], rand() % 10, (double)rand() * 0.0031});

	return temp;
}

void add(HashTable& Table)
{
	Data temp;

	cout << "Введите имя ";
	cin.ignore();
	getline(cin, temp.name);
	cout << "Введите № группы: ";
	cin.ignore();
	cin >> temp.group;
	cin.get();
	cout << "Введите рейтинг ";
	cin.ignore();
	cin >> temp.rate;
	cin.get();
	Table.Add(temp);
}

void Delete(HashTable& Table)
{
	cout << "Введите имя ";
	string name;
	cin.ignore();
	getline(cin, name);
	Table.Delete(name);
}

void Find(HashTable& Table)
{
	cout << "Введите имя " << endl;
	string name;
	cin.ignore();
	getline(cin, name);

	Data temp = Table.Find(name);

	if (temp.name != "empty")
	{
		cout << "Имя: " << temp.name << endl;
		cout << "Группа: " << temp.group << endl;
		cout << "Рейтинг: " << temp.rate << endl;
	}
	else
		return;
}

void Change(HashTable& Table)
{
	cout << "Введите имя " << endl;
	string name;
	cin.ignore();
	getline(cin, name);

	Data temp = Table.Find(name);

	if (temp.name != "empty")
	{
		cout << "Новый номер группы? ";
		int group;
		cin >> group;
		cin.get();
		cout << "Новый рейтинг? ";
		double rate;
		cin >> rate;
		cin.get();
		Table.Change(name, group, rate);
	}
	else
		return;
}

void Collisions(HashTable& Table)
{
	int count = Table.GetCollision();

	cout << "Всего коллизий: " << count << endl;;
}

void main()
{
	setlocale(LC_ALL, "ru");
	HashTable Table;
	int s;
	do
	{
		system("cls");
		cout << "Меню\n";
		cout << "1. Создать таблицу" << endl;
		cout << "2. Вывести на экран" << endl;
		cout << "3. Добавить элемент " << endl;
		cout << "4. Найти элемент " << endl;
		cout << "5. Изменить элемент " << endl;
		cout << "6. Удалить элемент " << endl;
		cout << "7. Коллизии " << endl;
		cin >> s;
		switch (s)
		{
		case 1:
			Table = MakeTable();
			break;
		case 2:
			Table.Print();
			break;
		case 3:
			add(Table);
			break;
		case 4:
			Table.Print();
			Find(Table);
			break;
		case 5:
			Table.Print();
			Change(Table);
			break;
		case 6:
			Table.Print();
			Delete(Table);
			break;
		case 7:
			Collisions(Table);
			break;
		default:
			break;
		}
		system("pause");
	} while (s != 0);

}

