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
        bool isMoved;
        int x,y;
        Piece(int x_param, int y_param,char symbol_param, char colour_param){
            x = x_param;
            y = y_param;
            symbol = symbol_param;
            colour = colour_param;
            isMoved = false;
        }

        bool getisMoved(){
            return isMoved;
        }

        void setMoved(){
            isMoved = true;
        }
        virtual void display() = 0;
        virtual bool isValidMove(int oldX, int oldY, int newX, int newY, Board& board, char colour_param) = 0;
        //virtual bool isKingSafe(int newX,int newY, Board& board) = 0; 
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



    

};

#endif