#include "Piece.h"
#include <iostream>
#include <iomanip>

class Pawn : public Piece{
    public:
        char symbol_param;
        Pawn(bool isWhite_param);
        ~Pawn() = default; //checkout later idk
        virtual void display() override{
            std::cout << std::setw(2) << symbol_param;
        }
        virtual bool isValidMove() override{
            return true;
        }
    
};