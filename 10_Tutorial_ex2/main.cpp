#include "Shift.h"
#include "Rotate90.h"
#include "Rescale.h"
#include <iostream>
#include <list>

using std::cout;
using std::endl;
using std::list;

void printBlock(block& b) {
	cout << "This is a " << b.width << "*" << b.height
		<< " block with midpoint (" << b.middleX << "," << b.middleY << ")" << endl;
}

int main() {
	block b{ 0, 0, 3, 4 };
	list<Transform*> transforms;

	//dont miss public when you are inheriting from the base class transform or the new is going to give you an error
	transforms.push_back(new Shift(1, 2));
	transforms.push_back(new Rotate90());
	transforms.push_back(new Rescale(2.5));
	printBlock(b);
	for (Transform* t : transforms) {
		t->apply(b);
		printBlock(b);
	}
}

