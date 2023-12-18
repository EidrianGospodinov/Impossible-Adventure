#include "Player.h"
//dont forget to implement the static members if you dont want to have random errors
list<Item*> Player::inventory;
Location Player::location;
int Player::steps;


bool Player::hasItem(Item* i)
{
    for (Item* x : inventory)
    { 
        if (x == i)
            return true;
    }
    //    //check if the names of x and i are the same
    return false;
}

bool Player::takeItem(Item* i)
{
    inventory.push_back(i);

    return hasItem(i);
}

bool Player::dropItem(Item* i)
{
    if (hasItem(i))
    {
        inventory.remove(i);
    }
    return hasItem(i);
}

bool Player::openItem(Item* i)
{
    return false;
}

void Player::printStatus()
{
    cout << "Player location: ";
    location.print();
        
    

}
