#pragma once
#include <iostream>
#include "Item.h"


#include<string>
#include<list>
#include<map>

using std::string;
using std::list;
using std::map;


class Location
{
	
	int number;//identifier for the the location
	//string direction;//it looks needed
	string name;//name of the locstion
	string description;//description of the location
	list<Item*> contents;//all items inside the location

	map<string, Item*> key_items;//a map that hold the item needed and direction to move in said direction
	map<string, int> connections;//a map that hold the number of location the direction needed to go to that direction

public:
	
	list<Item*>getContents();//function that return a list to all the items on the location
	string getName();//returns the name of the location

	//constructor 
	Location(int defaultLocation, string n, string descr, 
		list<Item*>cont, map<string, Item*>keyItems, map<string, int>connect);
	//destructor
	~Location();
	void print();//prints the information about the location
	bool hasItem(Item* i);//check if an item is present in the location
	bool take_item(Item* i); //remove an item from the location when taken by the player
	void drop_item(Item* i);//add an item to the location when dropped by the player
	Item* getKey(string& direction);// Function to get the key item required to go in a specific direction
	Location* getConnection(string& direction);// Function to get the connected location in a specific direction

};

