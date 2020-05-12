#ifndef INPUT_H
#define INPUT_H

#include "DEFS.h"
#include "UI_Info.h" 
#include "CMUgraphicsLib\CMUgraphics.h"
#include "Cell.h"

// forward declarations (their includes are in the cpp)
class Output;  

class Input		// The application manager (phase 2) should have a pointer to this class
{
private:

	window *pWind;	// Pointer to the Graphics Windo

public:

	// ========== General Functions ==========

	Input(window *pW);  // Consturctor: Points to the passed window pointer

	void GetPointClicked(int &x, int &y, bool wait=true) const; // Gets real coordinates (x,y) where user clicks
	                                     // ==> (wait=true) means: It waits and pauses the program till mouse click
	                                     // ==> (wait=false) means: It does NOT wait 
	                                     //     but take coordinates whenever a mouse click occurs after the call

	string GetSrting(Output* pO) const ; // Returns a string entered by the user
	
	// ========== Game Functions ==========
	
	///TODO: Complete the Implementions of GetUserAction function
	ActionType GetUserAction(bool wait=true) const;	  // Reads the user click and map it to an action
	                                     // ==> the wait parameter is like wait of GetPointClicked function

	///TODO: Complete the Implementation of TakeMoveDirection function
	DIRECTION TakeMoveDirection(const Cell& current) const;  // Reads Returns direction from keybaord 
	                                                         // Keyboard Keys: 'i'-> UP, 'j'-> Left, 'k'-> Down, 'l'-> Right
	                                                         // You MUST accept direction if the letter is capital or small 
	                                                         // (for example: 'i' and 'I' means UP, so on for other directions)
	
	///TODO: Add the Implementation of GetCellClicked function
	Cell GetCellClicked() const; // Waits for a mouse click and Returns the Clicked Cell
	                             // It is needed only in Create-Grid Mode
	                             // If the click is NOT on a cell, cell (-1,-1) is returned

	~Input(); // Destructor: Add any needed deallocations
};

#endif