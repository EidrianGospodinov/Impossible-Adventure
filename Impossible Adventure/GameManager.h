#pragma once
#include <iostream>
#include "Location.h"
#include "Player.h"
using std::string;
using std::cout;
using std::endl;
class GameManager
{
	Location *location= Player::getLocation();//pointer to the current postion
	
public:

	
	static bool gameOn;  // Static flag indicating whether the game is running
	static void startGame();  // Static method to start the game
	static void stopGame();  // Static method to stop the game
	void splitWord(string input);  // Method to split user input and process commands
	void checkSoloKeyword(string keyWord);  // Method to check and process single-word commands
	
	void checkKeywordItem(string keyWord, string keyItem);  // Method to check and process commands with an associated item
	void updateLocation();  // Method to update the GameManager's location based on the player's location
	
	
	
};

