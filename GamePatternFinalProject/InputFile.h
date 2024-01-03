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
	
	ifstream file;//declare ifstream file
	// The InputFile class reads input from a file, processes the data, and creates items and locations.
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

	list<string>listOfDirections{ "NORTH","SOUTH","EAST","WEST","IN","OUT" };//list of all directions
		
    // Check if the direction is valid
    bool searchDirection(string direction);
    // Process input and create a new item
    void processInputItem();
    // Process input and create a new location
    void processInputLocation();
    // Clear variables after processing a block
    void clearVariables();
    // Set input values based on the current line
    void setInput();
    // Find an item by name
    Item* findItem(string temp);

public:
    // Static list to store all created locations
    static list<Location*> allLocations;

    

    // Constructor
    InputFile(string fName);
    // Read file and process data
    void readFile();
	
};

