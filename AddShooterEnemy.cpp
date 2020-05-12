#include "AddShooterEnemy.h"
#include "Output.h"
#include "Input.h"
#include "ShooterEnemy.h"
#include "Grid.h"
#include "ApplicationManager.h"


AddShooterEnemy::AddShooterEnemy(ApplicationManager *pApp):Action(pApp)
{
}
void AddShooterEnemy::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Please Click on a Cell to a Shooter Enemy");
	Pos = pIn->GetCellClicked();
	pOut->PrintMessage("Please enter bullet rate");
	Brate = stoi(pIn->GetSrting(pOut));
}
void AddShooterEnemy::Execute() {
	ReadActionParameters();
	ShooterEnemy* S = new ShooterEnemy(Pos, Brate);
	Grid* pGrid = pManager->GetGrid();
	pGrid->AddObject(S);
}
AddShooterEnemy::~AddShooterEnemy()
{
}
