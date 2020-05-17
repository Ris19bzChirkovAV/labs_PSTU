#pragma once
#include "Vector.h"
#include "event.h"

class Dialog :
	public Vector
{
public:
	Dialog(void);
public:
	virtual ~Dialog(void);
	virtual void GetEvent(TEvent& event);
	virtual int Execute();
	virtual void HandleEvent(TEvent& event);
	virtual void ClearEvent(TEvent& event);
	int Valid();
	void EndExec();
protected:
	int EndState;
	int Number;
};