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
		for (auto i : location->getContents()) {
			if (i->getName() == keyItem)
			{
				
				checkKeywordItem(keyword, i, location, player);
			}
		}
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
		cout << "Invalid Command! \n";

}
void GameManager::checkKeywordItem(string keyWord, Item *keyItem, Location* l, Player* p) {
	if (keyWord == "TAKE") {
		p->takeItem(keyItem);
		l->take_item(keyItem);
	}
	else if (keyWord == "DROP") {
		p->dropItem(keyItem);
		l->drop_item(keyItem);
	}

	else if (keyWord == "OPEN") {
		keyItem->open();

	}
	else
		cout << "Invalid Command! \n";
}

