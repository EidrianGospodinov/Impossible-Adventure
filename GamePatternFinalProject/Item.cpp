#include "Item.h"

string Item::getName()
{
	//returns item name
	return name;
}

string Item::getDescription()
{
	//returns item description
	return description;
}

Item::Item(string n, string d) : name(n), description(d)
{

}