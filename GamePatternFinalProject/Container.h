#pragma once
#include "Item.h"
#include "Player.h"
#include <list>

using std::list;
class Container: public Item
{
	bool isOpened;
	Item *key_item;
	list<Item*> contents;
	
public:
	bool open();
	void addToInventory();


};

