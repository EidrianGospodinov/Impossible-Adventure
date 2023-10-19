#pragma once
#include "PotionType.h"
class Potion
{
	int level;
	PotionType* type;
public:
	Potion(PotionType* t,int l);
};

