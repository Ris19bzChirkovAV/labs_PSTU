#pragma once
#include <vector>

using namespace std;

const int Size = 50;
struct Tree
{
	char* Data;
	Tree* left;
	Tree* right;
};

Tree* MakeTree(const int& size);
void InsertRight(Tree* data, Tree* S);
void InsertLeft(Tree* data, Tree* S);
void Print(Tree* data, int S);
int count(Tree* root);
void CopyTreeToVector(Tree* root, vector<char*>& Vector);