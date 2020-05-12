#pragma once

#include "UI_Info.h"
#include "DEFS.h"
#include "Cell.h"
#include <fstream>

// forward declarations (the includes are in the cpp)
class Output;
class Input;
class GameObject;
class Player;

class Grid
{
	int moveCounter; // it resets to 0 every 3 timesteps (3 MoveAll)
	                 // it is used in the move of Enemies
	Output * pOut;   // a pointer to the Output object
	Input * pIn;     // a pointer to the Input object
	GameObject * GameObjectList[NumVerticalCells][NumHorizontalCells]; // Array of Pointers to All GameObjects of the Grid Cells

	int obstaclesCount;
	int enemiesCount;
	int friendlyItemsCount;
	int TS;

public:

	Grid(Output * pout, Input * pin);	  // Gives a Grid a Pointer to the Output and Input Objects
	                                      // and makes any needed initializations
	
	///TODO: CMPLETE THE IMPLEMENTATION OF AddObject FUNCTION
	void AddObject(GameObject * pObject); // Adds a GameObject in the List in its position
	                                      // and Draws it in its cell in the Interface

	void RemoveObject(const Cell &  pos); // Removes the GameObject of the passed position from the List
	                                      // and Clears its cell from the Interface

	///TODO: ADD AN IMPLEMENTATION FOR IsObstacle FUNCTION
	bool IsObstacle(const Cell & cell) const; // Checks if the passed position is obstacle

	bool MoveIfPossible(Cell & cell, DIRECTION dir) const; // Moves the entered position in the passed direction if no obstacles
	                                                       // Note: the passed position could be changed
	                                                       // Note: It returns bool indicating if a move occured or not
	bool MoveEnemyIfPossible(Cell & cell, DIRECTION dir) const;
	bool MoveFriendlyItemIfPossible(Cell & cell, DIRECTION dir) const;
	///TODO: ADD AN IMPLEMENTATION FOR DrawAll FUNCTION
	void DrawAll(Output* pOut) const; // Draws the Grid and All its GameObjects

	///TODO: ADD AN IMPLEMENTATION FOR MoveAll FUNCTION
	void MoveAll(); // Moves all the GameObjects of the Grid 
	                // This function should be called each timestep
	
	//Save related Functions
	void SaveAll(ofstream &file, OBJECT_TYPE object);
	int getObstaclesCount()const;
	int getEnemiesCount()const;
	int getFriendlyItemsCount()const;
	
	int getTimeStep()const;
	void SaveGame(ofstream &file, OBJECT_TYPE o);
	//Load related Functions
	//virtual void Open(ifstream &Infile);	// Opens and Read the GameObject parameters from the file

	
	Player* AddPlayer();
	Input * GetInput() const;	// Gets a Pointer to the Input
	Output * GetOutput() const; // Gets a Pointer to the Output 

};

