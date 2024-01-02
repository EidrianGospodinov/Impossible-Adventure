#include "GameManager.h"
bool GameManager::gameOn;


void GameManager::stopGame()
{
	gameOn = false;
}

void GameManager::startGame()
{
	gameOn = true;
}
void GameManager::updateLocation() {
	location= Player::getLocation();
}

void GameManager::splitWord(string input) {
	char sep = ' ';
	int i = 0;


	string keyword="";
	string keyItem="";


	bool iskeyword = true;

	while (input[i] != '\0')
	{
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
	updateLocation();//updates location in case the player has moved
	if (keyItem == "")
		checkSoloKeyword(keyword);
	else {
			checkKeywordItem(keyword, keyItem);		
		}
	}


void GameManager::checkSoloKeyword(string keyWord) {
	Item* keyItem=nullptr;
	Location* locationTowards=nullptr;
	if (keyWord == "LOOK") {
		location->print();
	}

	else if (keyWord == "QUIT") {
		GameManager::stopGame();
	}
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
	else
		cout << keyWord<<" is an invalid Command! \n";
	if (locationTowards != nullptr) {
		if (keyItem != nullptr) {
			if (Player::hasItem(keyItem)) {
				Player::changeLocation(locationTowards);
				Player::steps++;

		}
		}
		else {
			Player::changeLocation(locationTowards);
			Player::steps++;

		}
	}
}
void GameManager::checkKeywordItem(string keyWord, string keyItem) {
	if (keyWord == "TAKE") {
		for (auto i : location->getContents()) {
			if (i->getName() == keyItem)
			{
				cout << "item taken: " << keyItem << endl;
				Player::takeItem(i);
				/*location->take_item(i);*/
				
				
			}
		}
	}
	else if (keyWord == "DROP") {
		for (auto i : Player::getInventory()) {
			if (i->getName() == keyItem) {
				cout << "item dropped: " << keyItem << endl;
				Player::dropItem(i);
				location->drop_item(i);
				
			}
		}
	}

	else if (keyWord == "OPEN") {
		for (auto i : Player::getInventory()) {
			if (i->getName() == keyItem) {
				if (Player::openItem(i)/*, i->open()*/) {
					Player::dropItem(i);
					cout << "item openned: " << keyItem << endl;
				}
			}
		}

	}
	else
		cout <<keyItem <<" is an invalid Command! \n";
}

