#include "ScoreEnemy.h"
#include "Player.h"
#include <ctime>
ScoreEnemy::ScoreEnemy(const Cell & pos, int TStep):Enemy(pos)
{
	TimeStep = TStep;
	ADraw = false;
	srand(time(NULL) + ID);
	D = (DIRECTION)(rand() % 4);
	while (D == UP || D == DOWN) {
		D = (DIRECTION)(rand() % 4);
	}
}
ScoreEnemy::ScoreEnemy()
{
}
void ScoreEnemy::Move(Grid* pGrid, int moveCount) {
	Cell oldPos = position;
	if (moveCount == TimeStep)
		ADraw = true;
	if (justMoved == false && ADraw) {
		if (moveCount % 3 == 0) {
			D = (DIRECTION)(rand() % 4);
			while (D == UP || D == DOWN) {
				D = (DIRECTION)(rand() % 4);
			}
		}
		if (pGrid->MoveEnemyIfPossible(position, D)) {
			pGrid->RemoveObject(oldPos);
			pGrid->AddObject(this);
			justMoved = true;
		}
	}
}
void ScoreEnemy::Draw(Output* pOut) {
	if (ADraw || UI.InterfaceMode == MODE_CREATE_GRID)
		pOut->DrawGameObject("images/GameObjects/enemy5.jpg", position);
}
void ScoreEnemy::Collide(GameObject * pOther) {
	Player* P = dynamic_cast<Player*>(pOther);
	if (P != NULL) {
		P->SetScore(P->GetScore() - 1);
	}

}

int ScoreEnemy::getTimeStep() const
{
	return TimeStep;
}

ScoreEnemy::~ScoreEnemy()
{
}

void ScoreEnemy::Read(ifstream& Infile)
{
	Cell c;
	int x = 0, y = 0;
	Infile >> ID >> x >> y >> TimeStep;
	c.SetHCell(x);
	c.SetVCell(y);
	GameObject::setPosition(c);
}