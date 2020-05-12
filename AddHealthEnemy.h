#pragma once
#include "Action.h"
class AddHealthEnemy : public Action
{
private:
	int TimeStep;
	Cell Pos;
public:
	AddHealthEnemy(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~AddHealthEnemy();
};

