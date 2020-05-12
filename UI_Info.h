#ifndef UI_INFO_H
#define UI_INFO_H

#include "CMUgraphicsLib\CMUgraphics.h"

// User Interface information file.
// This file contains info that is needed by Input and Output classes to
// handle the user interface

#define NumHorizontalCells 22
#define NumVerticalCells NumHorizontalCells/2

enum GUI_MODE	// Graphical user interface mode
{
	MODE_CREATE_GRID,	// Create-Grid mode (startup mode)
	MODE_GAME       	// Game mode
};

enum CREATE_GRID_ITEMS // The items of the Creat Grid Mode (you should add more items)
{
	// Note: Items MUST be ordered here as they appear in menu
	// If you want to change the menu items order, change the order here

	ITM_ADD_OBSTACLE,
	ITM_ADD_KILLER_ENEMY,
	ITM_ADD_SHOOTER_ENEMY,
	ITM_ADD_HEALTH_ENEMY,
	ITM_ADD_SCORE_ENEMY,
	ITM_ADD_LIVE_FRIENDLY,
	ITM_ADD_GOLD_FRIENDLY,
	ITM_ADD_PLATINUM_FRIENDLY,
	ITM_ADD_HEART_FRIENDLY,
	ITM_DELETE,
	ITM_SET_TIME,
	ITM_SAVE,
	ITM_OPEN,
	ITM_SWITCH_TOPLAY,
	ITM_EXIT,


	///TODO: Add more items names here


	CREATE_GRID_ITM_COUNT		// no. of items ==> This should be the last line in this enum
};

enum GAME_ITEMS // The items of the Game Mode (you should add more items)
{
	// Note: Items are ordered here as they appear in menu
	// If you want to change the menu items order, change the order here

	ITM_CHOOSE_GRID_R,
	ITM_CHOOSE_GRID_C,
	ITM_GRAB_WEAPON,
	ITM_PAUSE,
	ITM_RESUME,
	ITM_SAVE_GAME,
	ITM_RELOAD,
	ITM_SWITCH_TOGRID,
	ITM_EXIT2,



	///TODO: Add more items names here


	GAME_ITM_COUNT		// no. of items ==> This should be the last line in this enum
};

enum DIRECTION // the 4 possible direction of movements
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	NO_MOVE
};

//enum ENEMY_TYPE
//{
//	ShooterEnemy,
//	KillerEnemy,
//	HealthEnemy,
//};

enum OBJECT_TYPE
{
	OBSTACLE__,
	PLAYER__,
	ENEMY__,
	FRIENDLY_ITEM__,
	HEALTH_ENEMY__,
	KILLER_ENEMY__,
	SCORE_ENEMY__,
	SHOOTER_ENEMY__,
	BULLET__,
};

__declspec(selectany) // This line to prevent "redefinition error"

struct UI_Info	// User Interface Info.
{
	GUI_MODE InterfaceMode;

	int	width, height,	    // Window width and height
		wx , wy,			// Window starting coordinates
		StatusBarHeight,	// Status Bar Height
		ToolBarHeight,		// Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		// Width of each item in toolbar menu
	
	int GridCellWidth;		// Width of 1 CELL (Assume: Cells are squares: width = height)

	color MsgColor;			// Messages color (usually used in statusbar)
	color BkGrndColor;		// Background color (grid background)
	color StatusBarColor;	// Status bar color (statusbar background)

	color GridLineColor;	// Color of the Lines separating adjacent cells
	color ObstacleColor;	// Color of the Obstacle (its background color)

	///TODO: Add more members if needed

} UI ;	// create a global object UI

#endif