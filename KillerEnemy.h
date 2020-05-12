#pragma once

#include "Enemy.h"

class KillerEnemy : public Enemy
{
	int TimeStep;
	bool ADraw;
	bool Coll;
public:

	KillerEnemy(const Cell & pos,int TStep);
	KillerEnemy();

	virtual void Move(Grid* pGrid, int moveCount);  // Moves the killer enemy

	virtual void Draw(Output* pOut); // Draws the killer enemy on the window in his position
	
	virtual void Collide(GameObject * pOther);
	
	int getTimeStep()const;
	virtual void Read(ifstream& Infile);

	virtual ~KillerEnemy();
};

