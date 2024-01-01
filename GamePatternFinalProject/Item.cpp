#include "Item.h"

bool Item::open()
{
	return false;
}

bool Item::isContainer()
{
	return false;
}

string Item::getName()
{
	//returns item name
	if(name!= " ")
	return name;
	return " ";
}

string Item::getDescription()
{
	//returns item description
	return description;
}

Item::Item(string n, string d) : name(n), description(d)
{

}

Item::~Item()
{
	delete(this);
}
