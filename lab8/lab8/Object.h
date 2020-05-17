#pragma once
#include "Event.h"

class Object
{
public:
	Object(void);
	virtual void show() = 0;
	virtual void input() = 0;
	virtual ~Object(void);
	virtual void HandleEvent(const TEvent& e);
};

