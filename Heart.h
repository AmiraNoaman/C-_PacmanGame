#pragma once
#include "FriendlyItem.h"
#include "Player.h"
#include"Input.h"

class Heart :
	public FriendlyItem
{
	DIRECTION D;
	int TimeStep;
public:
	Heart(Cell pos, int TStep);
	Heart();

	virtual void Move(Grid* pGrid, int moveCount);
	virtual void Draw(Output* pOut);
	virtual void Collide(GameObject * pOther);
	int getTimeStep(); 
	virtual void Read(ifstream& Infile);
	~Heart();
};

