#pragma once
#include <iostream>


#include "Checkpoint.h"
#include "GameManager.h"
#include<vector>



#define WIDTH 15
#define HEIGHT 15

using std::cout;
using std::endl;
using std::vector;
 class Map
{
public:
	void GenerateMap(int Xplayer, int Yplayer, GameManager* manager );
	void GenerateCheckpoint(int checkNum,int xPos, int yPos);

	vector<Checkpoint*> CheckpointHolder;
};

