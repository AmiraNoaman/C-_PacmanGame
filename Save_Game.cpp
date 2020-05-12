#include "Save_Game.h"
#include "Output.h"
#include "Input.h"
#include "ApplicationManager.h"
#include "Grid.h"

Save_Game::Save_Game(ApplicationManager *pApp) :Action(pApp)
{
}


void Save_Game::ReadActionParameters()
{

	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Saving Game: Please enter the file name");
	filename = pIn->GetSrting(pOut) + ".txt";
	pOut->ClearStatusBar();
}

//Execute the action
void Save_Game::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	ofstream OutFile(filename, ios::out);
	if (OutFile.is_open())
	{
		pOut->PrintMessage(filename + " file has been opened");
		Grid* pGrid = pManager->GetGrid();

		pGrid->SaveGame(OutFile, OBSTACLE__);
		pGrid->SaveGame(OutFile, ENEMY__);
		pGrid->SaveGame(OutFile, FRIENDLY_ITEM__);
		pGrid->SaveGame(OutFile, PLAYER__);

	}
	else
		pOut->PrintMessage("Error, Cannot open the file");

	OutFile.close();

}

Save_Game::~Save_Game()
{
}