#include "Checker.h"

Checker::Checker(int x, int y, bool r): Piece(x,y,r)
{
}

char Checker::getChar()
{
	return 'c';
}

string Checker::getName()
{
	return "Checkers";
}

bool Checker::canMove()
{
	int newY;
	newY = isRed ? yPos - 1 : yPos + 1;

		return isFree(xPos + 1, newY) || isFree(xPos - 1, newY);

		

		
	
}

void Checker::move()
{
	int newX = 1, newY = isRed ? yPos - 1 : yPos + 1;
	if (isFree(xPos - 1, newY) && isFree(xPos + 1, newY)) {//choice
		char choice;

		cout << "Move left(l) or right(r)\n";
		cin >> choice;
		newX = (choice == 'l' ? xPos - 1 : xPos + 1);
	}
	else
		newX = isFree(xPos - 1, newY) ? xPos - 1 : xPos + 1;

	pieces[yPos][xPos] = nullptr;
	xPos = newX;
	yPos = newY;
	pieces[yPos][xPos] = this;
}
