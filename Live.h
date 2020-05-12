#pragma once
#include "FriendlyItem.h"
#include "Player.h"
#include"Input.h"

class Live :
	public FriendlyItem
{
	int L;
	int TimeStep;

public:
	Live(Cell pos,int TStep,int l);
	Live();

	void SetL(int l);
	int GetL()const;

	virtual void Move(Grid* pGrid, int moveCount);
	virtual void Draw(Output* pOut);
	virtual void Collide(GameObject * pOther);
	int getTimeStep();
	virtual void Read(ifstream& Infile);
	~Live();
};

