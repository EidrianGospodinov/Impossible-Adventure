#pragma once
#include <iostream>
using std::string;
using std::cout;
using std::endl;
class GameManager
{
public:
	static bool gameOn;
	static void startGame();
	static void stopGame();
	void splitWord(string input);
	
	
	
	
};

