#pragma once
#include "Enemy.h"
class HealthEnemy : public Enemy
{
	int TimeStep;
	bool ADraw;
	DIRECTION D;
public:
	HealthEnemy(const Cell & pos, int TStep);

	HealthEnemy();
	virtual void Move(Grid* pGrid, int moveCount); 
	virtual void Draw(Output* pOut);
	virtual void Collide(GameObject * pOther);
	int getTimeStep()const;

	virtual void Read(ifstream& Infile);
	~HealthEnemy();
};

