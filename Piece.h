#ifndef _PIECE_
#define _PIECE_

#include "constants.h"
#include <utility>

class Piece{
    public:
        char symbol;
        bool isWhite;
        bool isCaptured;
        int x,y;

        Piece() = default;
        virtual void display() = 0;
        virtual bool isValidMove() = 0;
        void setPosition(int newX, int newY);
        std::pair<int, int> getPosition() const;
};

#endif