#pragma once
#include "Action.h"
#include "Output.h"
#include "Input.h"
#include "Grid.h"

class AddDeleteAction : public Action
{
	Cell position;
public:
	AddDeleteAction(ApplicationManager*);
	virtual void ReadActionParameters();
	virtual void Execute();
	~AddDeleteAction();
};
