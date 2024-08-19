#ifndef _PAWN_
#define _PAWN_

#include "Piece.h"
#include <iostream>
#include <iomanip>


class Pawn : public Piece{
    public:
        char symbol_param;
        Pawn(char isWhite_param);
        ~Pawn() = default; //checkout later idk
        virtual void display() override{
            std::cout << std::setw(2) << symbol_param;
        }
        virtual bool isValidMove(int oldX, int oldY, int newX, int newY, const Board& board, char isWhite_param)override;
    
};

#endif