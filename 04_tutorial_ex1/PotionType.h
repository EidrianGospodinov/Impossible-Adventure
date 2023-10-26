#include "Ingredient.h"

#include<string>
#include<list>

using std::string;
using std::list;



class PotionType
{
	string name;
	list<Ingredient*>ingredients;
public:
	PotionType();

	void addInredients(Ingredient *i);

	list<Ingredient*>getIngredient();
	void getName();

};

