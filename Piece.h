#ifndef _PIECE_
#define _PIECE_

#include "constants.h"
#include <utility>
#include <iostream>

class Board;

class Piece{
    public:
        char symbol;
        char colour;
        bool isCaptured;
        int x,y;
        Piece(char symbol_param, char colour_param){
            symbol = symbol_param;
            colour = colour_param;
        }
        virtual void display() = 0;
        virtual bool isValidMove(int oldX, int oldY, int newX, int newY, const Board& board, char colour_param) = 0;
        char getSymbol(){
            return symbol;
        }
        char getColour(){
            return colour;
        }
        void setPosition(int newX, int newY);

};

#endif