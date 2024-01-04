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
	cout << "\n\n";
	
	
	//game manager initalisation
	GameManager game;
	
	game.startGame();
	
	


	while (game.gameOn)//while the game is on keep looping
	{

		//instructions for the user
		cout << "Hello adventurer\n";
		cout << "Welcome to our world! Here are some basic commands you can use:\n\n";

		cout << "- TAKE [item]: Add an item to your inventory.\n";
		cout << "- DROP [item]: Remove an item from your inventory.\n";
		cout << "- OPEN [item]: Attempt to open a container\n";
		cout << "- EXAMINE [item]: Get more information about the item\n";
		cout << "- LOOK: Observe your surroundings for more details.\n";
		cout << "- QUIT: End your adventure.\n\n";

		cout << "For movement, check room descriptions for available DIRECTIONS such as:\n";
		cout << "NORTH, SOUTH, EAST, WEST, UP, DOWN, IN, and OUT.\n\n";

		cout << "Just dont that the commands are all in capitals\n";
		cout << "And the keyword are with the first letter in capital\n\n";

		cout << "Good luck on your journey!\n\n";
		
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