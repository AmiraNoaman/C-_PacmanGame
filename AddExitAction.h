#pragma once
#include "Action.h"
#include "Output.h"

class AddExitAction : public Action
{
public:
	AddExitAction(ApplicationManager*);
	virtual void ReadActionParameters();
	virtual void Execute();
	~AddExitAction();
};
