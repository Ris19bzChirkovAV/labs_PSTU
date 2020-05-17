#pragma once
#include "Object.h"
#include "Event.h"

using namespace std;

class Vector
{
public:
	Vector();
	Vector(int);
	~Vector(void);
	void Add();
	void Del();
	void show();
	void show(int);
	virtual void HandleEvent(const TEvent& e);
protected:
	Object** beg;
	int size;
	int cur;
};

