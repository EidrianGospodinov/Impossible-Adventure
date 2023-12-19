#include "Location.h"

void Location::print()
{
	std::cout << "About "<<name<<": \n"<<description<<"\n"<<"And here is a list of the current items on this location";

	for (Item* i : contents) {
		//print the name of each item on this location
		i->getName();
		std::cout << "\t";
	}
}

bool Location::hasItem(Item* i)
{
	for (Item* x : contents)
	{
		//check if the location has a specific item
		if (x == i)
			return true;
	}
	
	return false;
}

Location::Location(int defaultLocation, string n, string descr, list<Item*> cont):number(defaultLocation, name(n),description(descr))
{
}

bool Location::take_item(Item* i)
{
	//removes item from the location
	contents.remove(i);
	return Location::hasItem(i);
}

void Location::drop_item(Item* i)
{
	//add item to the location
	contents.push_back(i);
	
}

Item* Location::getKey(string& direction)
{
	
	return nullptr;
}

Location* Location::getConnection(string& direction)
{
	
	return nullptr;
}
