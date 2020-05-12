#pragma once
#include "Action.h"
class Switch_toGrid : public Action
{
public:
	Switch_toGrid(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~Switch_toGrid();
};

