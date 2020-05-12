#include "Grid.h"

#include "Output.h"
#include "Input.h"
#include "Enemy.h"
#include "FriendlyItem.h"
#include "Obstacle.h"
#include "Player.h"
#include"ApplicationManager.h"
#include <ctime>

Grid::Grid(Output * pout, Input * pin) : moveCounter(0), pOut(pout), pIn(pin)
{
	// initializes all the GameObject pointer of the List to NULL
	for (int i = 0; i < NumVerticalCells; i++)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			GameObjectList[i][j] = NULL;
		}
	}
	//initializing game objects counts
	obstaclesCount = 0;
	enemiesCount = 0;
	friendlyItemsCount = 0;
}

void Grid::AddObject(GameObject * pObject)  // think if a validation is needed
{
	// Handling the case of NO collision
	Cell pos = pObject->GetPosition();
	if (pos.IsValidCell())
	{
		///TODO: Check if the Cell is NOT Empty
		//       and if yes, call function Collide on the 2 GameObjects
		//       which should handle what to do in the collision between these 2 GameObject types
		//       Collide() is a virtual function in GameObject class
		if (GameObjectList[pos.VCell()][pos.HCell()] != NULL) {
			pObject->Collide(GameObjectList[pos.VCell()][pos.HCell()]);
		}
		if (dynamic_cast<Enemy*>(pObject) != NULL &&
			dynamic_cast<Player*>(GameObjectList[pos.VCell()][pos.HCell()]) != NULL) {
			Cell X = GameObjectList[pos.VCell()][pos.HCell()]->GetPosition();
			GameObjectList[X.VCell()][X.HCell()] = GameObjectList[pos.VCell()][pos.HCell()];
			GameObjectList[X.VCell()][X.HCell()]->Draw(pOut);
			GameObjectList[pos.VCell()][pos.HCell()] = pObject;
			pObject->Draw(pOut);
		}
		else if (dynamic_cast<Enemy*>(GameObjectList[pos.VCell()][pos.HCell()]) != NULL &&
			dynamic_cast<Player*>(pObject) != NULL) {
			Cell X = pObject->GetPosition();
			GameObjectList[X.VCell()][X.HCell()] = pObject;
		}/////
		else if (dynamic_cast<FriendlyItem*>(pObject) != NULL &&
			dynamic_cast<Player*>(GameObjectList[pos.VCell()][pos.HCell()]) != NULL) {
			Cell X = GameObjectList[pos.VCell()][pos.HCell()]->GetPosition();
			GameObjectList[X.VCell()][X.HCell()] = GameObjectList[pos.VCell()][pos.HCell()];
			GameObjectList[X.VCell()][X.HCell()]->Draw(pOut);
			GameObjectList[pos.VCell()][pos.HCell()] = pObject;
			pObject->Draw(pOut);
		}
		else if (dynamic_cast<FriendlyItem*>(GameObjectList[pos.VCell()][pos.HCell()]) != NULL &&
			dynamic_cast<Player*>(pObject) != NULL) {
			Cell X = pObject->GetPosition();
			GameObjectList[X.VCell()][X.HCell()] = pObject;
		}
		else {
			GameObjectList[pos.VCell()][pos.HCell()] = pObject;
			pObject->Draw(pOut);
		}

		//Incrementing the counts of this object type
		Obstacle*o = dynamic_cast<Obstacle*>(pObject);
		FriendlyItem *f = dynamic_cast<FriendlyItem*>(pObject);
		Enemy* e = dynamic_cast<Enemy*>(pObject);

		if (o)
			obstaclesCount++;
		else if (f)
			friendlyItemsCount++;
		else if (e)
			enemiesCount++;
	}
}

void Grid::RemoveObject(const Cell & pos)
{
	if (pos.IsValidCell())
	{
		GameObjectList[pos.VCell()][pos.HCell()] = NULL;
		pOut->ClearCell(pos);
	}
}

bool Grid::IsObstacle(const Cell & cell) const 
{
	///TODO: ADD AN IMPLEMENTATION FOR THIS FUNCTION

	// Here are Some Guideline Steps

	// Step 1:
	// Check if the passed cell is a valid cell (in the range of the Grid Cells)

	// Step 2:
	// Check if the GameObject in the position the passed cell is an OBSTACLE
	Obstacle* Check = dynamic_cast<Obstacle*>(GameObjectList[cell.VCell()][cell.HCell()]);
	if (Check != NULL)
		return true;
	else
		return false;	
}

bool Grid::MoveIfPossible(Cell & cell, DIRECTION dir) const
{
	int vCell = cell.VCell();
	int hCell = cell.HCell();
	Cell tried (vCell, hCell);

	switch(dir)
	{
	case UP:
		tried.SetVCell(vCell - 1); // the setter here only set if valid
		if ( ! IsObstacle(tried) )
		{
			return cell.SetVCell(vCell - 1); // the setter sets only if in the the cell is in grid range
		}
		break;
	case DOWN:
		tried.SetVCell(vCell + 1); // the setter here only set if valid
		if ( ! IsObstacle(tried) )
		{
			return cell.SetVCell(vCell + 1); // the setter sets only if in the the cell is in grid range
		}
		break;
	case LEFT:
		tried.SetHCell(hCell - 1); // the setter here only set if valid
		if ( ! IsObstacle(tried) )
		{
			return cell.SetHCell(hCell - 1); // the setter sets only if in the the cell is in grid range
		}
		break;
	case RIGHT:
		tried.SetHCell(hCell + 1); // the setter here only set if valid
		if ( ! IsObstacle(tried) )
		{
			return cell.SetHCell(hCell + 1); // the setter sets only if in the the cell is in grid range
		}
		break;
	}
	return false; // invalid direction
}
bool Grid::MoveEnemyIfPossible(Cell & cell, DIRECTION dir) const {
	int vCell = cell.VCell();
	int hCell = cell.HCell();
	Cell tried(vCell, hCell);
	Enemy* E;
	switch (dir)
	{
	case UP:
		tried.SetVCell(vCell - 1); // the setter here only set if valid
		E = dynamic_cast<Enemy*>(GameObjectList[tried.VCell()][tried.HCell()]);
		if (!IsObstacle(tried) && E == NULL)
		{
			return cell.SetVCell(vCell - 1); // the setter sets only if in the the cell is in grid range
		}
		break;
	case DOWN:
		tried.SetVCell(vCell + 1); // the setter here only set if valid
		E = dynamic_cast<Enemy*>(GameObjectList[tried.VCell()][tried.HCell()]);
		if (!IsObstacle(tried)&& E == NULL)
		{
			return cell.SetVCell(vCell + 1); // the setter sets only if in the the cell is in grid range
		}
		break;
	case LEFT:
		tried.SetHCell(hCell - 1); // the setter here only set if valid
		E = dynamic_cast<Enemy*>(GameObjectList[tried.VCell()][tried.HCell()]);
		if (!IsObstacle(tried) && E == NULL)
		{
			return cell.SetHCell(hCell - 1); // the setter sets only if in the the cell is in grid range
		}
		break;
	case RIGHT:
		tried.SetHCell(hCell + 1); // the setter here only set if valid
		E = dynamic_cast<Enemy*>(GameObjectList[tried.VCell()][tried.HCell()]);
		if (!IsObstacle(tried) && E == NULL)
		{
			return cell.SetHCell(hCell + 1); // the setter sets only if in the the cell is in grid range
		}
		break;
	}
	return false; // invalid direction
}

bool Grid::MoveFriendlyItemIfPossible(Cell & cell, DIRECTION dir) const
{
	int vCell = cell.VCell();
	int hCell = cell.HCell();
	Cell tried(vCell, hCell);
	FriendlyItem*F;
	switch (dir)
	{
	case UP:
		tried.SetVCell(vCell - 1); // the setter here only set if valid
		F= dynamic_cast<FriendlyItem*>(GameObjectList[tried.VCell()][tried.HCell()]);
		if (!IsObstacle(tried) && F == NULL)
		{
			return cell.SetVCell(vCell - 1); // the setter sets only if in the the cell is in grid range
		}
		break;
	case DOWN:
		tried.SetVCell(vCell + 1); // the setter here only set if valid
		F = dynamic_cast<FriendlyItem*>(GameObjectList[tried.VCell()][tried.HCell()]);
		if (!IsObstacle(tried) && F == NULL)
		{
			return cell.SetVCell(vCell + 1); // the setter sets only if in the the cell is in grid range
		}
		break;
	case LEFT:
		tried.SetHCell(hCell - 1); // the setter here only set if valid
		F = dynamic_cast<FriendlyItem*>(GameObjectList[tried.VCell()][tried.HCell()]);
		if (!IsObstacle(tried) && F == NULL)
		{
			return cell.SetHCell(hCell - 1); // the setter sets only if in the the cell is in grid range
		}
		break;
	case RIGHT:
		tried.SetHCell(hCell + 1); // the setter here only set if valid
		F = dynamic_cast<FriendlyItem*>(GameObjectList[tried.VCell()][tried.HCell()]);
		if (!IsObstacle(tried) && F == NULL)
		{
			return cell.SetHCell(hCell + 1); // the setter sets only if in the the cell is in grid range
		}
		break;
	}
	return false; // invalid direction
}


void Grid::DrawAll(Output* pOut) const	
{
	///TODO: ADD AN IMPLEMENTATION FOR THIS FUNCTION

	// Here are Some Guidelines Steps

	// Step 1:
	// Draw Empty Grid

	// Step 2:
	// Draw all the GameObjects of the Grid
	pOut->ClearGridArea();
	for (int i = 0; i < NumVerticalCells; i++) {
		for (int j = 0; j < NumHorizontalCells; j++) {
			if (GameObjectList[i][j] != NULL)
				GameObjectList[i][j]->Draw(pOut);
		}
	}
}

void Grid::MoveAll()
{
	///TODO: ADD AN IMPLEMENTATION FOR THIS FUNCTION
	
	// Here are Some Guidelines Steps

	// Step 1:
	// Increment the moveCounter

	// Step 2:
	// Move all the GameObjects of the Grid
	
	// Step 3:
	// ResetJustMoved boolean of all Enemies in the List
	moveCounter++;
	for (int i = 0; i < NumVerticalCells; i++) {
		for (int j = 0; j < NumHorizontalCells; j++) {
			if (GameObjectList[i][j] != NULL)
				GameObjectList[i][j]->Move(this, moveCounter);
			Enemy* E = dynamic_cast<Enemy*>(GameObjectList[i][j]);
			if (E != NULL)
				E->ResetJustMoved();
			FriendlyItem* F= dynamic_cast<FriendlyItem*>(GameObjectList[i][j]);
			if (F != NULL)
				F->ResetJustMoved();
		}
	}
}
Player* Grid::AddPlayer() {
	srand(time(NULL));
	int H = rand() % NumHorizontalCells;
	int V = rand() % NumVerticalCells;
	Cell C(V, H);
	//Cell C(0, 1);
	Player *P1 = new Player(C);
	AddObject(P1);
	return P1;
}
Input * Grid::GetInput() const
{
	return pIn;
}

Output * Grid::GetOutput() const
{
	return pOut;
}

int Grid::getEnemiesCount()const
{
	return enemiesCount;
}

int Grid::getFriendlyItemsCount()const
{
	return friendlyItemsCount;
}

int Grid::getTimeStep() const
{
	return TS;
}

void Grid::SaveGame(ofstream & file, OBJECT_TYPE o)
{
	//Game Time
	//Current Timestep
	//file<< getTimeStep();
	int obsCnt = 0;
	int enemCnt = 0;
	int friendCnt = 0;

	for (int i = 0; i < NumVerticalCells; i++)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			if (dynamic_cast<Obstacle*>(GameObjectList[i][j]))
			{
				obsCnt++;
			}
			else if (dynamic_cast<Enemy*>(GameObjectList[i][j]))
			{
				enemCnt++;
			}
			else if (dynamic_cast<FriendlyItem*>(GameObjectList[i][j]))
			{
				friendCnt++;
			}
		}
	}

	file << obsCnt<<endl;
	for (int i = 0; i < NumVerticalCells; i++)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			if (dynamic_cast<Obstacle*>(GameObjectList[i][j]))
			{
				((Obstacle*)GameObjectList[i][j])->Save(file, o);
			}
		}
	}

	file << enemCnt << endl;
	for (int i = 0; i < NumVerticalCells; i++)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			if (dynamic_cast<Enemy*>(GameObjectList[i][j]))
				((Enemy*)GameObjectList[i][j])->Save(file, o);
		}
	}

	file << friendCnt << endl;
	for (int i = 0; i < NumVerticalCells; i++)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			if (dynamic_cast<FriendlyItem*>(GameObjectList[i][j]))
				((FriendlyItem*)GameObjectList[i][j])->Save(file, o);
		}
	}

	for (int i = 0; i < NumVerticalCells; i++)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			if (dynamic_cast<Player*>(GameObjectList[i][j]))
			{
				((Player*)GameObjectList[i][j])->Save(file, o);
			}
		}
	}
}

int Grid::getObstaclesCount()const
{
	return obstaclesCount;
}

void Grid::SaveAll(ofstream &file, OBJECT_TYPE object)
{
	//ApplicationManager* pManager=NULL;

//		file << pManager->getGameTime();
	switch (object)
	{
	case OBSTACLE__:
		file << getObstaclesCount() << endl;
		break;
	case ENEMY__:
		file << getEnemiesCount() << endl;
		break;
	case FRIENDLY_ITEM__:
		file << getFriendlyItemsCount() << endl;
		break;
	case PLAYER__:
		break;
	default:
		break;
	}

	for (int i = 0; i < NumVerticalCells; i++)
	{
		for (int j = 0; j < NumHorizontalCells; j++)
		{
			if (GameObjectList[i][j])
			{
				switch (object)
				{
				case OBSTACLE__:
					((Obstacle*)GameObjectList[i][j])->Save(file, object);
					break;
				case PLAYER__:
					break;
				case ENEMY__:
					((Enemy*)GameObjectList[i][j])->Save(file, object);
					break;
				case FRIENDLY_ITEM__:
					((FriendlyItem*)GameObjectList[i][j])->Save(file, object);
					break;
				default:
					break;
				}
			}
			//if(dynamic_cast<Obstacle*>(GameObjectList[i][j]))
				//((Obstacle*)GameObjectList[i][j])->Save(file, object);
		}
	}


	//for (int i = 0; i < NumVerticalCells; i++)
	//{
	//	for (int j = 0; j < NumHorizontalCells; j++)
	//	{
	//		if (dynamic_cast<Enemy*>(GameObjectList[i][j]))
	//			((Enemy*)GameObjectList[i][j])->Save(file, object);
	//	}
	//}


	//for (int i = 0; i < NumVerticalCells; i++)
	//{
	//	for (int j = 0; j < NumHorizontalCells; j++)
	//	{
	//		if (dynamic_cast<FriendlyItem*>(GameObjectList[i][j]))
	//			((FriendlyItem*)GameObjectList[i][j])->Save(file, object);
	//	}
	//}
}