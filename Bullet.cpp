#include "Bullet.h"
#include "ShooterEnemy.h"
#include "Player.h"
Bullet::Bullet(const Cell &Pos, DIRECTION R) :Enemy(Pos)
{
	D = R;
}

void Bullet::Move(Grid* pGrid, int moveCount) 
{
		if (justMoved == false) {
			pGrid->RemoveObject(position);
			bool check;
			switch (D) 
			{
			case RIGHT:
			{
				check = position.SetHCell(position.HCell() + 1);
				if (check)
					pGrid->AddObject(this);
				else
					pGrid->RemoveObject(position);
				break;
			}
			case LEFT: 
			{
				check = position.SetHCell(position.HCell() - 1);
				if (check)
					pGrid->AddObject(this);
				else
					pGrid->RemoveObject(position);
				break;
			}
			case UP: 
			{
				check = position.SetVCell(position.VCell() - 1);
				if (check)
					pGrid->AddObject(this);
				else
					pGrid->RemoveObject(position);
				break;
			}
			case DOWN:
			{
				check = position.SetVCell(position.VCell() + 1);
				if (check)
					pGrid->AddObject(this);
				else
					pGrid->RemoveObject(position);
				break;
			}
			}
			justMoved = true;
		}
}

void Bullet::Draw(Output* pOut) 
{
	pOut->DrawGameObject("images\\GameObjects\\Bullet.jpg", position);
}

void Bullet::Collide(GameObject* pOther)
{
	Player* P = dynamic_cast<Player*>(pOther);
	if (P != NULL)
		P->DecLives();
}

Bullet::~Bullet()
{
}
