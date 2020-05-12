#include "AddPlatinumItem.h"

#include "Output.h"
#include "Input.h"
#include "Obstacle.h"
#include "ApplicationManager.h"

AddPlatinumItem::AddPlatinumItem(ApplicationManager *pApp) : Action(pApp)
{
}

void AddPlatinumItem::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("New Platinum Item: Click on its Cell ...");
	pos = pIn->GetCellClicked();
	pOut->PrintMessage("Please enter the time step for the platinum item to appear");
	TimeStep = stoi(pIn->GetSrting(pOut));
}


void AddPlatinumItem::Execute()
{
	ReadActionParameters();
	Platinum * pPlatinum = new Platinum(pos, TimeStep);
	Grid * pGrid = pManager->GetGrid();
	pGrid->AddObject(pPlatinum);
}

AddPlatinumItem::~AddPlatinumItem()
{
}