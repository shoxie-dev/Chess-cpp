#ifndef _QUEEN_
#define _QUEEN_

#include "Piece.h"
#include <iostream>
#include <iomanip>

class Queen : public Piece{
    public:
        char symbol_param;
        Queen(bool isWhite_param);
        ~Queen() = default; //checkout later idk
        virtual void display() override{
            std::cout << std::setw(2) << symbol_param;
        }
        virtual bool isValidMove() override;
    
};

#endif