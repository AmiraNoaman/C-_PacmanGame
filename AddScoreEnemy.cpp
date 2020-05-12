#include "AddScoreEnemy.h"
#include "ApplicationManager.h"
#include "Output.h"
#include "Input.h"
#include "ScoreEnemy.h"
AddScoreEnemy::AddScoreEnemy(ApplicationManager *pApp):Action(pApp)
{
}
void AddScoreEnemy::ReadActionParameters() {
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Please Click on a Cell to add Score Enemy");
	Pos = pIn->GetCellClicked();
	pOut->PrintMessage("Please enter the time step to for the Enemy to appear");
	TimeStep = stoi(pIn->GetSrting(pOut));
}
void AddScoreEnemy::Execute() {
	ReadActionParameters();
	ScoreEnemy* S = new ScoreEnemy(Pos, TimeStep);
	Grid* pGrid = pManager->GetGrid();
	pGrid->AddObject(S);
}

AddScoreEnemy::~AddScoreEnemy()
{
}
