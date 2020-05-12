#include "Obstacle.h"


Obstacle::Obstacle(const Cell & pos) : GameObject(pos)
{
}

Obstacle::Obstacle()
{
}

Obstacle::~Obstacle(void)
{
}

void Obstacle::Move(Grid* pGrid, int moveCount) 
{
	// empty implementation
}

void Obstacle::Draw(Output* pOut)
{
	pOut->DrawObstacle(position);
}

void Obstacle::Collide(GameObject * pOther)
{
}

void Obstacle::Save(ofstream &OutFile, OBJECT_TYPE o)
{
	Cell m = GameObject::GetPosition();
	int x = m.HCell();
	int y = m.VCell();
	if (o == OBSTACLE__)
	{
		OutFile << GameObject::ID << "\t" << x << " " << y << endl;
	}
}

void Obstacle::Read(ifstream & Infile)
{
	int  x = 0, y = 0;
	Cell c;
	Infile >> ID >> x >> y;
	//GameObject::setID(id);
	c.SetHCell(x);
	c.SetVCell(y);
	GameObject::setPosition(c);
}

