#include "AddHeartItem.h"

#include "Output.h"
#include "Input.h"
#include "Obstacle.h"
#include "ApplicationManager.h"

AddHeartItem::AddHeartItem(ApplicationManager *pApp) : Action(pApp)
{
}


void AddHeartItem::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("New Heart Item: Click on its Cell ...");
	pos = pIn->GetCellClicked();
	pOut->PrintMessage("Please enter the time step for the Heart item to appear");
	TimeStep = stoi(pIn->GetSrting(pOut));

}


void AddHeartItem::Execute()
{
	ReadActionParameters();
	Heart * pHeart = new Heart(pos, TimeStep);
	Grid * pGrid = pManager->GetGrid();
	pGrid->AddObject(pHeart);
}

AddHeartItem::~AddHeartItem()
{
}
