#pragma once
#include "Action.h"
class AddShooterEnemy :
	public Action
{
private:
	Cell Pos;
	int Brate;
public:
	AddShooterEnemy(ApplicationManager *pApp);
	void ReadActionParameters();
	void Execute();
	~AddShooterEnemy();
};

