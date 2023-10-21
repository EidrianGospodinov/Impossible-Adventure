#pragma once
#include <iostream>

#include "GameManager.h"

#define WIDTH 8
#define HEIGHT 8

using std::cout;
using std::endl;
 class Map
{
public:
	void GenerateMap(int Xplayer, int Yplayer, GameManager* manager );
};

