#pragma once
#include "FriendlyItem.h"
#include "Player.h"
#include"Input.h"

class Gold :
	public FriendlyItem
{
	int TimeStep;
public:
	Gold(Cell pos, int TStep);
	Gold();

	virtual void Move(Grid* pGrid, int moveCount);
	virtual void Draw(Output* pOut);
	virtual void Collide(GameObject * pOther);
	int getTimeStep();
	virtual void Read(ifstream& Infile);
	~Gold();
};

