#pragma once
#include "Enemy.h"
#include "Bullet.h"

class ShooterEnemy : public Enemy
{
private:
	int Brate;
	int BCounter;
	Bullet* Bullets[50];

	int TimeStep;
public:
	ShooterEnemy(const Cell &pos,int R);
	ShooterEnemy();

	virtual void Move(Grid* pGrid, int moveCount); 
	virtual void Draw(Output* pOut);
	virtual void Collide(GameObject * pOther);
	int getBrate()const;
	void setBrate(int b);
	virtual void Read(ifstream& Infile);
	
	~ShooterEnemy();
};

