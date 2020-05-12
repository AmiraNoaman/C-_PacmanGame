#pragma once

#include "DEFS.h"
#include "UI_Info.h"

class Input;
class Output;
class Grid;
// Main class that manages everything in the application.

class ApplicationManager
{
	// Pointer to the Grid
	Grid* pGrid;

	// Pointers to the Input and Output 
	Input *pIn;
	Output *pOut;
	// TimeStep data members mangement
	int Time;
	bool Pause;

public:

	ApplicationManager();  // Constructor: where the Input, Ouput and Grid are allocated
	~ApplicationManager(); // Destructor for needed deallocations

	// ========== Interface Management Functions ==========

	Input *GetInput() const;   // Return pointer to the Input
	Output *GetOutput() const; // Return pointer to the Output
	Grid * GetGrid() const;    // Returns pointer to the Grid

	// ========== Action-Related Functions ==========

	ActionType GetUserAction() const; // Reads the input command from the user and returns the corresponding action type
	void StartGame();
	void ExecuteAction(ActionType) ;  // Creates an action of the passed actionType and executes it
	void UpdateInterface() const;
	void Exit() const;
	int getGameTime()const; //returns the game time (used for save)


};

