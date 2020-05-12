#include "AddExitAction.h"
#include"ApplicationManager.h"

AddExitAction::AddExitAction(ApplicationManager *pApp) :Action(pApp)
{
}

void AddExitAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->ClearStatusBar();
}

void AddExitAction::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	pManager->Exit();
	pManager->UpdateInterface();
}

AddExitAction::~AddExitAction()
{
}
