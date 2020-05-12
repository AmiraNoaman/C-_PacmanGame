#include "Gold.h"


Gold::Gold(Cell pos, int TStep):FriendlyItem(pos)
{
	TimeStep = TStep;
}

Gold::Gold()
{
}

void Gold::Move(Grid * pGrid, int moveCount)
{
}

void Gold::Draw(Output* pOut)
{
	pOut->DrawGameObject("images/GameObjects/gold.jpg", position); // using the image of the player
}

void Gold::Collide(GameObject * pOther)
{
	Player* P = dynamic_cast<Player*>(pOther);
	if (P != NULL)
	{
		P->SetScore(P->GetScore() +1);
	}
}

int Gold::getTimeStep()
{
	return TimeStep;
}

void Gold::Read(ifstream& Infile)
{
	Cell c;
	int x = 0, y = 0;
	Infile >> ID >> x >> y >> TimeStep;
	c.SetHCell(x);
	c.SetVCell(y);
	GameObject::setPosition(c);
}

Gold::~Gold()
{
}
