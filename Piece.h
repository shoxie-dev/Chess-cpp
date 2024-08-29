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
        bool isMoved, enPassant, capture_enPassant, castling_var;
        int x,y;
        Piece(int x_param, int y_param,char symbol_param, char colour_param){
            x = x_param;
            y = y_param;
            symbol = symbol_param;
            colour = colour_param;
            isMoved = false;
            enPassant = false;
            capture_enPassant = false;
            castling_var = false;
        }

        bool getisMoved(){
            return isMoved;
        }

        void setMoved(){
            isMoved = true;
        }

        bool getenPassant(){
            return enPassant;
        }

        void setenPassant(bool enPassant_param){
            enPassant = enPassant_param;
        }

        void setenPassant_capture(){
            capture_enPassant = true;
        }

        void setCastled(){
            castling_var = true;
        }

        bool getCastled(){
            return castling_var;
        }


        virtual void display() = 0;
        virtual bool isValidMove(int oldX, int oldY, int newX, int newY, Board& board, char colour_param) = 0;
        void setPosition(int newX,int newY){
            x = newX;
            y = newY;
        }

        char getSymbol(){
            return symbol;
        }
        char getColour(){
            return colour;
        }



    

};

#endif