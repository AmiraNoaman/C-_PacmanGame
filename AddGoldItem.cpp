#include "AddGoldItem.h"

#include "Output.h"
#include "Input.h"
#include "Obstacle.h"
#include "ApplicationManager.h"

AddGoldItem::AddGoldItem(ApplicationManager *pApp) : Action(pApp)
{
}


void AddGoldItem::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("New Gold Item: Click on its Cell ...");
	pos= pIn->GetCellClicked();
	pOut->PrintMessage("Please enter the time step for the gold item to appear");
	TimeStep = stoi(pIn->GetSrting(pOut));

}


void AddGoldItem::Execute()
{
	ReadActionParameters();
	Gold * pGold = new Gold(pos,TimeStep);
	Grid * pGrid = pManager->GetGrid(); 
	pGrid->AddObject(pGold);    
}

AddGoldItem::~AddGoldItem()
{
}
