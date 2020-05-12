#include "ApplicationManager.h"

#include "Output.h"
#include "Input.h"
#include "Grid.h"
#include "Action.h"
#include "Player.h"

#include "AddObstacleAction.h"
#include "Current_Grid.h"
#include "Save_Grid.h"
#include "Open_Grid.h"

#include "Save_Game.h"
#include "Reload_Game.h"

#include "Switch_toPlay.h"
#include "Switch_toGrid.h"
#include "AddExitAction.h"
#include "AddDeleteAction.h"

#include "AddKillerEnemy.h"
#include "AddShooterEnemy.h"
#include "AddHealthEnemy.h"
#include "AddScoreEnemy.h"

#include "AddGoldItem.h"
#include "AddLiveItem.h"
#include "AddPlatinumItem.h"
#include "AddHeartItem.h"


ApplicationManager::ApplicationManager()
{
	// Create Input, output and Grid
	pOut = new Output();
	pIn = pOut->CreateInput();
	pGrid = new Grid(pOut, pIn);
	Pause = false;
	Time = 1;

}

////////////////////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	delete pIn;
	delete pOut;
	delete pGrid;
}

//==================================================================================//
//								Interface Management Functions						//
//==================================================================================//

Input *ApplicationManager::GetInput() const
{	return pIn; }

////////////////////////////////////////////////////////////////////////////////////

Output *ApplicationManager::GetOutput() const
{	return pOut; }

////////////////////////////////////////////////////////////////////////////////////

Grid * ApplicationManager::GetGrid() const
{
	return pGrid;
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//

ActionType ApplicationManager::GetUserAction() const
{
	bool wait = (UI.InterfaceMode == MODE_CREATE_GRID);

	// Ask the input to get the action from the user.
	return pIn->GetUserAction(wait);
}

////////////////////////////////////////////////////////////////////////////////////

// Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;

	// According to Action Type, create the corresponding action object
	switch (ActType)
	{
	case ADD_OBSTACLE:
		pAct = new AddObstacleAction(this);
		break;

	case ADD_KILLER_ENEMY:
		pAct = new AddKillerEnemy(this);
		break;
	case ADD_SHOOTER_ENEMY:
		pAct = new AddShooterEnemy(this);
		break;
	case ADD_HEALTH_ENEMY:
		pAct = new AddHealthEnemy(this);
		break;
	case ADD_SCORE_ENEMY:
		pAct = new AddScoreEnemy(this);
		break;


	case ADD_GOLD_FRIENDLY:
		pAct = new AddGoldItem(this);
		break;
	case ADD_LIVE_FRIENDLY:
		pAct = new AddLiveItem(this);
		break;
	case ADD_PLATINUM_FRIENDLY:
		pAct = new AddPlatinumItem(this);
		break;
	case ADD_HEART_FRIENDLY:
		pAct = new AddHeartItem(this);
		break;

	case SAVE:
		pAct = new Save_Grid(this);
		break;
	case SAVE_GAME:
		pAct = new Save_Game(this);
		break;


	case OPEN:
		pAct = new Open_Grid(this);
		break;

	case RELOAD:
		pAct = new Reload_Game(this);
		break;

	case EXIT:
		pAct = new AddExitAction(this);
		break;

	case EXIT2:
		pAct = new AddExitAction(this);
		break;

	case LDELETE:
		pAct = new AddDeleteAction(this);
		break;

	case TO_GAME_MODE:
		pAct = new Switch_toPlay(this);
		break;

	case SWITCH_TOGRID :
		pAct = new Switch_toGrid(this);
		break;

	case CHOOSE_GRID_C:
		pAct = new Current_Grid(this);
		break;

	case STATUS:	
		return;
	
	}

	// Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute(); // Execute
		delete pAct;	 // Action is not needed any more after executing, so we delete it
		pAct = NULL;
	}
}

void ApplicationManager::UpdateInterface() const
{
	pOut->ClearGridArea();
}

void ApplicationManager::Exit() const
{
	pOut->ClearGridArea();
	pOut->ClearStatusBar();
}

int ApplicationManager::getGameTime() const
{
	return Time;
}

void ApplicationManager::StartGame() {
	int TimeSteps = Time * 60 * 10;
	int TimeStepCounter = 0;
	pOut->ClearGridArea();
	Player* P1 = pGrid->AddPlayer();
	while (Pause == false) {
		pGrid->MoveAll();
		pGrid->DrawAll(pOut);
		pOut->PrintMessage("Player Lives ="+to_string(P1->GetLives())+ " Player Health = "+to_string(P1->GetHealth())+" Player Score = "+to_string(P1->GetScore()));
		Sleep(100);
		TimeStepCounter++;
		if (TimeStepCounter == TimeSteps)
			break;
	}
}