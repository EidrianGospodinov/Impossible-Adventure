#include "Player.h"

Player::Player(int x,int y) : xPlayer(x),yPlayer(y) {}


int Player::getXPlayer()
{
	return xPlayer;
}

int Player::getYPlayer()
{
	return yPlayer;
}

void Player::playerMovement(char c)
{
	switch (c)
	{
	case 'a':
		xPlayer--;
		break;
	case 'd':
		xPlayer++;
		break;
	case 'w':
		yPlayer--;
		break;
	case 's':
		yPlayer++;
		break;
		

	default:

		break;
	}
}
