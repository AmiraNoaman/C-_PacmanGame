#pragma once
#include "Action.h"
class Switch_toPlay: public Action
{
public:
	Switch_toPlay(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	~Switch_toPlay();
};

