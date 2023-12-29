#pragma once
#include <iostream>

#include "Item.h"
#include "Location.h"

#include<list>


using std::list;
using std::cout;
using std::endl;

class Player//all the members of the class are static so there to indicate there is only one player
{


	static Location* location;//keep track of player location
	static list<Item*> inventory;//store items in the player inventory
	static int steps;//track number of steps taken

public:
	~Player();
	static void changeLocation(Location* loc);
	static Location *getLocation();
	list<Item*>getInventory() {
		return inventory;
	}
	
	static bool hasItem(Item* i); // Function to check if an item is in the player's inventory
	static bool takeItem(Item* i);// Function to add an item to the player's inventory
	static bool dropItem(Item* i);// Function to remove an item from the player's inventory
	static bool openItem(Item* i);// Function to handle opening an item
	static void printStatus(); // Function to print the player's current status, including location
	
};

