#pragma once
#include<string>
#include<list>

using std::string;
using std::list;

class Ingredient
{
	string name;
	list<string>ingredients;

public:
	Ingredient();
	void addIngredient(string i);

	Ingredient GetIngredient() {

		
	}

};

