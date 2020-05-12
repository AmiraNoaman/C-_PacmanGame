#pragma once

#include "GameObject.h"

class Player : public GameObject
{
	///TODO: 
	int lives;
	int health;
	int score;
	bool Coll;

public:

	Player(Cell pos); // Constructor
	Player();

	void SetLives(int l);
	int GetLives()const;

	void SetHealth(int h);
	int GetHealth()const;

	void SetScore(int s);
	int GetScore()const;

	void DecLives();

	virtual void Move(Grid* pGrid, int moveCount); // Moves the Player

	virtual void Save(ofstream &OutFile, OBJECT_TYPE o);

	//virtual void Open(ifstream &Infile);	// Opens and Read the GameObject parameters from the file
	virtual void Read(ifstream& Infile);

	virtual void Draw(Output* pOut); // Draws the Player
	virtual void Collide(GameObject * pOther);
};

