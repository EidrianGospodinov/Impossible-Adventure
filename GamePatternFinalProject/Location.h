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
	int number;
	string direction;//it looks needed
	string name;
	string description;
	list<Item*> contents;

	map<string, Item*> key_items;//not sure about this 2
	map<Location*, string > connections;

public:
	void print();
	bool take_item(Item* i);
	void drop_item(Item* i);
	Item* getKey(string& direction);
	Location* getConnection(string& direction);

};

