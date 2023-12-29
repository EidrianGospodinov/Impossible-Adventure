#pragma once
#include <iostream>
#include <fstream>
#include <string>
using std::string;
using std::ifstream;

class InputFile
{
	string fileName;
	ifstream file;//declare ifstream file
public:
	InputFile(string fName);
	void readFile();
	
};

