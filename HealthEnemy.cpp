#include "HealthEnemy.h"
#include "Player.h"
//#include "stdlib.h"
#include <ctime>
HealthEnemy::HealthEnemy(const Cell & pos, int TStep):Enemy(pos)
{
	position = pos;
	TimeStep = TStep;
	ADraw = false;
	srand(time(NULL) + ID);
	D = (DIRECTION)(rand() % 4);
}
HealthEnemy::HealthEnemy()
{
}
void HealthEnemy::Move(Grid* pGrid, int moveCount) {
	Cell oldPos = position;
	if (moveCount == TimeStep)
		ADraw = true;
	if (justMoved == false && ADraw) {
		if (pGrid->MoveEnemyIfPossible(position, D)) {
			pGrid->RemoveObject(oldPos);
			pGrid->AddObject(this);
			justMoved = true;
		}
	}
	if (moveCount % 5 == 0) {
		srand(time(NULL));
		D = (DIRECTION)(rand() % 4);
	}
}
void HealthEnemy::Draw(Output* pOut) {
	if (ADraw || UI.InterfaceMode == MODE_CREATE_GRID)
		pOut->DrawGameObject("images/GameObjects/enemy4.jpg", position);
}
void HealthEnemy::Collide(GameObject * pOther) {
	Player* P = dynamic_cast<Player*>(pOther);
	if (P != NULL) {
		P->SetHealth(P->GetHealth() - 50);
	}
	
}

int HealthEnemy::getTimeStep() const
{
	return TimeStep;
}

void HealthEnemy::Read(ifstream& Infile)
{
	Cell c;
	int x=0 ,y=0;
	Infile >> ID >> x >> y >> TimeStep;
	c.SetHCell(x);
	c.SetVCell(y);
	GameObject::setPosition(c);
}

HealthEnemy::~HealthEnemy()
{
}
