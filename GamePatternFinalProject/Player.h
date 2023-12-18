#pragma once
#include <iostream>

#include "Item.h"
#include "Location.h"

#include<list>


using std::list;
using std::cout;
using std::endl;

class Player
{
	static Location location;
	static list<Item*> inventory;
	static int steps;

public:
	bool hasItem(Item* i);
	bool takeItem(Item* i);
	bool dropItem(Item* i);
	bool openItem(Item* i);
	void printStatus();
	
};

