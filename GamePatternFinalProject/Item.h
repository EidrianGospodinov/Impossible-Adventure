#pragma once
#include <string>
using std::string;
class Item
{
	//stores items name and description
	string name="";
	string description;

public:
	virtual bool open();
	bool isContainer = false;
	//public getters to retrive the name and description of items
	string getName();
	string getDescription();

	//constructor
	Item(string n, string d);
	~Item();


};

