#pragma once
#include <iostream>

#include "Item.h"
#include "Location.h"

#include<vector>

using std::vector;


class Player
{
	static Location* location;
	static vector<Item*> inventory;
	static int steps;

public:
	bool hasItem(Item* i);
	bool takeItem(Item* i);
	bool dropItem(Item* i);
	bool openItem(Item* i);
	void printStatus();
	
};

