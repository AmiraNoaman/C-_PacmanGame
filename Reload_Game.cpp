#include "Reload_Game.h"

#include "Reload_Game.h"
#include"Grid.h"
#include "Input.h"
#include "Output.h"
#include "ApplicationManager.h"

#include"GameObject.h"
#include "KillerEnemy.h"
#include "ShooterEnemy.h"
#include "HealthEnemy.h"
#include "ScoreEnemy.h"
#include "Gold.h"
#include "Live.h"
#include "Heart.h"
#include "Platinum.h"
#include "Obstacle.h"

#include <cstring>

Reload_Game::Reload_Game(ApplicationManager * pApp) :Action(pApp)
{
}

void Reload_Game::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Loading Game: Please enter the file name");
	filename = pIn->GetSrting(pOut) + ".txt";
	pOut->ClearStatusBar();

	InFile.open(filename, ios::in);
	if (InFile.is_open())
	{
		pOut->PrintMessage(filename + " file has been opened");

		pOut->ClearGridArea();
	}
	else
		pOut->PrintMessage("Error, Cannot open the file");

}

void Reload_Game::Execute()
{
	//This action needs to read some parameters first
	ReadActionParameters();
	if (InFile.is_open())
	{
		Grid* pGrid = pManager->GetGrid();
		//pGrid->Open(InFile);

		int gametime=0,currentTS=0;
		//Infile >> gametime;
		//Infile>>currentTS;
		//set Times

		int obsCount = 0, enemCount = 0, friendlyCount = 0;
		InFile >> obsCount;
		for (int i = 0; i < obsCount; i++)
		{
			GameObject *newObs = new Obstacle();
			newObs->Read(InFile);
			pGrid->AddObject(newObs);
		}
		InFile >> enemCount;
		//string enemyType=" ";
		int enemyType = 0;
		for (int i = 0; i < enemCount; i++)
		{
			InFile >> enemyType;
			//if (enemyType == "ShooterEnemy")
			if (enemyType == 1)
			{
				GameObject* newShooterEnem = new ShooterEnemy();
				newShooterEnem->Read(InFile);
				pGrid->AddObject(newShooterEnem);
			}
			//else if (enemyType == "HealthEnemy")
			else if (enemyType == 2)
			{
				GameObject *newHealthEnem = new HealthEnemy();
				newHealthEnem->Read(InFile);
				pGrid->AddObject(newHealthEnem);
			}

			//else if (enemyType == "KillerEnemy")                                                  
			else if (enemyType == 3)
			{
				GameObject* newKillerEnem = new KillerEnemy();
				newKillerEnem->Read(InFile);
				pGrid->AddObject(newKillerEnem);
			}

			//else if (enemyType == "ScoreEnemy")
			else if (enemyType == 4)
			{
				GameObject* newScoreEnem = new ScoreEnemy();
				newScoreEnem->Read(InFile);
				pGrid->AddObject(newScoreEnem);
			}
		}

		InFile >> friendlyCount;
		int friendlyType = 0;
		for (int i = 0; i < friendlyCount; i++)
		{
			InFile >> friendlyType;
			if (friendlyType == 5)
			{
				GameObject* newGold = new Gold;
				newGold->Read(InFile);
				pGrid->AddObject(newGold);
			}
			else if (friendlyType = 6)
			{
				GameObject *newLive = new Live;
				newLive->Read(InFile);
				pGrid->AddObject(newLive);
			}

			else if (friendlyType = 7)
			{
				GameObject* newPlatinum = new Platinum;
				newPlatinum->Read(InFile);
				pGrid->AddObject(newPlatinum);
			}
			else if (friendlyType = 8)
			{
				GameObject* newHeart = new Heart;
				newHeart->Read(InFile);
				pGrid->AddObject(newHeart);
			}
		}

		GameObject* newPlayer = new Player;
		newPlayer->Read(InFile);
		pGrid->AddObject(newPlayer);
	}
	InFile.close();
}

Reload_Game::~Reload_Game()
{
}
