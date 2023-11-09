#pragma once
#include "Pawn.h"
#include "Checker.h"

class Player
{
	// Colour (red or blue)
	bool isRed;

	// This player's pieces
	vector<Piece*> pieces;

public:
	
	// Constructor. Also initialises the pieces.
	Player(bool r);
	
	// Input function for choosing a piece to move.
	// Will keep nagging until a valid piece (that can actually move) is chosen.
	int choosePiece();

	// Executes a turn for this player:
	// Prints the map;
	// Lists pieces that can/cannot move;
	// Prints game over message if none can move;
	// Otherwise asks for piece to move.
	// Returns false if player has lost, otherwise true.
	bool turn(); 
};

