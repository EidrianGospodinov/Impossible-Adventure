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
//using std::istringstream;

class InputFile
{
	string fileName;
	ifstream file;//declare ifstream file

	string name;
	string description;
	Item* keyItem=nullptr;
	list<Item*> contents;
	list<Item*>allItems;


	void processInputItem(string s);
	void processInputLocation(string s);
	void clearVariables();
public:
	InputFile(string fName);
	void readFile();
	
};

