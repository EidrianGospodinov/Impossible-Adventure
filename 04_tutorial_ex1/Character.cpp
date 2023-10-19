#include "Character.h"



Character::Character(string n, int l):name(n),level(l)
{

}

void Character::collectIngredient(Ingredient* i)
{
	inventory[i]++;
}

void Character::displayIngredients()
{
	for (auto i : inventory) {
		cout << i.first << " - " << i.second << endl;
	}
}
