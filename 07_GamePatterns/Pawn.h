#pragma once
#include "Piece.h"
class Pawn : public Piece
{
    
public:
    Pawn(int x, int y, bool r);

    char getChar();

    string getName();

    bool canMove();

    void move();
};

