#pragma once
#include "Enemy.h"
#include "UI_Info.h"
class Bullet : public Enemy
{
private:
	DIRECTION D;
public:
	Bullet(const Cell &Pos,DIRECTION R);
	virtual void Move(Grid* pGrid, int moveCount);
	virtual void Draw(Output* pOut);
	virtual void Collide(GameObject * pOther);
	~Bullet();
};

