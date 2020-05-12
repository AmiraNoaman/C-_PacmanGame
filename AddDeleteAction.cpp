#include "AddDeleteAction.h"
#include"ApplicationManager.h"

AddDeleteAction::AddDeleteAction(ApplicationManager *pApp) :Action(pApp)
{
}

void AddDeleteAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("To Delete game object: Click on its Cell ...");
	position = pIn->GetCellClicked();
	pOut->ClearStatusBar();
}

void AddDeleteAction::Execute()
{
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	Grid * pGrid = pManager->GetGrid();
	pGrid->RemoveObject(position);
}

AddDeleteAction::~AddDeleteAction()
{
}
