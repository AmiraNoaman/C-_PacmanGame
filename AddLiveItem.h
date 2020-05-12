#pragma once
#include "Action.h"
#include "Live.h"


class AddLiveItem :public Action
{
private:
	int TimeStep;
	Cell pos;
	int L;

public:

	AddLiveItem(ApplicationManager *pApp); 
	virtual void ReadActionParameters();
	virtual void Execute(); 
	~AddLiveItem(); 

};

