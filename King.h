#include "Piece.h"
#include <iostream>
#include <iomanip>

class King : public Piece{
    public:
        char symbol_param;
        King(bool isWhite_param);
        ~King() = default; //checkout later idk
        virtual void display() override{
            std::cout << std::setw(2) << symbol_param;
        }
        virtual bool isValidMove() override;
    
};