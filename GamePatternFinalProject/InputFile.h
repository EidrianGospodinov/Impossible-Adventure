#pragma once
#include <iostream>
#include <fstream>
#include <string>

#include "Item.h"

using std::string;
using std::ifstream;
//using std::istringstream;

class InputFile
{
	string fileName;
	ifstream file;//declare ifstream file

	string name;
	string description;

	void processInputItem(string s);
	void processInputLocation(string s);
public:
	InputFile(string fName);
	void readFile();
	
};

