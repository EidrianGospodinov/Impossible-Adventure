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
	static bool hasItem(Item* i);
	static bool takeItem(Item* i);//not the best name to add item to inventory
	static bool dropItem(Item* i);
	static bool openItem(Item* i);
	static void printStatus();
	
};

