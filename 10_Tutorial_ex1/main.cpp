#include <iostream>
#include "Mobster.h"
using namespace std;


int main() {
	Mobster* joe = new Mobster("Joe", 4);
	Mobster::printMob();
	cout << endl;

	Mobster* irene = new Mobster("Irene", 5);
	Mobster::printMob();
	cout << endl;

	Mobster* jackie = new Mobster("Jackie", 1);
	Mobster::printMob();
	cout << endl;

	irene->hostileTakeover(jackie);
	Mobster::printMob();
	



}