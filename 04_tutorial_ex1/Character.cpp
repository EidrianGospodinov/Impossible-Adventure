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

void Character::levelUp()
{
	level++;
}

Potion* Character::brew(PotionType* type)
{
	for (Ingredient* i : type->getIngredient()) {
		if (inventory[i] <= 0)
			return nullptr;
	}
	for (Ingredient* i : type->getIngredient()) {
		inventory[i]--;

	}
		return new Potion(type, level);
	
}
