#include "Save_Grid.h"
#include "Output.h"
#include "Input.h"
#include "ApplicationManager.h"
#include "Grid.h"

Save_Grid::Save_Grid(ApplicationManager *pApp) :Action(pApp)
{
}


void Save_Grid::ReadActionParameters()
{

	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Saving Grid: Please enter the file name");
	filename = pIn->GetSrting(pOut) + ".txt";
	pOut->ClearStatusBar();
}

//Execute the action
void Save_Grid::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	Output* pOut = pManager->GetOutput();
	ofstream OutFile(filename, ios::out);
	if (OutFile.is_open())
	{
		pOut->PrintMessage(filename + " file has been opened");
		Grid* pGrid = pManager->GetGrid();

		pGrid->SaveAll(OutFile, OBSTACLE__);

		pGrid->SaveAll(OutFile, ENEMY__);

		pGrid->SaveAll(OutFile, FRIENDLY_ITEM__);

	}
	else
		pOut->PrintMessage("Error, Cannot open the file");

	OutFile.close();

}

Save_Grid::~Save_Grid()
{
}