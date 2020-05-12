#pragma once

#include "Action.h"

class AddObstacleAction : public Action
{
private:

	// Always add action parameters as private data members

	Cell position; // The Position where the new obstacle will be added -- The only parameter of this action

public:

	AddObstacleAction(ApplicationManager *pApp); // Constructor

	virtual void ReadActionParameters(); // Reads AddObstacle action parameters
	
	virtual void Execute(); // Creates a new Obstacle Object and Adds it in GameObjectList of the Grid

	virtual ~AddObstacleAction(); // Virtual Destructor

};

