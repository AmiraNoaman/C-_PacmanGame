#pragma once

#include "GameObject.h"

class Obstacle : public GameObject
{

public:

	Obstacle(const Cell & pos); // Constructor
	Obstacle();

	virtual void Move(Grid* pGrid, int moveCount); // No Move for Obstacles

	virtual void Draw(Output* pOut); // Draws the Obstacle

	virtual void Save(ofstream &OutFile, OBJECT_TYPE o);
	//virtual void Open(ifstream &Infile);	// Opens and Read the GameObject parameters from the file

	virtual void Read(ifstream& Infile);
	
	virtual void Collide(GameObject * pOther);

	virtual ~Obstacle(void); // Virtual Destructor
};

