#include "Piece.h"
#include <iostream>
#include <iomanip>

class Bishop : public Piece{
    public:
        char symbol_param;
        Bishop(bool isWhite_param);
        ~Bishop() = default; //checkout later idk
        virtual void display() override{
            std::cout << std::setw(2) << symbol_param;
        }
        virtual bool isValidMove() override;
    
};