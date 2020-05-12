#include "Switch_toPlay.h"
#include "Output.h"
#include"ApplicationManager.h"


Switch_toPlay::Switch_toPlay(ApplicationManager *pApp) :Action(pApp)
{
}


void Switch_toPlay::ReadActionParameters() 
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->ClearStatusBar();
}

void Switch_toPlay::Execute()
{
	UI.InterfaceMode = MODE_GAME;
	Output*pOut = pManager->GetOutput();
	pOut->CreateGameModeToolBar();
	pOut->PrintMessage("Switch to playmode succeeded !");
	pManager->UpdateInterface();
}

Switch_toPlay::~Switch_toPlay()
{
}
