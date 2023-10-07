#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;


struct Town {

	string name; int population;

};
struct NPC {

	string name; Town* home;

};
Town* makeTown(string name, int startingPop) {
	Town* town = new Town;
	town->name = name;
	town->population = startingPop;
	return town;
}
NPC* makeNPC(string name, Town* startingHome) {
	NPC* npc = new NPC;
	npc->name = name;
	npc->home = startingHome;
	return npc;
}

void printNPC(NPC* npc) {
	cout << npc->name;
	cout << "( Population " << npc->home->population << " )" << endl;


}
void MoveNPC(NPC* npc, Town* newTown) {
	npc->home->population--;
	npc->home = newTown;
}

int main() {
	Town* town1 = makeTown("Osgard", 3);
	Town* town2 = makeTown("Paris", 34533);
	NPC* npc1 = makeNPC("Bob", town1);

	printNPC(npc1);
	MoveNPC(npc1, town2);

	printNPC(npc1);
	cout << town1->population;


}