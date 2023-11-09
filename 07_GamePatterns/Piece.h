#pragma once

#include <string>
#include <vector>
#include <iostream>

using namespace std;


#define WIDTH 4
#define HEIGHT 6

class Piece
{
protected:
	// x/y position
	int xPos, yPos;
	// colour (red or blue)
	bool isRed;
	// map keeping track what piece is at each position on the board
	static vector<vector<Piece*>> pieces;

public:
	// Constructor. Also places this piece on the map.
	Piece(int x, int y, bool w);
	
	// Checks if given x/y coordinates are within boundaries and empty
	static bool isFree(int x, int y);

	// Draws the map
	static void drawPieces();

	// Getters for x/y position
	int getXPos();
	int getYPos();

	// Character used to represent this piece
	virtual char getChar() = 0;

	// Name to use for this piece (e.g. "pawn")
	virtual string getName() = 0;

	// Checks if this piece can move
	virtual bool canMove() = 0;

	// Moves this piece if possible
	virtual void move() = 0;

};

