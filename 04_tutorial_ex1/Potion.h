#pragma once
#include "PotionType.h"
#include <iostream>
using std::cout;
class Potion
{
	int level;
	PotionType* type;
public:
	Potion(PotionType* t,int l);

	void printMe();
};

