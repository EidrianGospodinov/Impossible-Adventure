#include "Mobster.h"

list<Mobster*> Mobster::theMob;//this defines the static list
//the "list<Mobster*> Mobster" is the type of static member
//and "::theMob" belongs to that static list


Mobster::Mobster(string n, int c) : name(n), customer(c) {
	theMob.push_back(this);
}

Mobster::~Mobster()
{
	theMob.remove(this);
}

void Mobster::hostileTakeover(Mobster* victim)
{
	this->customer += victim->customer;
	delete victim;
}

void Mobster::printMob()
{
	for (Mobster* m : theMob)
		cout <<"name: " << m->name << ", customers: "<<m->customer<<endl;
}
