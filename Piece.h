#ifndef _PIECE_
#define _PIECE_

#include "constants.h"

class Piece{
    public:
        char symbol;
        bool isWhite;
        Piece() = default;
        virtual void display() = 0;
        virtual bool isValidMove() = 0;
};

#endif