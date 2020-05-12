#pragma once
#include "Action.h"
#include "Platinum.h"

class AddPlatinumItem : public Action
{
private:
	int TimeStep;
	Cell pos; 

public:

	AddPlatinumItem(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~AddPlatinumItem();
};

