#include "Location.h"
#include "InputFile.h"



void Location::print()
{
	std::cout << "About the "<<name<<": \n"<<description<<"\n"<<"And here is a list of the current items on this location: \n";

	for (Item* i : contents) {
		//print the name of each item on this location
		if(i!=nullptr)
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

//constructor that gives all the parameter to the location
Location::Location(int defaultLocation, string n, string descr, list<Item*> cont,
	map<string, Item*>keyItems, map<string, int>connect) :number(defaultLocation), name(n),
		description(descr),contents(cont),key_items(keyItems),connections(connect)
{
}

bool Location::take_item(Item* i)
{
	//removes item from the location, if the item is not null
	if(i!=nullptr)
	contents.remove(i);
	return Location::hasItem(i);
}

//delete location when removed
Location::~Location()
{
	delete(this);
}

string Location::getName()//return the name of the location
{
	if (this != nullptr)
	return name;
	
}

list<Item*> Location::getContents()//return all the contents of the location
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
	if(key_items.count(direction))//if the direction excist on the map with the given direction 
	return key_items[direction];//return the item
	return nullptr;//if not return nullptr
}

Location* Location::getConnection(string& direction)//get location this direction leads to
{
		for (auto i : InputFile::allLocations)
		{
			if (connections[direction] == i->number) //if the location is the same return the location
				return i;
			
		}
		cout << "You can not travel in this direction: " << direction << endl;
		//inform the player that he wont be able to move in that direction
		return nullptr;
}
