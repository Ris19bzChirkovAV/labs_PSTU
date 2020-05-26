#include "SearhTree.h"
#include <xatomic.h>
#include <iostream>

using namespace std;


SearhTree::SearhTree()
{
}

SearhTree::SearhTree(const char* data)
{
	Data = new char[50];
	Data[0] = '\0';
	strncat(Data, data, 50);

	up = nullptr;
	left = nullptr;
	right = nullptr;
}


SearhTree::~SearhTree()
{
}

void SearhTree::Insert(const char* data)
{
	Data = new char[datasize];
	Data[0] = '\0';
	strncat(Data, data, datasize);
	SearhTree* tree = this;
	while (tree != nullptr)
	{
		if (strcmp(data, tree->Data) < 0)
		{
			if (tree->left != nullptr)
				tree = tree->left;
			else
			{
				SearhTree* NewTree = new SearhTree(data);
				NewTree->up = tree;
				tree->left = NewTree;
				break;
			}
		}
		else if (strcmp(data, tree->Data) > 0 || strcmp(data, tree->Data) == 0)
		{
			if (tree->right != nullptr)
				tree = tree->right;
			else
			{
				SearhTree* NewTree = new SearhTree(data);
				NewTree->up = tree;
				tree->right = NewTree;
				break;
			}
		}
	}
	return;
}

void SearhTree::PrintTree(int S)
{
	if (this == nullptr)
		return;
	S += 10;
	this->right->PrintTree(S);
	cout << "\n\n";
	for (int i = 10; i < S; i++)
		cout << ' ';
	cout << this->getData();
	this->left->PrintTree(S);
}

char* SearhTree::getData()
{
	return this->Data;
}
