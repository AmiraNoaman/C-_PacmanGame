#pragma once

#include "GameObject.h"

// Base Class of All Type of Enemies

class Enemy : public GameObject
{

protected:

	bool justMoved; // A boolean indicating if the Enemy is moved in the current timestep or not
	                // We need this bool, because maybe the enemy moves right or down
	                // Where it will be met again in the next iterations of the move loop
	                // so, we make the move of an enemy with the condition that it didn't move in the current timestep
	
public:

	Enemy(const Cell & pos);  // Constructor
	Enemy();

	void ResetJustMoved(); // Resets the justMoved to false
	                       // It should be used at the end of each timestep

	// ============ Virtual Functions ============

	virtual void Move(Grid* pGrid, int moveCount) = 0;  // Moves the enemy

	virtual void Draw(Output* pOut) = 0; // Draws the enemy on the window in his position

	virtual void Save(ofstream &OutFile, OBJECT_TYPE o);
	//virtual void Open(ifstream& Infile);

	virtual ~Enemy(); // Virtual Destructor

};

