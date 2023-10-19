#include "Ingredient.h"
#include <iostream>
#include<string>
#include<map>


using std::string;
using std::map;
using std::cout;
using std::endl;

class Character
{
	string name;
	int level;
	map<Ingredient*, int>inventory;

public:
	Character(string n, int l);

	void collectIngredient(Ingredient* i);

	void displayIngredients();
};

