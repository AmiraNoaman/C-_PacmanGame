#include "ShooterEnemy.h"
#include "Player.h"
#include <ctime>
ShooterEnemy::ShooterEnemy(const Cell &pos,int R):Enemy(pos)
{
	Brate = R;
	BCounter = 0;
	for (int i = 0; i < 50; i++)
	{
		Bullets[i] = NULL;
	}
	TimeStep = 0;
}

ShooterEnemy::ShooterEnemy()
{
}

void ShooterEnemy::Move(Grid* pGrid, int moveCount) {
	if (moveCount % Brate == 0) {
		srand(time(NULL));
		DIRECTION rdir = (DIRECTION)(rand() % 4);
		Cell *S;
		switch (rdir) 
		{
		case RIGHT:
			S = new Cell(position.VCell(), position.HCell() + 1);
			break;
		case LEFT:
			S = new Cell(position.VCell(), position.HCell() - 1);
			break;
		case UP:
			S = new Cell(position.VCell()-1, position.HCell());
			break;
		case DOWN:
			S = new Cell(position.VCell()+1, position.HCell());
			break;
		}
		Bullets[BCounter] = new Bullet(*S, rdir);
		pGrid->AddObject(Bullets[BCounter]);
		BCounter++;
	}
}


void ShooterEnemy::Collide(GameObject* pOther) 
{
	Player* P = dynamic_cast<Player*>(pOther);
	if (P != NULL)
		P->DecLives();
}

void ShooterEnemy::Draw(Output* pOut)
{
	pOut->DrawGameObject("images\\MenuItems\\Enemy_Shooter.jpg", position);
}

int ShooterEnemy::getBrate() const
{
	return Brate;
}

void ShooterEnemy::setBrate(int b)
{
	Brate = b;
}

ShooterEnemy::~ShooterEnemy()
{
}

void ShooterEnemy::Read(ifstream& Infile)
{
	Cell c;
	int x = 0, y = 0;
	Infile >> ID >> x >> y >> TimeStep>>Brate;
	if (Brate > 0)
		BCounter++;
	c.SetHCell(x);
	c.SetVCell(y);
	GameObject::setPosition(c);
}