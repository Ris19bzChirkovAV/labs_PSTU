#pragma warning(disable : 4996)
#pragma once
class SearhTree
{
	const int datasize = 50;
	char* Data;
	SearhTree* left;
	SearhTree* right;
	SearhTree* up;
public:
	SearhTree();
	SearhTree(const char* data);
	~SearhTree();
	void Insert(const char* data);
	void PrintTree(int S);
	char* getData();
};
