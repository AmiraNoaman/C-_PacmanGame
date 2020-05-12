#include "Action.h"

#include "ApplicationManager.h"

Action::Action(ApplicationManager *pApp) : pManager(pApp)
{
	// The constructor initializes the ApplicationManager pointer data member
}

Action::~Action()
{
}
