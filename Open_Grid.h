#pragma once
#include "Action.h"
#include <fstream>

class Open_Grid :
	public Action
{
	ifstream InFile;
	string filename;
public:
	Open_Grid(ApplicationManager*pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~Open_Grid();
};

