#include "Player.h"
// Static members initialization
list<Item*> Player::inventory;
Location* Player::location = nullptr;
int Player::steps;




// Destructor implementation
Player::~Player()
{
    // Deleting the player instance; consider using 'delete this' only if Player is heap-allocated
    delete(this);
}

// Method to change the player's location
void Player::changeLocation(Location* loc)
{
    if (loc != nullptr)
        location = loc;
}

// Method to get the current player location
Location* Player::getLocation()
{
    return location;
}

// Method to get the player's inventory
list<Item*> Player::getInventory()
{
    return inventory;
}

bool Player::hasItem(Item* i)
{
    //check if the item is in the player inventory
    for (Item* x : inventory)
    {
        if (i != nullptr)
            if (x == i)//check if the names of x and i are the same
               return true;
    }
    
        // Return false if the item is not found
    return false;
}

bool Player::takeItem(Item* i)
{
    //add an item to player inventory if the item is not null
    if (i != nullptr) {
        location->take_item(i); 
        inventory.push_back(i);
    }

    return Player::hasItem(i);
}

bool Player::dropItem(Item* i)
{
    //drop a specific item from player inventory
    if (hasItem(i))
    {
        //removes item from inventory
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
