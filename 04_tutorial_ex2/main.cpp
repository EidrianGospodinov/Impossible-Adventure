#include <iostream>
#include "Map.h"
#include "Player.h"
#include "GameManager.h"

using namespace std;

int main() {
	Player player(4,4);
	Map map;
	GameManager *gameManager= new GameManager;

	gameManager->setGameOn();//starts the game//the game is false by default

	gameManager->setPlayerMovement();

	//bool inGame=true;
	bool moving = false;
	char getInput;

	while (gameManager->getGameStatus())
	{
		cin >> getInput;
		player.playerMovement(getInput);
		if (getInput != NULL)
			moving = true;
		if (getInput == 'q') {
			gameManager->setGameOn();
			gameManager->finalMessage = "Game ends by quitting";
		}
		if (moving) {
			map.GenerateMap(player.getXPlayer(),player.getYPlayer(),gameManager);
			moving=false;
			getInput = NULL;
		}
	}
	cout << gameManager->finalMessage;
}