#include "KillerEnemy.h"
#include "Player.h"
#include <time.h> // used to in srand to generate random numbers with different seed

KillerEnemy::KillerEnemy(const Cell & pos,int TStep) : Enemy(pos)
{
	TimeStep = TStep;
	justMoved = false;
	ADraw = false;
	//Coll = false;
}

KillerEnemy::KillerEnemy()
{
}

KillerEnemy::~KillerEnemy()
{
}
	
void KillerEnemy::Move(Grid* pGrid, int moveCount)
{
	///TODO: The Implementation of This Function is Left to You
	///      but here are some guideline steps

	// Step 1
	// To move an enemy, we have to check on 2 conditions:
	// A- the moveCount must be 3 because killer enemies moves every 3 timesteps
	// B- the enemy has NOT moved yet during the current timestep

	// Step 2
	// Generate a random movement direction for the enemy
	Cell oldPos = position;
	if (moveCount == TimeStep)
		ADraw = true;
	if ( moveCount % 3 == 0 && justMoved == false && ADraw) {
		srand(time(NULL) + ID); // I added the ID to make the random movement of the enemies different from each other
		DIRECTION rdir = (DIRECTION)(rand() % 4); // 4 DIRECTIONS
		if (pGrid->MoveEnemyIfPossible(position, rdir)) {
			pGrid->RemoveObject(oldPos);
			pGrid->AddObject(this);
			justMoved = true;
		}
	}
	// Step 3
	// Use MoveIfPossible Function of the Grid class to see if no obstacles on the chosen direction

	// Step 4
	// If the movement can be made (no obstacles), then -->
	// A- Remove the Object from its old position in pGrid and hence clear it from the Interface
	// B- Add the Object to the new position and hence draw it in the Interface
	// C- Mark the enemy as moved for the current timestep using the bool of justMoved

	// Note: in Step 4.B of AddObject,
	// inside AddObject of the Grid class, 
	// if the position is occupied by another object, ...
	// --> then AddObject of the Grid class calls function "Collide" between the 2 GameObjects
	
}

void KillerEnemy::Draw(Output* pOut)
{
	if(ADraw || UI.InterfaceMode == MODE_CREATE_GRID)
		pOut->DrawGameObject("images/GameObjects/enemy3.jpg", position); // drawing the image of the killer enemy
}

void KillerEnemy::Collide(GameObject * pOther)
{
	Player* P = dynamic_cast<Player*>(pOther);
	if (P != NULL)
		P->DecLives();
	//Coll = true;
}

int KillerEnemy::getTimeStep() const
{
	return TimeStep;
}

void KillerEnemy::Read(ifstream& Infile)
{
	Cell c;
	int x = 0, y = 0;
	Infile >> ID >> x >> y >> TimeStep;
	c.SetHCell(x);
	c.SetVCell(y);
	GameObject::setPosition(c);
}