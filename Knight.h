#ifndef _KNIGHT_
#define _KNIGHT_

#include "Piece.h"
#include <iostream>
#include <iomanip>

class Knight : public Piece{
    public:
        char symbol_param;
        Knight(char isWhite_param);
        ~Knight() = default; //checkout later idk
        virtual void display() override{
            std::cout << std::setw(2) << symbol_param;
        }
        virtual bool isValidMove(int oldX, int oldY, int newX, int newY, const Board& board, char isWhite_param) override;
    
};

#endif