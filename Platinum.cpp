#include "Platinum.h"


Platinum::Platinum(Cell pos,int TStep) :FriendlyItem(pos)
{
	TimeStep = TStep;
}

Platinum::Platinum()
{
}

void Platinum::Move(Grid * pGrid, int moveCount)
{
}

void Platinum::Draw(Output* pOut)
{
	pOut->DrawGameObject("images/MenuItems/platinum.jpg", position); // using the image of the player
}

void Platinum::Collide(GameObject * pOther)
{
	Player* P = dynamic_cast<Player*>(pOther);
	if (P != NULL) 
	{
		P->SetHealth(P->GetHealth() * 1.5);
		P->SetScore(P->GetScore() + 1);
	}
}

int Platinum::getTimeStep()
{
	return TimeStep;
}

void Platinum::Read(ifstream& Infile)
{
	Cell c;
	int x = 0, y = 0;
	Infile >> ID >> x >> y >> TimeStep;
	c.SetHCell(x);
	c.SetVCell(y);
	GameObject::setPosition(c);
}

Platinum::~Platinum()
{
}
