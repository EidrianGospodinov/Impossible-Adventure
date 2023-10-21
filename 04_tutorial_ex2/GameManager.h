#pragma once
#include <string>
using std::string;
class GameManager
{
	bool playerMove=false;
	bool gameOn=false;

public:
	string finalMessage;

	void setPlayerMovement();

	void setGameOn();

	bool getPlayerMovementStatus();

	bool getGameStatus();

	
};

