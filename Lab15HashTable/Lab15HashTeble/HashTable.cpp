#include "HashTable.h"



HashTable::HashTable()
{
	Table = new Data;
	size = 0;
}

HashTable::HashTable(int s)
{
	size = s;
	Table = new Data[s];

	Data temp = { "empty", 0 , 0 };
	for (int i = 0; i < size; i++)
		Table[i] = temp;
}


HashTable::~HashTable()
{
}

void HashTable::Add(const Data& data)
{
	int Key = Hash(data.name);
	if (Table[Key].name == "empty")
	{
		Table[Key] = data;
		tempsize++;
		return;
	}
	while (Table[Key].name != "empty")
	{
		Key++;
		if (Key == size)
			Key = 0;

		if (Table[Key].name == "empty")
		{
			Table[Key] = data;
			tempsize++;
			return;
		}
	}
}

int HashTable::Hash(const string& key)
{
	int n = 13;
	int KeySum = 0;
	int sum = 0;
	double A = 0.61183;
	for (int i = 0; i < key.length(); i++)
	{
		KeySum += (int)(key[i]);
	}
	sum = n * fmod(KeySum * A, 2);
	return sum % size;
}

void HashTable::Delete(const string& name)
{
	int Key = Hash(name);

	if (Table[Key].name == name)
	{
		Table[Key].name = "empty";
		Table[Key].group = 0;
		Table[Key].rate = 0;
		tempsize--;
		return;
	}

	int check = 1;
	while (Table[Key].name != "empty")
	{
		Key++;
		if (Key == size)
			Key = 0;

		if (Table[Key].name == name)
		{
			Table[Key].name = "empty";
			Table[Key].group = 0;
			Table[Key].rate = 0;
			tempsize--;
			return;
		}

		check++;
		if (check = size)
		{
			cout << "Not found\n";
			return;
		}

		
	}

}

Data HashTable::Find(const string& name)
{
	int Key = Hash(name);

	if (Table[Key].name == name)
		return Table[Key];

	int check = 1;
	while (Table[Key].name != "empty")
	{
		Key++;
		if (Key == size)
			Key = 0;

		if (Table[Key].name == name)
			return Table[Key];

		check++;
	}
	return { "empty", 0, 0 };
}

void HashTable::Change(const string& name, const int& groupS, const double& rateS)
{
	int Key = Hash(name);

	if (Table[Key].name == name)
	{
		Table[Key].group = groupS;
		Table[Key].rate = rateS;
		return;
	}
	int check = 0;
	while (Table[Key].name != "empty")
	{
		Key++;
		if (Key == size)
			Key = 0;

		if (Table[Key].name == name)
		{
			Table[Key].group = groupS;
			Table[Key].rate = rateS;
			return;
		}

		check++;
		if (check = size)
		{
			cout << "Not found\n";
			return;
		}
	}
}

int HashTable::GetCollision()
{
	int count = 0;

	for (int i = 0; i < size; i++)
	{
		if (Table[i].name == "empty")
			continue;
		if (Hash(Table[i].name) != i)
			count++;
	}

	return count;
}

void HashTable::Print()
{
	for (int i = 0; i < size; i++)
		cout << Hash(Table[i].name) << "\t" << Table[i].name << "\t" << Table[i].group << "\t" << Table[i].rate << endl;
}









