#ifndef _BISHOP_
#define _BISHOP_

#include "Piece.h"
#include <iostream>
#include <iomanip>

class Bishop : public Piece{
    public:
        char symbol_param;
        Bishop(char isWhite_param);
        ~Bishop() = default; //checkout later idk
        virtual void display() override{
            std::cout << std::setw(2) << symbol_param;
        }
        virtual bool isValidMove(int oldX, int oldY, int newX, int newY, const Board& board, char isWhite_param) override;
    
};

#endif