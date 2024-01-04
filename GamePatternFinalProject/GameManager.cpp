#include "GameManager.h"
bool GameManager::gameOn;// Initialize static member 'gameOn' for the entire program

//static functions to start and stop the game
void GameManager::stopGame()
{
	gameOn = false;
}
void GameManager::startGame()
{
	gameOn = true;
}

//function that get the current player location
void GameManager::updateLocation() {
	location= Player::getLocation();
}

void GameManager::splitWord(string input) {
	char sep = ' ';
	int i = 0;

	//storing the main parts of the input
	string keyword="";
	string keyItem="";


	bool iskeyword = true;

	//loop until the last charcter of the char array which 
	//is alway \0
	while (input[i] != '\0')
	{
		// Implementation of splitting logic
		if (input[i] == sep && iskeyword != false) {
			iskeyword = false;
		}

		else if (iskeyword != false) {
			keyword += input[i];

		}
		else
		{
			keyItem += input[i];
		}

		i++;
	}
	updateLocation();//updates location after procesing the input

	// Depending on the command type, call other methods to handle specific actions
	if (keyItem == "")
		checkSoloKeyword(keyword);
	else {
			checkKeywordItem(keyword, keyItem);		
		}
	}

// Method to check and process single-word commands
void GameManager::checkSoloKeyword(string keyWord) {

	Item* keyItem=nullptr;
	Location* locationTowards=nullptr;


	if (keyWord == "LOOK") {
		location->print();
	}

	else if (keyWord == "QUIT") {
		GameManager::stopGame();
	}
	//get the location and keyitem in the specific direction-for all direction
	else if (keyWord == "NORTH") {
		keyItem=location->getKey(keyWord);
		locationTowards = location->getConnection(keyWord);
		
		
	}
	else if (keyWord == "SOUTH") {

		keyItem = location->getKey(keyWord);
		locationTowards = location->getConnection(keyWord);
	}
	else if (keyWord == "EAST") {

		keyItem = location->getKey(keyWord);
		locationTowards = location->getConnection(keyWord);
	}
	else if (keyWord == "WEST") {

		keyItem = location->getKey(keyWord);
		locationTowards = location->getConnection(keyWord);
	}
	else if (keyWord == "IN") {

		keyItem = location->getKey(keyWord);
		locationTowards = location->getConnection(keyWord);
	}
	else if (keyWord == "OUT") {

		keyItem = location->getKey(keyWord);
		locationTowards = location->getConnection(keyWord);
	}
	else if (keyWord == "UP") {

		keyItem = location->getKey(keyWord);
		locationTowards = location->getConnection(keyWord);
	}
	else if (keyWord == "DOWN") {

		keyItem = location->getKey(keyWord);
		locationTowards = location->getConnection(keyWord);
	}
	else
		cout << keyWord<<" is an invalid Command! \n";
	//if the keyword is not one of the known return invalid

	if (locationTowards != nullptr) {//check if the player can go in selected direction from this location
		if (keyItem != nullptr) {//if there is a key item we check if the player has it
			if (Player::hasItem(keyItem)) {//check if the player has item needed
				Player::changeLocation(locationTowards);//moves to the new direction
				Player::steps++;//update step counter

			}
			else
				cout << "You dont have the required item to access the location: " << keyItem << endl;
		}
		else {//if there is no provided item then you can go to the location
			Player::changeLocation(locationTowards);
			Player::steps++;

		}
	}
	else
		cout << "You can not travel to that direction from here! ";
	
}
// Method to check and process commands with an associated item
void GameManager::checkKeywordItem(string keyWord, string keyItem) {
	//check if the keyword is known
	if (keyWord == "TAKE") {
		for (auto i : location->getContents()) {//compares each item in the location with the one we have
			if (i->getName() == keyItem)
			{
				cout << "item taken: " << keyItem << endl;//tells the item when the item is taken
				Player::takeItem(i);//gets the item in the inventory
				
				
				
			}
		

		}
	}
	else if (keyWord == "DROP") {
		for (auto i : Player::getInventory()) {
			if (i->getName() == keyItem) {
				cout << "item dropped: " << keyItem << endl;//tell the user when the action done
				Player::dropItem(i);//player drop item and the location takes it
				location->drop_item(i);
				
			}
		

		}
	}

	else if (keyWord == "OPEN") {
		for (auto i : Player::getInventory()) {
			if (i->getName() == keyItem) {
				if (Player::openItem(i)) {
					Player::dropItem(i);//after the container is open, its no longer needed so we drop it
					cout << "item openned: " << keyItem << endl;
					
				}
				
			}
		}

	}
	else if (keyWord == "EXAMINE") {//examine keyword check if the description of item
		for (auto i : Player::getInventory()) {
			if (i->getName() == keyItem) {
				cout<<i->getName()<<" is " << i->getDescription();
			}
			
		}
	}
	else
		cout <<keyItem <<" is an invalid Command! \n";//tell the player that the command is invalide
}

