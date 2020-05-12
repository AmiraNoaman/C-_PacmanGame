#pragma once

#include "DEFS.h"
#include "UI_Info.h"
#include "Cell.h"

// forward declarations (their includes are in the cpp)
class ApplicationManager; 

// Base class for all possible actions

class Action
{
protected:

	ApplicationManager *pManager;	// Actions needs AppMngr to do their job

public:

	Action(ApplicationManager *pApp);  // Constructor

	// ============ Virtual Functions ============

	virtual void ReadActionParameters() = 0; // Reads parameters required for action to execute (code depends on action type)
	
	virtual void Execute() = 0;  // Executes action (code depends on action type)

	virtual ~Action();  // Virtual Destructor
};

