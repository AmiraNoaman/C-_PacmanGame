#include "Output.h"

#include "Input.h"

////////////////////////////////////////////////////////////////////////////////////////// 

Output::Output()
{
	// Initialize user interface parameters
	UI.InterfaceMode = MODE_CREATE_GRID;

	// Widths and Heights

	UI.StatusBarHeight = 60;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 50;

	UI.width = 1100; // make it divisible by NumHorizontalCells
	UI.height = UI.width/2 + UI.ToolBarHeight + UI.StatusBarHeight; // the grid height (window width/2)
                                                                    // Note: num vertical cells = num horizontal cells / 2
	UI.wx = 5;
	UI.wy = 5;

	UI.GridCellWidth = UI.width / NumHorizontalCells;

	// Colors

	UI.MsgColor = DARKRED;		    // StatusBar Messages color
	UI.BkGrndColor = DARKSLATEBLUE;	// Grid Background color
	UI.StatusBarColor = GREY;       // StatusBar Background color

	UI.GridLineColor = LIGHTGRAY;   // Vertical and Horizontal Lines
	UI.ObstacleColor = BLACK;       // Background of Obstacles
	
	// Create the output window
	pWind = CreateWind(UI.width + 15, UI.height, UI.wx, UI.wy); 

	// Change the title
	pWind->ChangeTitle("Game");
		
	CreateGridModeToolBar(); // this call will test your implementation
	ClearGridArea();         // this call will test your implementation
	ClearStatusBar();
}

////////////////////////////////////////////////////////////////////////////////////////// 

Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}

////////////////////////////////////////////////////////////////////////////////////////// 

void Output::ClearStatusBar() const
{
	// Clear Status bar by drawing a filled rectangle with status bar background color
	pWind->SetPen(UI.StatusBarColor, 1);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearGridArea() const
{
	// Create a big rectangle with the background of the Grid
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight, UI.width, UI.height - UI.StatusBarHeight);

	
	///TODO: Add The Code to Draw the Horizontal and Vertical Lines Separting Between Grid Cells
	pWind->SetPen(UI.GridLineColor, 0);
	pWind->SetBrush(UI.GridLineColor);
	for (int i = UI.ToolBarHeight; i < (UI.height - UI.StatusBarHeight); i += 50) {
		pWind->DrawLine(0, i, UI.width, i);
	}
	for (int i = UI.GridCellWidth; i < UI.width; i += 50) {
		pWind->DrawLine(i, UI.ToolBarHeight, i, UI.height - UI.StatusBarHeight);
	}
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreateGridModeToolBar() const
{
	UI.InterfaceMode = MODE_CREATE_GRID;

	// You can draw the tool bar icons in any way you want.
	// Below is one possible way
	
	// First prepare List of images for each menu item
	// To control the order of these images in the menu, 
	// reoder them in UI_Info.h ==> enum CREATE_GRID_ITEMS
	string MenuItemImages[CREATE_GRID_ITM_COUNT];
	MenuItemImages[ITM_ADD_OBSTACLE] = "images\\MenuItems\\Menu_Obstacle.jpg";
	MenuItemImages[ITM_ADD_KILLER_ENEMY] = "images\\MenuItems\\Menu_Killer.jpg";
    MenuItemImages[ITM_ADD_SHOOTER_ENEMY] = "images\\MenuItems\\Enemy_Shooter.jpg";
	MenuItemImages[ITM_ADD_HEALTH_ENEMY] = "images\\MenuItems\\Health_Enemy.jpg";
	MenuItemImages[ITM_ADD_SCORE_ENEMY] = "images\\MenuItems\\Score_Enemy.jpg";
	MenuItemImages[ITM_ADD_GOLD_FRIENDLY] = "images\\MenuItems\\gold.jpg";
	MenuItemImages[ITM_ADD_LIVE_FRIENDLY] = "images\\MenuItems\\life.jpg";
	MenuItemImages[ITM_ADD_PLATINUM_FRIENDLY] = "images\\MenuItems\\platinum.jpg";
	MenuItemImages[ITM_ADD_HEART_FRIENDLY] = "images\\MenuItems\\Heart.jpg";
	MenuItemImages[ITM_DELETE] = "images\\MenuItems\\Delete.jpg";
	MenuItemImages[ITM_SET_TIME] = "images\\MenuItems\\clock.jpg";
	MenuItemImages[ITM_SAVE] = "images\\MenuItems\\save.jpg";
	MenuItemImages[ITM_OPEN] = "images\\MenuItems\\open.jpg";
	MenuItemImages[ITM_SWITCH_TOPLAY] = "images\\MenuItems\\switch.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Menu_Exit.jpg";


	///TODO: Prepare images for each menu item and add it to the list


	// Draw menu item one image at a time
	for(int i=0; i<CREATE_GRID_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	// Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);	

}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreateGameModeToolBar() const
{
	UI.InterfaceMode = MODE_GAME;
	string MenuItemImages[GAME_ITM_COUNT];
	MenuItemImages[ITM_CHOOSE_GRID_R] = "images\\MenuItems\\Random.jpg";
	MenuItemImages[ITM_CHOOSE_GRID_C] = "images\\MenuItems\\Current.jpg";
	MenuItemImages[ITM_PAUSE] = "images\\MenuItems\\pause.jpg";
	MenuItemImages[ITM_RESUME] = "images\\MenuItems\\play.jpg";
	MenuItemImages[ITM_SAVE_GAME] = "images\\MenuItems\\save.jpg";
	MenuItemImages[ITM_RELOAD] = "images\\MenuItems\\open.jpg";
	MenuItemImages[ITM_SWITCH_TOGRID] = "images\\MenuItems\\switch.jpg";
	MenuItemImages[ITM_GRAB_WEAPON] = "images\\MenuItems\\grab.jpg";
	MenuItemImages[ITM_EXIT2] = "images\\MenuItems\\Menu_Exit.jpg";



	///TODO: Prepare images for each menu item and add it to the list
	//Clear Grid Menu Items
	pWind->SetBrush(WHITE);
	pWind->SetPen(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight);

	// Draw menu item one image at a time
	for (int i = 0; i < GAME_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	// Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight, UI.width, UI.ToolBarHeight);

	///TODO: write code to create Game mode Toolbar Menu

}

//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(string msg) const	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	
	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(18, BOLD , BY_NAME, "Verdana");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.3), msg);
}

//======================================================================================//
//						Game Objects Drawing Functions   								//
//======================================================================================//

////////////////////////////////////////////////////////////////////////////////////////// 

// <<<<<<<<<<< ============ >>>>>>>>>>>

///TODO: ADD IMPLEMENTATION OF FUNCTION: void DrawObstacle(const Cell & cell) const;

// <<<<<<<<<<< ============ >>>>>>>>>>>
void Output::DrawObstacle(const Cell & cell) const {
	int x1 = (cell.HCell() * 50)+1;
	int y1 = (cell.VCell() * 50)+UI.ToolBarHeight+1;
	pWind->SetPen(UI.ObstacleColor);
	pWind->SetBrush(UI.ObstacleColor);
	pWind->DrawRectangle(x1, y1, x1 + 49, y1 + 49);
}

////////////////////////////////////////////////////////////////////////////////////////// 

////////////////////////////////////////////////////////////////////////////////////////// 

// <<<<<<<<<<< ============ >>>>>>>>>>>

///TODO: ADD IMPLEMENTATION OF FUNCTION: void DrawGameObject(string imgPath, const Cell & cell) const;

// <<<<<<<<<<< ============ >>>>>>>>>>>
void Output::DrawGameObject(string imgPath, const Cell & cell) const {
	int x1 = (cell.HCell() * 50) + 1;
	int y1 = (cell.VCell() * 50) + UI.ToolBarHeight+ 1;
	pWind->DrawImage(imgPath, x1, y1, 50,50);
}

////////////////////////////////////////////////////////////////////////////////////////// 

////////////////////////////////////////////////////////////////////////////////////////// 

// <<<<<<<<<<< ============ >>>>>>>>>>>

///TODO: ADD IMPLEMENTATION OF FUNCTION: void ClearCell(const Cell & cell) const;

// <<<<<<<<<<< ============ >>>>>>>>>>>
void Output::ClearCell(const Cell & cell) const {
	int x1 = (cell.HCell() * 50) + 1;
	int y1 = (cell.VCell() * 50) + UI.ToolBarHeight+1;
	pWind->SetPen(UI.BkGrndColor);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(x1, y1, x1 + 49, y1 + 49);
}

////////////////////////////////////////////////////////////////////////////////////////// 



//////////////////////////////////////////////////////////////////////////////////////////

Output::~Output()
{
	delete pWind;
}

