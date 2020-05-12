#pragma once
#include "Action.h"
class AddScoreEnemy : public Action
{
private:
	int TimeStep;
	Cell Pos;
public:
	AddScoreEnemy(ApplicationManager *pApp);
	void ReadActionParameters();
	void Execute();
	~AddScoreEnemy();
};

