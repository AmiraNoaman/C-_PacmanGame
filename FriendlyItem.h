#pragma once

#include "GameObject.h"

// Base Class of All Types of FriendlyItems

class FriendlyItem : public GameObject
{
protected: 

	bool justMoved;

public:

	FriendlyItem(const Cell & pos); // Constructor
	FriendlyItem();

	virtual void Move(Grid* pGrid, int moveCount)=0;  

	virtual void Draw(Output* pOut)=0;

	void ResetJustMoved();

	virtual void Save(ofstream &OutFile, OBJECT_TYPE o);

	//virtual void Open(ifstream& Infile);

	virtual ~FriendlyItem(); // Virtual Destructor
};

