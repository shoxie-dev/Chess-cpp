#ifndef _PAWN_
#define _PAWN_

#include "Piece.h"
#include <iostream>
#include <iomanip>


class Pawn : public Piece{
    public:
        char symbol_param;
        Pawn(int x_param, int y_param,char colour_param);
        ~Pawn() = default; //checkout later idk
        virtual void display() override{
            std::cout << std::setw(2) << symbol_param;
        }
        virtual bool isValidMove(int oldX, int oldY, int newX, int newY, Board& board, char colour_param)override;
    
};

#endif