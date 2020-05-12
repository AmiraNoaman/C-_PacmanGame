#pragma once
#include "Action.h"
#include "Gold.h"


class AddGoldItem :public Action
{
private:
	int TimeStep;
	Cell pos; 

public:
	AddGoldItem(ApplicationManager *pApp); 
	virtual void ReadActionParameters();
	virtual void Execute();
	~AddGoldItem(); 
};

