#include <iostream>
#include "Tree.h"
#include "SearhTree.h"
#include <vector>

void replaceTree(Tree* tree, SearhTree* search);

using namespace std;

void main()
{
	setlocale(LC_ALL, "ru");

	Tree* tree = nullptr;
	SearhTree* search = new SearhTree;
	int s;
	do
	{
		cout << "\tМеню\n";
		cout << "1. Создать дерево\n";
		cout << "2. Показать дерево\n";
		cout << "3. Посчитать количество листьев\n";
		cout << "4. Преобразовать в дерево поиска\n";
		cout << ">";
		cin >> s;
		switch (s)
		{
		case 1:
			int size;
			cout << "Укажите размер >";
			cin >> size;
			tree = MakeTree(size);
			break;
		case 2:
			Print(tree, 0);
			cout << endl;
			break;
		case 3:
			cout << "Количество листьев = " << count(tree) << endl;
			break;
		case 4:
			replaceTree(tree, search);
			s = 0;
		default:
			break;
		}
		system("pause");
		system("cls");
	} while (s != 0);
	s = 10;
	cout << "Дерево поиска: \n";
	search->PrintTree(0);
}

void replaceTree(Tree * tree, SearhTree * search)
{
	vector<char*> Vector;
	CopyTreeToVector(tree, Vector);
	for (int i = 0; i < Vector.size(); i++)
	{
		search->Insert(Vector[i]);
	}
}

