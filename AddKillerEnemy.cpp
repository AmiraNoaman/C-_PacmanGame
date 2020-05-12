#include "AddKillerEnemy.h"
#include "Output.h"
#include "Input.h"
#include "ApplicationManager.h"
#include "KillerEnemy.h"
#include "Grid.h"

AddKillerEnemy::AddKillerEnemy(ApplicationManager *pApp):Action(pApp)
{
}


void AddKillerEnemy::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Please Click on a Cell to a Killer Enemy");
	Pos = pIn->GetCellClicked();
	pOut->PrintMessage("Please enter the time step to for the Enemy to appear");
	TimeStep = stoi(pIn->GetSrting(pOut));
}

void AddKillerEnemy::Execute()
{
	ReadActionParameters();
	KillerEnemy* K = new KillerEnemy(Pos, TimeStep);
	Grid* pGrid = pManager->GetGrid();
	pGrid->AddObject(K);
}

AddKillerEnemy::~AddKillerEnemy()
{
}