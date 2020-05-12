#pragma once
#include "Enemy.h"
class ScoreEnemy :	public Enemy
{
private:
	int TimeStep;
	bool ADraw;
	DIRECTION D;
public:
	ScoreEnemy(const Cell & pos, int TStep);
	ScoreEnemy();

	virtual void Move(Grid* pGrid, int moveCount);
	virtual void Draw(Output* pOut);
	virtual void Collide(GameObject * pOther);
	int getTimeStep()const;
	
	virtual void Read(ifstream& Infile);
	
	~ScoreEnemy();
};

