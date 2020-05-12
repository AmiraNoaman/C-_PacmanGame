#pragma once
#include "Action.h"
#include <fstream>

class Save_Game :
	public Action
{
	//	ofstream Outfile;
	string filename;
public:
	Save_Game(ApplicationManager *pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual ~Save_Game();
};

