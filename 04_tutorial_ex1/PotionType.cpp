#include "PotionType.h"

PotionType::PotionType()
{
}

void PotionType::addInredients(Ingredient* i)
{
	ingredients.push_back(i);
}

list<Ingredient*> PotionType::getIngredient()
{
	return ingredients;
}

void PotionType::getName()
{
}
