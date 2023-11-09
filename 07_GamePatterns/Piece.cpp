#include "Piece.h"
#include "Colours.h"

vector<vector<Piece*>> Piece::pieces(HEIGHT, vector<Piece*>(WIDTH, nullptr));

// Initialise the attributes with the given values, and place us on the map at the given position
Piece::Piece(int x, int y, bool r) : xPos(x), yPos(y), isRed(r)
{
	pieces[y][x] = this;
}

// Check if the given x/y position is within bounds and has no piece on it
bool Piece::isFree(int x, int y)
{
	return ((x >= 0) && (x < WIDTH) && (y >= 0) && (y < HEIGHT) && (pieces[y][x] == nullptr));
}

// Draw the map
void Piece::drawPieces()
{
	for (vector<Piece*>& row : pieces) {
		for (Piece* p : row)
			if (p == nullptr) { // No piece, draw a dot
				// No piece, draw a dot
				setColours(light_gray, black);
				cout << '.';
			}
			else {
				// Draw the piece's character representation, using its side's colour
				setColours((p->isRed ? red : blue), black);
				cout << p->getChar();
			}
		cout << endl;
	}
	cout << endl;
}

int Piece::getXPos()
{
	return xPos;
}

int Piece::getYPos()
{
	return yPos;
}
