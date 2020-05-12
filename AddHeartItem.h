#pragma once
#include "Action.h"
#include "Heart.h"


class AddHeartItem :public Action
{
private:
	int TimeStep;
	Cell pos;

public:
	AddHeartItem(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~AddHeartItem();
};

