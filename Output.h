#ifndef OUPTUT_H
#define OUPTUT_H

#include "DEFS.h"
#include "UI_Info.h" 
#include "CMUgraphicsLib\CMUgraphics.h"
#include "Cell.h"

// forward declarations (their includes are in the cpp)
class Input;  

class Output	// The application manager (phase 2) should have a pointer to this class
{
private:	

	window* pWind;	// Pointer to the Graphics Window

public:
	Output();		

	Input* CreateInput() const; // Creates a pointer to the Input object	
	
	// ========== Interface Functions ==========

	window* CreateWind(int, int, int , int) const; // Creates the application window

	void ClearStatusBar() const;	// Clears the status bar
	
	///TODO: Complete Implementation of ClearGridArea() function
	void ClearGridArea() const;	    // Draws an empty grid (horizontal and vertical lines with empty cells)

	///TODO: Complete Implementation of CreateGridModeToolBar() function
	void CreateGridModeToolBar() const;	// Creates Create-Grid mode toolbar menu

	///TODO: Complete Implementation of CreateGameModeToolBar() function
	void CreateGameModeToolBar() const;	// Creates Game mode toolbar menu
	
	void PrintMessage(string msg) const;	// Prints a message on Status bar

	// ========== Game Objects Drawing Functions ==========

	//TODO: Add Implementation of DrawObstacle function
	void DrawObstacle(const Cell & cell) const;	// Draws an obstacle in the passed cell
	                                            ///TODO: You MUST use pWind->DrawRectangle with the obstacle background color in this function

	//TODO: Add Implementation of DrawGameObject function
	void DrawGameObject(string imgPath, const Cell & cell) const; // Draws the passed image inside the passed cell
	                                                              // This will be used in phase 2 to draw a game object (enemy, player, friendlyItem, ...etc.)

	//TODO: Add Implementation of ClearCell function
	void ClearCell(const Cell & cell) const; // Clears a cell from any drawings ( Reset it to grid background color )
	
	~Output();
};

#endif