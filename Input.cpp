#include "Input.h"

#include "Output.h"

//======================================================================================//
//								General Functions									    //
//======================================================================================//

Input::Input(window* pW) 
{
	pWind = pW; // point to the passed window
}

////////////////////////////////////////////////////////////////////////////////////////// 

void Input::GetPointClicked(int &x, int &y, bool wait) const
{
	if(wait)
		pWind->WaitMouseClick(x, y); // wait (pause) till a mouse click
	else
		pWind->GetMouseClick(x, y);	 // no wait
}

////////////////////////////////////////////////////////////////////////////////////////// 

string Input::GetSrting(Output *pO) const 
{
	string Label;
	char Key;
	while(1)
	{
		pWind->WaitKeyPress(Key);
		if(Key == 27 )	// ESCAPE key is pressed
			return "";	// returns nothing as user has cancelled label
		if(Key == 13 )	// ENTER key is pressed
			return Label;
		if((Key == 8) && (Label.size() >= 1))	// BackSpace is pressed
			Label.resize(Label.size() -1 );			
		else
			Label += Key;
		if (pO)
			pO->PrintMessage(Label);
	}
}

//======================================================================================//
//								Game  Functions									        //
//======================================================================================//

ActionType Input::GetUserAction(bool wait) const
{	
	int x = -1, y = -1;
	GetPointClicked(x, y, wait); 

	//  ============ GUI in the CREATE-GRID mode ============
	if ( UI.InterfaceMode == MODE_CREATE_GRID )	
	{
		// [1] If user clicks on the Toolbar
		if ( y >= 0 && y < UI.ToolBarHeight)
		{	
			// Check which Menu item was clicked
			// ==> This assumes that menu items are lined up horizontally <==

			int ClickedItemOrder = (x / UI.MenuItemWidth);

			// Divide x coord of the point clicked by the menu item width (integer division)
			// If division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_ADD_OBSTACLE: return ADD_OBSTACLE;
			case ITM_ADD_KILLER_ENEMY: return ADD_KILLER_ENEMY;
			case ITM_ADD_SHOOTER_ENEMY: return ADD_SHOOTER_ENEMY;
			case ITM_ADD_HEALTH_ENEMY: return ADD_HEALTH_ENEMY;
			case ITM_ADD_SCORE_ENEMY: return ADD_SCORE_ENEMY;
			case ITM_ADD_LIVE_FRIENDLY: return ADD_LIVE_FRIENDLY;
			case ITM_ADD_GOLD_FRIENDLY: return ADD_GOLD_FRIENDLY;
			case ITM_ADD_PLATINUM_FRIENDLY: return ADD_PLATINUM_FRIENDLY;
			case ITM_ADD_HEART_FRIENDLY: return ADD_HEART_FRIENDLY;
			case ITM_DELETE: return LDELETE;
			case ITM_SET_TIME:return SET_TIME;
			case ITM_SAVE: return SAVE;
			case ITM_OPEN:return OPEN;
			case ITM_SWITCH_TOPLAY:return TO_GAME_MODE;
			case ITM_EXIT: return EXIT;

			///TODO: Add cases for the other items of Create-Grid Mode

			default: return EMPTY;	// A click on empty place in toolbar
			}
		}

		// [2] User clicks on the grid area
		if ( (y >= UI.ToolBarHeight) && (y < UI.height - UI.StatusBarHeight))
		{
			return GRID_AREA;	
		}

		// [3] User clicks on the status bar
		return STATUS;
	}
	// ============ GUI in the GAME mode ============
	else	
	{
		///TODO:
		// perform checks similar to Game mode checks above for the Game Mode
		// and return the corresponding ActionType
		if (y >= 0 && y < UI.ToolBarHeight)
		{
			// Check which Menu item was clicked
			// ==> This assumes that menu items are lined up horizontally <==

			int ClickedItemOrder = (x / UI.MenuItemWidth);

			// Divide x coord of the point clicked by the menu item width (integer division)
			// If division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_CHOOSE_GRID_R:return CHOOSE_GRID_R;
			case ITM_CHOOSE_GRID_C:return CHOOSE_GRID_C;
			case ITM_GRAB_WEAPON:return GRAB_WEAPON;
			case ITM_RELOAD:return RELOAD;
			case ITM_PAUSE:return PAUSE;
			case ITM_RESUME:return RESUME;
			case ITM_SAVE_GAME:return SAVE_GAME;
			case ITM_EXIT2: return EXIT;
			case ITM_SWITCH_TOGRID: return SWITCH_TOGRID;

			default: return EMPTY;	// A click on empty place in toolbar
			}
		}

		// [2] User clicks on the grid area
		if ((y >= UI.ToolBarHeight) && (y < UI.height - UI.StatusBarHeight))
		{
			return GRID_AREA;
		}

		// [3] User clicks on the status bar
		return STATUS;
	}	

}

////////////////////////////////////////////////////////////////////////////////////////// 

DIRECTION Input::TakeMoveDirection(const Cell & current) const
{
	char Key;
	pWind->GetKeyPress(Key); // no wait

	///TODO: COMPLETE IMPLEMENTATION HERE
	if (Key == 'j' || Key == 'J')
		return LEFT;
	else if (Key == 'l' || Key == 'L')
		return RIGHT;
	else if (Key == 'i' || Key == 'I')
		return UP;
	else if (Key == 'k' || Key == 'K')
		return DOWN;
		return NO_MOVE; // if other keys is pressed OR if it can't move because of obstacle
}

////////////////////////////////////////////////////////////////////////////////////////// 

// <<<<<<<<<<< ============ >>>>>>>>>>>

///TODO: ADD IMPLEMENTATION OF GetCellClicked() HERE

// <<<<<<<<<<< ============ >>>>>>>>>>>
Cell Input::GetCellClicked() const {
	int x, y;
	Cell dumm(-1,-1);
	pWind->WaitMouseClick(x, y);
	if (y < 50 || y > 600)
		return dumm;
	int Cx = x / 50;
	int Cy = (y / 50)-1;
	dumm.SetHCell(Cx);
	dumm.SetVCell(Cy);
	return dumm;
}

////////////////////////////////////////////////////////////////////////////////////////// 

Input::~Input()
{
}
