#pragma once
#include <iostream>
#include<list>
using std::string;
using std::list;
using std::endl;
using std::cout;
class Mobster
{
private:
	string name;
	int customer;
	static list<Mobster*> theMob;//declaration only 
public:
	Mobster(string n, int c);
	~Mobster();
	void hostileTakeover(Mobster* victim);
	static void printMob();
};

