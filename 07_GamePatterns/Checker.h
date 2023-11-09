#pragma once
#include "Piece.h"
class Checker:public Piece 
{
    
    
    public:
        Checker(int x, int y, bool r);

        char getChar();

        string getName();

        bool canMove();

        void move();
    
};

