#include "AddHealthEnemy.h"
#include "Output.h"
#include "Input.h"
#include "ApplicationManager.h"
#include "HealthEnemy.h"
AddHealthEnemy::AddHealthEnemy(ApplicationManager *pApp) :Action(pApp)
{

}
void AddHealthEnemy::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Please Click on a Cell to a Health Enemy");
	Pos = pIn->GetCellClicked();
	pOut->PrintMessage("Please enter the time step to for the Enemy to appear");
	TimeStep = stoi(pIn->GetSrting(pOut));
}
void AddHealthEnemy::Execute() {
	ReadActionParameters();
	HealthEnemy * H= new HealthEnemy(Pos, TimeStep);
	Grid* pGrid = pManager->GetGrid();
	pGrid->AddObject(H);
}
AddHealthEnemy::~AddHealthEnemy()
{
}
