#ifndef _PIECE_
#define _PIECE_

#include "constants.h"
#include <utility>
#include <iostream>

class Board;

class Piece{
    public:
        char symbol;
        char isWhite;
        bool isCaptured;
        int x,y;

        Piece() = default;
        virtual void display() = 0;
        virtual bool isValidMove(int oldX, int oldY, int newX, int newY, const Board& board, char isWhite_param) = 0;
        void setPosition(int newX, int newY);

};

#endif