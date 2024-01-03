#include<iostream>


#include "GameManager.h"
#include "InputFile.h"
using std::cout;
using std::getline;
using std::cin;










int main() {
	
	//read data
	string fileName;
	cout << "Enter the file name you want to use! \n if you dont have one use \" initial.txt\"\n";
	//cin >> fileName;
	InputFile file("Game Scenario.txt");
	file.readFile();
	
	
	//game manager initalisation
	GameManager game;
	
	game.startGame();
	
	


	while (game.gameOn)//while the game is on keep looping
	{
		cout << endl;
		//get user input
		string input;
		getline(cin, input);

		//process the user input 
		game.splitWord(input);
		cout << std::endl;
		
		//print the player status
		//Player::printStatus();
		
		
		
		


	}
	
}