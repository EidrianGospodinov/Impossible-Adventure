#pragma once
#include "Item.h"
#include "Player.h"
#include <list>

using std::list;
class Container: public Item
{
	Item *key_item;//item needed to open container
	list<Item*> contents;// list of all the contents of the container
	
	void addToInventory();//private function that is used inside the open function to add to the inventory the content of the container if successfull
public:
	bool isContainer();//overrides the base class item
	bool isOpened=false;//tracks if the container is opened
	bool open() override;//function to open the container, returns true if successfull 

	//constructor
	Container(string name,string descr,Item *item, list<Item*>cont);
	//destructor
	~Container();//deletes the ptr of the container when its not longer needed
};

