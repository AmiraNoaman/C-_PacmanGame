#include "AddObstacleAction.h"

#include "Output.h"
#include "Input.h"
#include "Obstacle.h"
#include "ApplicationManager.h"

AddObstacleAction::AddObstacleAction(ApplicationManager *pApp) : Action(pApp)
{
	// Initializes the pManager pointer of Action with the passed pointer
}

AddObstacleAction::~AddObstacleAction()
{
}

void AddObstacleAction::ReadActionParameters() 
{	
	// Get a Pointer to the Input / Output Interfaces from the ApplicationManger
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("New Obstacle: Click on its Cell ...");
	
	// Read the start cell of the enemy
	position = pIn->GetCellClicked();

	// The only action parameter of AddObstacleAction is the the cell position
	// Action parameters are the inputs you need to take from the user after choosing the icon of the action
	// to be able to perform the action

	// Clear messages
	pOut->ClearStatusBar();
}


// Execute the action
void AddObstacleAction::Execute() 
{
	// The first line of any Action Execution is to read its parameter first and hence initializes its data members
	ReadActionParameters();
	
	// Create an Obstacle object with the parameters read from the user
	Obstacle * pObstacle = new Obstacle(position);

	// Add the Obstacle to the GameObjectList of the Grid
	Grid * pGrid = pManager->GetGrid(); // We get a pointer to the Grid from the ApplicationManager
	pGrid->AddObject(pObstacle);        // Function AddObject adds the passed object to the GameObjectList and draws it

	// Here, the obstacle is created and added to the GameObjectList, so we finished executing the AddObstacleAction

}
