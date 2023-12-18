#include "Container.h"

bool Container::open()
{
    if(key_item==nullptr || isOpened)
    return false;

    addToInventory();


    return true;



}

void Container::addToInventory()
{
    for (Item* i : contents) {
        Player::takeItem(i);

        

    }
        
}
