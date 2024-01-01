#include "Container.h"

bool Container::open()
{
    //Check if the container is empty or its already opened
    if(key_item==nullptr || isOpened)
    return false;

    //returns false if the player does not have the item needed to open
    if (!Player::hasItem(key_item))
        return false;

    //add the contents to the players inventory
    addToInventory();

    //shows that the container is opened
    isOpened = true;

    return true;



}

Container::Container(string name, string descr, Item* item, list<Item*> cont): Item(name,descr),key_item(item),contents(cont)
{
}

Container::~Container()
{
    delete(this);
}

void Container::addToInventory()
{
    for (Item* i : contents) {
        //gives the items to the players inventory if he doesnt already have them
        if(!Player::hasItem(i))
        Player::takeItem(i);

        

    }
        
}

bool Container::isContainer()
{
    return true;
}
