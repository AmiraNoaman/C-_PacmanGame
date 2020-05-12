#include "Heart.h"


Heart::Heart(Cell pos, int TStep) :FriendlyItem(pos)
{
	TimeStep = TStep;
}

Heart::Heart()
{
}

void Heart::Move(Grid * pGrid, int moveCount)
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

void Heart::Draw(Output* pOut)
{
	pOut->DrawGameObject("images/MenuItems/Heart.jpg", position); // using the image of the player
}

void Heart::Collide(GameObject * pOther)
{
	Player* P = dynamic_cast<Player*>(pOther);
	if (P != NULL)
	{
		P->SetLives(P->GetLives() + 3);
	}
}

int Heart::getTimeStep()
{
	return TimeStep;
}

void Heart::Read(ifstream& Infile)
{
	Cell c;
	int x = 0, y = 0;
	Infile >> ID >> x >> y >> TimeStep;
	c.SetHCell(x);
	c.SetVCell(y);
	GameObject::setPosition(c);
}

Heart::~Heart()
{
}
