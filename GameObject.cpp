#include "GameObject.h"

GameObject::GameObject(const Cell & pos)
{
	position = pos; // Sets Position
	ID = (position.HCell() + 22 - position.VCell());
	///TODO: Initialize ID appropriately with unique value

}

GameObject::GameObject()
{
}

Cell GameObject::GetPosition() const
{
	return position;
}

void GameObject::setPosition(Cell c)
{
	position = c;
}

void GameObject::Read(ifstream & Infile)
{
	//does nothing
}

void GameObject::setID(int i)
{
	ID = i;
}


GameObject::~GameObject()
{
}