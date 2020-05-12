#pragma once
#include "Action.h"
#include <fstream>

class Reload_Game : public Action
{
public:

	ifstream InFile;
	string filename;
public:
	Reload_Game(ApplicationManager*pApp);

	virtual void ReadActionParameters();

	virtual void Execute();

	virtual ~Reload_Game();
};

