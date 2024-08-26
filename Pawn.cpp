#include "Pawn.h"
#include "Board.h"

Pawn::Pawn(int x_param, int y_param,char colour_param) : Piece(x_param, y_param,(colour_param == 'W')? symbol_param = 'P' : symbol_param = 'p', colour_param){
   
}

bool Pawn::isValidMove(int oldX, int oldY, int newX, int newY, Board& board, char colour_param){
    bool valid_M = false;
    if(colour_param == 'B'){
        if(board.getSquare(oldX,oldY)->getisMoved() == false){
            if((oldX + 1 == newX && oldY == newY) || (oldX + 2 == newX && oldY == newY)){
                valid_M = true;
            }
            
        }else{
            if(oldX + 1 == newX  && oldY == newY){
                valid_M = true;
            } 
        }
    }

    if(colour_param == 'W'){
        
        if(board.getSquare(oldX,oldY)->getisMoved() == false){
            if((oldX - 1 == newX  && oldY == newY) || (oldX - 2 == newX  && oldY == newY)){
                valid_M = true;
            }
            
        }else{
            if(oldX - 1 == newX  && oldY == newY){
                valid_M = true;
            } 
        }

    }
    return valid_M;
}

 