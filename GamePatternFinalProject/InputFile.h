#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <list>

#include "Item.h"
#include "Container.h"
#include "Location.h"

using std::string;
using std::ifstream;
using std::list;


class InputFile
{
	
	string fileName;
	ifstream file;//declare ifstream file

	string name;
	string description;
	Item* keyItem=nullptr;
	list<Item*> contents;
	list<Item*>allItems;

	bool newBlock = false;
	string line;
	string keyword;
	string temp;
	int numberOfLocation;
	map<string, Item*>keyItemsMap;
	map<string, int>connectionsMap;

	list<string>listOfDirections{ "NORTH","SOUTH","EAST","WEST","IN","OUT" };
		
	bool searchDirection(string direction);
	void processInputItem();
	void processInputLocation();
	void clearVariables();
	void setInput();
	Item* findItem(string temp);
public:
	static list<Location*>allLocations;
	list<Item*>qwer();
	list<Location*>locqwe();
	InputFile(string fName);
	void readFile();
	
};

