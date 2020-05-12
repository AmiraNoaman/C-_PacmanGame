#include "Input.h"
#include "Output.h"
#include "KillerEnemy.h"
#include "Player.h"
#include "Obstacle.h"
#include "ApplicationManager.h"

// This Main Function Must NOT be Changed

int main()
{
	ActionType ActType;

	//Create an object of ApplicationManager
	ApplicationManager AppManager;

	do
	{		
		//Read user action
		ActType = AppManager.GetUserAction();

		//Exexute the action
		AppManager.ExecuteAction(ActType);


	} while(ActType != EXIT);
	
	return 0;
}


