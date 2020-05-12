#pragma once
#include "FriendlyItem.h"
#include "Player.h"
#include"Input.h"

class Platinum :
	public FriendlyItem
{
	int TimeStep;
public:
	Platinum(Cell pos, int TStep);
	Platinum();
	
	virtual void Move(Grid* pGrid, int moveCount);
	virtual void Draw(Output* pOut);
	virtual void Collide(GameObject * pOther);
	int getTimeStep();
	virtual void Read(ifstream& Infile);

	~Platinum();
};

