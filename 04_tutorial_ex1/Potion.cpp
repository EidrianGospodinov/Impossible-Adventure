#include "Potion.h"



Potion::Potion(PotionType* t, int l) : level(l), type(t) { }

void Potion::printMe()
{
	cout <<"This is " << level<<"level potion of type " << type;
}



