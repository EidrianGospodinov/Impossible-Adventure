#include "Colours.h"
#include "Player.h"

// Initialise the isRed attribute, and set up our pieces
Player::Player(bool r) : isRed(r) {
	for (int i = 0; i < WIDTH; i++) {
		// Fill the bottom (if red) or top (if blue) row with pawns
		pieces.push_back(new Pawn(i, r ? HEIGHT - 1 : 0, r));
		// Fill the second row from the bottom (if red) or top (if blue) with checkers
		pieces.push_back(new Checker(i, r ? HEIGHT - 2 : 1, r));
	}
}

// Choose a piece to move. Must be a valid number, and the piece must be able to move.
int Player::choosePiece()
{
	int choice;
	cout << "Move which piece? ";
	cin >> choice;
	while (choice < 0 || choice >= pieces.size() || !pieces[choice]->canMove()) {
		// Invalid input. Just in case a non-number was entered, we clear cin to prevent an infinite loop.
		cin.clear();
		cin.ignore(100, '\n');
		cout << "Sorry, that piece cannot move. Please choose another: ";
		cin >> choice;
	}
	return choice;
}

// Process one of our turns.
bool Player::turn() {
	bool canMove = false;
	// Draw the current map
	Piece::drawPieces();
	// Set our output colour
	setColours((isRed ? red : blue), black);
	// Go through our pieces, printing for each if it can move or not.
	// Also determine if at least one can move.
	for (int i = 0; i < pieces.size(); i++) {	
		Piece* p = pieces[i];
		canMove |= p->canMove();
		cout << i << ": " << p->getName() << " at (" << p->getXPos() << ", " << p->getYPos() << ") "
				<< (p->canMove() ? " can move" : "cannot move") << endl;		
	}
	// If any of our pieces can move, pick one.
	if (canMove) {
		int i = choosePiece();
		pieces[i]->move();
	}
	// Otherwise we lose the game.
	else {
		cout << "Sorry, you lost!" << endl;
	}
	// Return true/false based on if we were able to move.
	return canMove;
}
