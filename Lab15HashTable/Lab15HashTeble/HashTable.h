#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Data
{
	string name = " ";
	int group = 0;
	double rate = 0;
};

class HashTable
{
	Data* Table;
	int size;
	int tempsize;

public:
	HashTable();
	HashTable(int s);
	~HashTable();
	void Add(const Data& data);
	int Hash(const string& key);
	void Delete(const string& name);
	Data Find(const string& name);
	void Change(const string& name, const int& group, const double& rate);
	int GetCollision();
	void Print();

};

