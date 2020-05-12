#include "Player.h"
#include "Enemy.h"
#include "FriendlyItem.h"
#include <ctime>


Player::Player(Cell pos) : lives(3), health(100), score(0), GameObject(pos)
{
	// Makes all the needed initialization
	Coll = false;
}

Player::Player()
{
}

void Player::SetLives(int l)
{
	lives = l;
}

int Player::GetLives() const
{
	return lives;
}

void Player::SetHealth(int h)
{
	health = h;
	if (health < 0) {
		SetLives(GetLives() - 1);
		health = 100;
	}	
	int H = rand() % NumHorizontalCells;
	int V = rand() % NumVerticalCells;
	position.SetHCell(H);
	position.SetVCell(V);
}

int Player::GetHealth() const
{
	return health;
}

void Player::SetScore(int s)
{
	if (s > 0)
		score = s;
	else
		score = 0;
	int H = rand() % NumHorizontalCells;
	int V = rand() % NumVerticalCells;
	position.SetHCell(H);
	position.SetVCell(V);
}

int Player::GetScore() const
{
	return score;
}

void Player::Move(Grid* pGrid, int moveCount)
{
	
	// Take a copy of the position before change
	Cell oldPosition = position;

	// Try to take a Move from Keyboard
	Input * pIn = pGrid->GetInput();
	DIRECTION dir = pIn->TakeMoveDirection(position);

	// Check if the Move is Possible (No Obstacles)
	pGrid->MoveIfPossible(position, dir); // if the move is possible, position will be changed (passed by ref)

	// If the position changed ( valid move )
	if (position != oldPosition)
	{
		pGrid->RemoveObject(oldPosition); // Removes it from the old position and Clears it from the Interface
		pGrid->AddObject(this); // Adds it to the new position and Draws it in the Interface
									// inside AddObject of the Grid, 
									// if the position is occupied by another object, ...
									// --> then AddObject calls function Collide between the 2 GameObjects
	}
}

void Player::Draw(Output* pOut)
{
	pOut->DrawGameObject("images/GameObjects/mario.jpg", position); // using the image of the player
}

void Player::Collide(GameObject * pOther) 
{
	Enemy* E = dynamic_cast<Enemy*>(pOther);
	FriendlyItem* F = dynamic_cast<FriendlyItem*>(pOther);

	if(E!=NULL)
		E->Collide(this);
	else if (F != NULL)
		F->Collide(this);
}

void Player::DecLives() {
	lives--;
	int H = rand() % NumHorizontalCells;
	int V = rand() % NumVerticalCells;
	position.SetHCell(H);
	position.SetVCell(V);
}

void Player::Save(ofstream &OutFile, OBJECT_TYPE o)
{
	Cell c = GameObject::GetPosition();
	int x = c.HCell();
	int y = c.VCell();
	int l, h, s;
	OutFile << ID<<"\t" << x<<" " << y <<"\t"<< GetLives()<<"\t"<< GetHealth()<<"\t" << GetScore() << endl;
}

void Player::Read(ifstream & Infile)
{
	int id, x, y;
	Cell c;
	Infile >> ID >> x >> y>>lives>>health>>score;
	c.SetHCell(x);
	c.SetVCell(y);
	GameObject::setPosition(c);
}
