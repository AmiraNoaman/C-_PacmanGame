#include "AddLiveItem.h"

#include "Output.h"
#include "Input.h"
#include "Obstacle.h"
#include "ApplicationManager.h"

AddLiveItem::AddLiveItem(ApplicationManager *pApp) : Action(pApp)
{
}


void AddLiveItem::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("New Live Item: Click on its Cell ...");
	pos = pIn->GetCellClicked();
	pOut->PrintMessage("Please enter the time step for the live item to appear");
	TimeStep = stoi(pIn->GetSrting(pOut));
	pOut->PrintMessage("Please enter L");
	L = stoi(pIn->GetSrting(pOut));
}

void AddLiveItem::Execute()
{
	ReadActionParameters();
	Live * pLive = new Live(pos, TimeStep,L);
	Grid * pGrid = pManager->GetGrid();
	pGrid->AddObject(pLive);

	/*if (TimeStep > L)
		pGrid->RemoveObject(pos);*/

}

AddLiveItem::~AddLiveItem()
{
}