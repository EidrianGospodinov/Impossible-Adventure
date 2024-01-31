#include "Item.h"

bool Item::open()//when open is used, return false if the item is not derrived by container class
{
	return false;
}

bool Item::isContainer()//tell the that and item that is not derrived by container is not one
{
	return false;
}

string Item::getName()
{
	//gets the name of the item
	return name;
	
}

string Item::getDescription()
{
	//returns item description
	return description;
}
//constructor that gives name and description to the item
Item::Item(string n, string d) : name(n), description(d)
{

}

Item::~Item()
{//delete item
	delete(this);
}
