#include "Tree.h"
#include <iostream>

using namespace std;

Tree* MakeTree(const int& size)
{
	if (size == 0)
		return nullptr;

	cout << "”кажите данные >";
	char* data = new char[Size];
	//cin.ignore();
	cin >> data;
	cin.get();
	Tree * root = new Tree{ data, nullptr, nullptr };
	InsertLeft(root, MakeTree(size / 2));
	InsertRight(root, MakeTree(size - size / 2 - 1));

	return root;
}

void InsertRight(Tree * dataS, Tree * S)
{
	if (dataS == nullptr)
		if (S != nullptr)
		{
			dataS = S;
			return;
		}
	Tree* temp = dataS;
	if (temp->right != nullptr)
	{
		temp = temp->right;
		InsertRight(temp, S);
	}
	else
		temp->right = S;
}

void InsertLeft(Tree * dataS, Tree * S)
{
	if (dataS == nullptr)
		if (S != nullptr)
		{
			dataS = S;
			return;
		}
	Tree* temp = dataS;
	if (temp->left != nullptr)
	{
		temp = temp->left;
		InsertLeft(temp, S);
	}
	else
		temp->left = S;
}

void Print(Tree * dataS, int S)
{
	if (dataS == nullptr)
		return;
	S += 10;

	Print(dataS->right, S);

	cout << "\n\n";
	for (int i = 10; i < S; i++)
		cout << ' ';
	cout << dataS->Data;
	Print(dataS->left, S);
}

int count(Tree * root)
{
	if (root == nullptr)
		return 0;

	if (root->left == nullptr && root->right == nullptr)
		return 1;
	else
		return count(root->left) + count(root->right);
}

void CopyTreeToVector(Tree * root, vector<char*> & Vector)
{
	if (root != nullptr)
	{
		Vector.push_back(root->Data);
		CopyTreeToVector(root->left, Vector);
		CopyTreeToVector(root->right, Vector);
	}
}
