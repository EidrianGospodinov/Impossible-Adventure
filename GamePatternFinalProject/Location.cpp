#include "Location.h"

void Location::print()
{
	std::cout << "About "<<name<<": \n"<<description<<"\n"<<"And here is a list of the current items on this location";

	for (Item* i : contents) {
		i->getName();
		std::cout << "\t";
	}
}

bool Location::hasItem(Item* i)
{
	for (Item* x : contents)
	{
		if (x == i)
			return true;
	}
	//    //check if the names of x and i are the same
	return false;
}

bool Location::take_item(Item* i)
{
	contents.remove(i);
	return Location::hasItem(i);
}

void Location::drop_item(Item* i)
{
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
