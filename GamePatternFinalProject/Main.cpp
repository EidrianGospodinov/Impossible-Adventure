#include<iostream>
#include<vector>


#include "Item.h"
#include "Player.h"
#include "Location.h"
#include"Container.h"
#include "GameManager.h"
using std::cout;
using namespace std;

//notes
/*
player function openItem- in progress, no idea what to do

container- open function in progress

location
-getkey and get connection

Executing commands


work on player printstatus- the location print is printing its items as well, which is not needed for the status
*/
/*
void splitWord(string arr) {
	

	char sep = ' ';
	int i = 0;

	
	string keyword;
	string desc;
	

	bool iskeyword = true;

	while (arr[i] != '\0')
	{
		if (arr[i] == sep && iskeyword != false) {
			iskeyword = false;
		}

		else if (iskeyword != false) {
			keyword += arr[i];

		}
		else
		{
			desc += arr[i];
		}

		i++;
	}
	cout << keyword << endl;
	if (desc != "")
		cout << desc;


}
*/

/*
void checkSoloKeyword(string keyWord, Location* l, Player* p) {
	if (keyWord == "LOOK") {
		l->print();
	}
	
	else if (keyWord == "QUIT") {
		GameManager::stopGame();
	}
}
*/

/*void checkKeywordItem(string keyWord, string itemName, Location* l, Player* p) {
	
	 if (keyWord == "TAKE") {
		//p->takeItem();
	}
	else if (keyWord == "DROP") {

	}

	else if (keyWord == "OPEN") {

	}
	
}*/

void readData() {

}

int main() {
	//game manager
	


	//test functionallity using the datafile

	//the key for the strongbox
	Item* screwDriver = new Item("Screwdriver", "screw");

	//the items inside the strongbox
	Item* redKey = new Item("redKey", "key that is red");
	Item* letter = new Item("letter", "let");
	list<Item*>content;
	content.push_back(redKey);
	content.push_back(letter);

	Container* Strongbox = new Container("Strongbox", "A sturdy box", screwDriver, content);
	
	//player
	Player* player = new Player();
	player->takeItem(screwDriver);
	//locations
	list<Item*>loc1Contents;
	loc1Contents.push_back(Strongbox);
	loc1Contents.push_back(screwDriver);
	Location* loc1 = new Location(1, "Outside building", "You are standing in front of a small building.", loc1Contents);




	//loc2
	Item* rubberDuck = new Item("rubber duck", "Duck made of rubber");
	list<Item*> loc2Contents{ rubberDuck };
	Location* loc2 = new Location(2, "inside Building", "You are inside a building, a well house for a largespring", loc2Contents);


	player->changeLocation(loc1);

	////test Item functions
	cout << Strongbox->getName() << ": " << Strongbox->getDescription()<<endl;
	
	cout<<"Is open: "<<Strongbox->isOpened;
	Strongbox->open();
	cout << "Is open: " << Strongbox->isOpened << endl;
	player->printStatus();
	cout << endl << endl;
	Player::printStatus();

	//cout<<player->openItem(Strongbox);
	cout << endl;
	
	//game manager
	GameManager game(player);
	game.startGame();




	while (game.gameOn)
	{
		string input;
		getline(cin, input);
		game.splitWord(input);
		/*if (input == "quit") {
			game.stopGame();
		}*/


	}
}