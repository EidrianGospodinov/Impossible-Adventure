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
	//InputFile file("initial.txt");
	file.readFile();
	//cout << "\n\n";
	
	
	//game manager initalisation
	GameManager game;
	
	game.startGame();
	
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

	cout << "Just remebmer that the commands are all in capitals\n";
	cout << "And the keyword are with the first letter in capital\n\n";

	cout << "If you have succesfully done an action, you would recieve a verification \n";
	cout << "If not assume you have not!\n\n";

	cout << "Your goal is to reach a cave under the Mountain\n"
		 << "and retrive the lost treasure inside a chest!\n\n";

	cout << "Good luck on your journey!\n\n";


	while (game.gameOn)//while the game is on keep looping
	{

		//get user input
		string input;
		getline(cin, input);

		cout << "Steps taken: " << Player::steps<<endl;//Tells the user how many steps he has taken
		//process the user input 
		game.splitWord(input);
		cout << std::endl;
		cout << "\n\n";



	}
	
}