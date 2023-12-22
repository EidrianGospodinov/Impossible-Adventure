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

	map<int, Item*> key_items;//not sure about this 2
	map<int, Location*> connections;

public:
	//contructor
	string getName();
	Location(int defaultLocation, string n, string descr, list<Item*>cont);//will add the last 2 later
	~Location();
	void print();//prints the information about the location
	bool hasItem(Item* i);//check if an item is present in the location
	bool take_item(Item* i); //remove an item from the location when taken by the player
	void drop_item(Item* i);//add an item to the location when dropped by the player
	Item* getKey(string& direction);// Function to get the key item required to go in a specific direction
	Location* getConnection(string& direction);// Function to get the connected location in a specific direction

};

