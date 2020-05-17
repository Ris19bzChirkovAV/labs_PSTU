#include "Time.h"
#include <iostream>
#include <fstream>
#include <string>
#include "FileWork.h"

using namespace std;

void main()
{
	Time t;
	Time nom;
	int k;
	int c;
	char FileName[30];
	do
	{
		cout << "\n1. Make File";
		cout << "\n2. Print";
		cout << "\n3. Delete value from file";
		cout << "\n4. Add record to file";
		cout << "\n5. IncreaseValue record in file";
		cout << "\n0. Exit \n";
		cin >> c;
		switch (c)
		{
		case 1:
			cout << " File Name? \n";
			cin >> FileName;
			k = MakeFile(FileName);
			if (k < 0)
				cout << "Can't make file \n";
			break;
		case 2:
			cout << " File Name? \n";
			cin >> FileName;
			k = PrintFile(FileName);
			if (k == 0)
				cout << "Empty file! \n";
			if (k < 0)
				cout << "Can't read file \n";
			break;
		case 3:
			cout << " File Name? \n";
			cin >> FileName;
			cout << "nom? \n";
			cin >> nom;
			k = DeleteValue(FileName, nom);
			if (k < 0)
				cout << "Can't read file \n";
			break;
		case 4:
			cout << " File Name? \n";
			cin >> FileName;
			int nom;
			cout << "nom? \n";
			cin >> nom;
			k = AddEnd(FileName, nom);
			if (k < 0)
				cout << "Can't read file \n";
			break;
		case 5:
			cout << " File Name? \n";
			cin >> FileName;
			int nim = 90;
			k = IncreaseValue(FileName, nim);
			if (k < 0)
				cout << "Can't read file \n";
			break;
		}

	} while (c != 0);

}
