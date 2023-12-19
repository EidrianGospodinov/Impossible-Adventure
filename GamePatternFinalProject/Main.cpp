#include<iostream>
#include<vector>

#include "Item.h"
#include "Player.h"
#include "Location.h"
#include"Container.h"
using std::cout;

//notes
/*
player function openItem- in progress, no idea what to do

container- open function in progress

location
-getkey and get connection

Executing commands


work on player printstatus- the location print is printing its items as well, which is not needed for the status
*/

void splitWord(string input) {
	/*for (auto word : input
		| split(' ')) */
	{

	}

}

int main() {

	//bool game = true;
	//Player *player= new Player;
	//Item *item= new Item;
	//
	//string input;
	//std::vector<string> words;
	

	/*while (game) {

		splitWord(input);


	}*/


	//test functionallity using the datafile

	//the key for the strongbox
	Item *screwDriver = new Item("Screwdriver", "screw");

	//the items inside the strongbox
	Item* redKey = new Item("redKey", "key that is red");
	Item* letter = new Item("letter", "let");
	list<Item*>content;
	content.push_back(redKey);
	content.push_back(letter);

	Container* Strongbox = new Container("Strongbox", "A sturdy box", screwDriver, content);

	//player
	Player *player = new Player;
	player->takeItem(screwDriver);

	//test Item functions
	cout << Strongbox->getName() << ": " << Strongbox->getDescription()<<endl;
	
	cout<<"Is open: "<<Strongbox->isOpened;
	Strongbox->open();
	cout << "Is open: " << Strongbox->isOpened << endl;
	player->printStatus();
	cout << endl << endl;

	//locations
	
	




}