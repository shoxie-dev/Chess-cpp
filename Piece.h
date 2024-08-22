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
        Piece(int x_param, int y_param,char symbol_param, char colour_param){
            x = x_param;
            y = y_param;
            symbol = symbol_param;
            colour = colour_param;
            isCaptured = false;
        }
        virtual void display() = 0;
        virtual bool isValidMove(int oldX, int oldY, int newX, int newY, const Board& board, char colour_param) = 0;
        void setPosition(int newX,int newY){
            x = newX;
            y = newY;
        }

        int getX(){
            return x;
        }

        int getY(){
            return y;
        }

        char getSymbol(){
            return symbol;
        }
        char getColour(){
            return colour;
        }

        void setCaptured(){
            isCaptured = true;
        }
    

};

#endif