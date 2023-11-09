#include "Pawn.h"

// TO DO: add the definitions for the pawn's member functions.

Pawn::Pawn(int x, int y, bool r) : Piece(x,y,r)
{
	
}

char Pawn::getChar()
{

	return 'p';
}

string Pawn::getName()
{
	return string("Pawn");
}

bool Pawn::canMove()
{
	int i = 0;
	if (isRed) {
		i = -1;
	}
	else
		i = 1;
	return isFree(getXPos(), getYPos()+i);
}

void Pawn::move()
{
		pieces[yPos][xPos] = nullptr;
		int newY = isRed ? yPos-1 : yPos+1;
		pieces[yPos][xPos] = this;
	
}
