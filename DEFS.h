#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

// This file contains some global constants and definitions to be used in the project.

enum ActionType // The actions supported (you can add more if needed)
{
	//  [1] Actions of Ceate Grid Mode

	ADD_OBSTACLE,		// Add Obstacle Action
	ADD_KILLER_ENEMY,	// Add Killer Enemy Action
	ADD_SHOOTER_ENEMY,
	ADD_HEALTH_ENEMY,
	ADD_SCORE_ENEMY,
	ADD_LIVE_FRIENDLY,
	ADD_GOLD_FRIENDLY,
	ADD_PLATINUM_FRIENDLY,
	ADD_HEART_FRIENDLY,
	LDELETE,
	SET_TIME,
	SAVE,
	OPEN,
	TO_GAME_MODE,		
	EXIT,				


	//  [2] Actions of Game Mode

	CHOOSE_GRID_R,
	CHOOSE_GRID_C,
	GRAB_WEAPON,
	PAUSE,
	RESUME,
	SAVE_GAME,
	RELOAD,
	SWITCH_TOGRID,
	EXIT2,


	//  [3] Others

	EMPTY,				// Empty Area in ToolBar (NOT inside any action icon)
	GRID_AREA,			// Inside Grid Area
	STATUS 				// Inside StatusBar Area
};

#endif