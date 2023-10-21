#include "GameManager.h"


void GameManager::setPlayerMovement()
{
	playerMove = !playerMove;
}

void GameManager::setGameOn()
{
	gameOn = !gameOn;
}

bool GameManager::getPlayerMovementStatus()
{
	return playerMove;
}

bool GameManager::getGameStatus()
{
	return gameOn;
}

