#include "Location.h"



void Location::print()
{
	std::cout << "About the "<<name<<": \n"<<description<<"\n"<<"And here is a list of the current items on this location: \n";

	for (Item* i : contents) {
		//print the name of each item on this location
		std::cout << i->getName() << "\t";
		
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

Location::Location(int defaultLocation, string n, string descr, list<Item*> cont):number(defaultLocation), name(n),description(descr),contents(cont)
{
}

bool Location::take_item(Item* i)
{
	//removes item from the location
	if(i!=nullptr)
	contents.remove(i);
	return Location::hasItem(i);
}

Location::~Location()
{
	delete(this);
}

string Location::getName()
{
	if (this != nullptr)
	return name;
	
}

list<Item*> Location::getContents()
{
	return contents;
}

void Location::drop_item(Item* i)
{
	//add item to the location
	if(i!=nullptr)
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
