#pragma once
#include "Action.h"
#include <fstream>

class Save_Grid :
	public Action
{
	//	ofstream Outfile;
	string filename;
public:
	Save_Grid(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual ~Save_Grid();
};

