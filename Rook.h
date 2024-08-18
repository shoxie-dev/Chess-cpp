#include "Piece.h"
#include <iostream>
#include <iomanip>

class Rook : public Piece{
    public:
        char symbol_param;
        Rook(bool isWhite_param);
        ~Rook() = default; //checkout later idk
        virtual void display() override{
            std::cout << std::setw(2) << symbol_param;
        }
        virtual bool isValidMove() override;
    
};