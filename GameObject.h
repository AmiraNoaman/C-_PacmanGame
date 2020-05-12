#pragma once
#include <iostream>
using namespace std;

#include "Grid.h"
#include "Output.h"
#include "Input.h"
#include "Cell.h"

// Base Class for All Game Objects ( player, enemies, friendly items, obstacles ...etc. )

class GameObject
{

protected:

	int ID;        // The ID of the GameObject -------> it should be unique among all GameObjects
	Cell position; // The current cell position of the GameObject
	
public:

	GameObject(const Cell & pos); // Constructor for initializing data members
	GameObject();

	Cell GetPosition() const;     // A Getter for position
	void setPosition(Cell);
	// ============ Virtual Functions ============

	virtual void Move(Grid* pGrid, int moveCount) = 0; // Moves the game object (movement depends on GameObject Type, so virtual)
	                                                   // moveCount: is used in killer enemies because it moves once every 3 timesteps

	virtual void Draw(Output* pOut) = 0; // Draws the game object in the window in his position cell 
	                                     // (drawing depends on GameObject Type, so virtual)

	// The following functions should be supported by the GameObject class
	// It should be overridden by each inherited class

	// Decide the parameters that you should pass to each function	

	virtual void Collide(GameObject * pOther) = 0; // Handles what will happen if the current GameObject
	                                                 // collides in the same position with the passed GameObject
												     // it depends on the type of the 2 GameObjects, so virtual

	virtual void Save(ofstream &OutFile, OBJECT_TYPE o) = 0;	// Saves the GameObject parameters to the file

																
	//virtual void Open(ifstream &Infile) = 0;	// Opens and Read the GameObject parameters from the file
	virtual void Read(ifstream& Infile);

	void setID(int i);

	virtual ~GameObject(); // Virtual destructor
};

