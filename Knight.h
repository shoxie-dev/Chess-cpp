#include "Piece.h"
#include <iostream>
#include <iomanip>

class Knight : public Piece{
    public:
        char symbol_param;
        Knight(bool isWhite_param);
        ~Knight() = default; //checkout later idk
        virtual void display() override{
            std::cout << std::setw(2) << symbol_param;
        }
        virtual bool isValidMove() override;
    
};