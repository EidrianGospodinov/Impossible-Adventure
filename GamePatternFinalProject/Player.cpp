#include "Player.h"
//dont forget to implement the static members if you dont want to have random errors
list<Item*> Player::inventory;
Location* Player::location = nullptr;
int Player::steps;




Player::~Player()
{
    delete(this);
}

void Player::changeLocation(Location* loc)
{
    if (loc != nullptr)
    location = loc;
}



Location *Player::getLocation()
{
    return location;
}

bool Player::hasItem(Item* i)
{
    //check if the item is in the player inventory
    for (Item* x : inventory)
    {
        if (i != nullptr)
            if (x == i)
               return true;
    }
    //check if the names of x and i are the same
    return false;
}

bool Player::takeItem(Item* i)
{
    //add an item to player inventory if the item is not null
    if (i != nullptr) {
        //location->take_item(i); //
        inventory.push_back(i);
    }

    return Player::hasItem(i);
}

bool Player::dropItem(Item* i)
{
    //drop a specific item from player inventory
    if (hasItem(i))
    {
        location->drop_item(i);
        inventory.remove(i);
    }
    return Player::hasItem(i);
}



bool Player::openItem(Item* i)
{
    //if (i->isContainer && i != nullptr)
    {
        return i->open();
    }
   // return false;
}

void Player::printStatus()
{
    //print the player status and location
    cout << "Player location: ";
    //get the name of the location
    
    string n=location->getName();
    cout << n<<endl;//if it works dont touch!

    //prints the items from the inventory
    cout << "Inventory items: ";
    for (auto i : inventory)
        cout << i->getName() << endl;

    //prints the steps taken
    cout << "Steps taken: " << steps << endl;


}
