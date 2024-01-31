#pragma once
#include <string>
using std::string;
class Item
{
	//stores items name and description
	string name="";
	string description;

public:
	virtual bool open();//virtual function that shows if the item is open-false if the item is not container
	virtual bool isContainer();//irtual function thats false unles its overriten by container class
	//public getters to retrive the name and description of items
	string getName();//get name and description
	string getDescription();

	//constructor
	Item(string n, string d);
	~Item();//destroyes item


};

