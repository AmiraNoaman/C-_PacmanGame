#pragma once
#include "Action.h"
#include "Cell.h"
class AddKillerEnemy : public Action
{
	int TimeStep;
	Cell Pos;
public:
	AddKillerEnemy(ApplicationManager *pApp);
	void ReadActionParameters();
	void Execute();
	~AddKillerEnemy();
};

