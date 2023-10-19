#pragma once
class Player
{
	int xPlayer, yPlayer;

public:
	Player(int x, int y);
	int getXPlayer();
	int getYPlayer();
	void playerMovement(char c);
};

