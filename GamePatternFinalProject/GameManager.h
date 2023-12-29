#pragma once
#include <iostream>
#include "Location.h"
#include "Player.h"
using std::string;
using std::cout;
using std::endl;
class GameManager
{
	Location *location;
	Player *player;
public:
	GameManager(Player* p);
	static bool gameOn;
	static void startGame();
	static void stopGame();
	void splitWord(string input);
	void checkSoloKeyword(string keyWord);
	void checkKeywordItem(string keyWord, string keyItem);
	void updateLocation();
	
	
	
	
};

