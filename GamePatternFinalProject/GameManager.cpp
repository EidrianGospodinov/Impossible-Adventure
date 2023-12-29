#include "GameManager.h"
bool GameManager::gameOn;

GameManager::GameManager(Player* p) :player(p)
{
	location = player->getLocation();
}
void GameManager::stopGame()
{
	gameOn = false;
}

void GameManager::startGame()
{
	gameOn = true;
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
	
	if (keyItem == "")
		checkSoloKeyword(keyword, location, player);
	else {
		
				
			checkKeywordItem(keyword, keyItem, location, player);
			
		}
	}


void GameManager::checkSoloKeyword(string keyWord, Location* l, Player* p) {
	if (keyWord == "LOOK") {
		l->print();
	}

	else if (keyWord == "QUIT") {
		GameManager::stopGame();
	}
	else
		cout << keyWord<<"is an invalid Command! \n";

}
void GameManager::checkKeywordItem(string keyWord, string keyItem, Location* l, Player* p) {
	if (keyWord == "TAKE") {
		for (auto i : location->getContents()) {
			if (i->getName() == keyItem)
			{
				cout << "item taken: " << keyItem << endl;
				player->takeItem(i);
				/*location->take_item(i);*/
				
				
			}
		}
	}
	else if (keyWord == "DROP") {
		for (auto i : player->getInventory()) {
			if (i->getName() == keyItem) {
				cout << "item dropped: " << keyItem << endl;
				player->dropItem(i);
				
			}
		}
	}

	else if (keyWord == "OPEN") {
		for (auto i : player->getInventory()) {
			if (i->getName() == keyItem) {
				if(i->open())
				cout << "item openned: " << keyItem << endl;
			}
		}

	}
	else
		cout <<keyItem <<" is an invalid Command! \n";
}

