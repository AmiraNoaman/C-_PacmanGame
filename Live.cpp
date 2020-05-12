#include "Live.h"

Live::Live(Cell pos,int TStep,int l):FriendlyItem(pos)
{
	TimeStep = TStep;
	L = l;
}

Live::Live()
{
}

void Live::SetL(int l)
{
	L = l;
}

int Live::GetL() const
{
	return L;
}

void Live::Move(Grid * pGrid, int moveCount)
{
	
}

void Live::Draw(Output* pOut)
{
	pOut->DrawGameObject("images/MenuItems/life.jpg", position);
}

void Live::Collide(GameObject * pOther)
{
	Player* P = dynamic_cast<Player*>(pOther);
	if (P != NULL) 
	{
		P->SetLives(P->GetLives() + 1);
	}
}

int Live::getTimeStep()
{
	return TimeStep;
}

void Live::Read(ifstream& Infile)
{
	Cell c;
	int x = 0, y = 0;
	Infile >> ID >> x >> y >> TimeStep>>L;
	c.SetHCell(x);
	c.SetVCell(y);
	GameObject::setPosition(c);
}

Live::~Live()
{
}
