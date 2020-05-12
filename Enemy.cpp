#include "Enemy.h"
#include "HealthEnemy.h"
#include "KillerEnemy.h"
#include "ShooterEnemy.h"
#include "ScoreEnemy.h"

Enemy::Enemy(const Cell & pos) : GameObject(pos), justMoved(false)
{

}

Enemy::Enemy():justMoved(false)
{
}

Enemy::~Enemy(void)
{
}

void Enemy::ResetJustMoved()
{
	justMoved = false;
}

void Enemy::Save(ofstream &OutFile, OBJECT_TYPE o)
{
	Cell m = GameObject::GetPosition();
	int x = m.HCell();
	int y = m.VCell();
	if (OutFile.is_open())
	{
		ShooterEnemy* sh = dynamic_cast<ShooterEnemy*>(this);
		KillerEnemy *k = dynamic_cast<KillerEnemy*>(this);
		ScoreEnemy* s = dynamic_cast<ScoreEnemy*>(this);
		HealthEnemy*h = dynamic_cast<HealthEnemy*>(this);

		if (sh)
			OutFile << "ShooterEnemy" << "\t" << GameObject::ID << "\t" << x << " " << y << "\t" << sh->getBrate() << endl;
		else if (k)
			OutFile << "KillerEnemy" << "\t" << GameObject::ID << "\t" << x << " " << y << "\t" << k->getTimeStep() << endl;
		else if (s)
			OutFile << "ScoreEnemy" << "\t" << GameObject::ID << "\t" << x << " " << y << "\t" << s->getTimeStep() << endl;
		else if (h)
			OutFile << "HealthEnemy" << "\t" << GameObject::ID << "\t" << x << " " << y << "\t" << h->getTimeStep() << endl;
	}
}

