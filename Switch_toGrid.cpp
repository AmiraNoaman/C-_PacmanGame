#include "Switch_toGrid.h"
#include "Output.h"
#include"ApplicationManager.h"


Switch_toGrid::Switch_toGrid(ApplicationManager *pApp) :Action(pApp)
{
}


void Switch_toGrid::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->ClearStatusBar();
}

void Switch_toGrid::Execute()
{
	UI.InterfaceMode = MODE_GAME;
	Output*pOut = pManager->GetOutput();
	pOut->CreateGridModeToolBar();
	pOut->PrintMessage("Switch to Gridmode succeeded !");
	pManager->UpdateInterface();
}

Switch_toGrid::~Switch_toGrid()
{
}
