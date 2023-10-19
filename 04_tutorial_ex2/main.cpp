#include <iostream>
#include "Map.h"
#include "Player.h"

using namespace std;

int main() {
	Player player(4,4);
	Map map;
	bool inGame=true;
	bool moving = false;
	char getInput;

	while (inGame)
	{
		cin >> getInput;
		player.playerMovement(getInput);
		if (getInput != NULL)
			moving = true;
		if (getInput == 'q')
			inGame = false;
		if (moving) {
			map.GenerateMap(player.getXPlayer(),player.getYPlayer());
			moving=false;
			getInput = NULL;
		}
	}
}