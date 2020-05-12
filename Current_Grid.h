#pragma once
#include "Action.h"
class Current_Grid : public Action
{
public:
	Current_Grid(ApplicationManager *pApp);
	void ReadActionParameters();
	void Execute();
	~Current_Grid();
};

