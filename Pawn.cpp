#include "Pawn.h"
#include "Board.h"

Pawn::Pawn(int x_param, int y_param,char colour_param) : Piece(x_param, y_param,(colour_param == 'W')? symbol_param = 'P' : symbol_param = 'p', colour_param){
   
}

bool Pawn::isValidMove(int oldX, int oldY, int newX, int newY, Board& board, char colour_param){
    bool valid = false;
    if(colour_param == 'B'){
        if(board.getSquare(oldX,oldY)->getisMoved() == false){// strictly movement
            if((newX == oldX + 1 && newY == oldY) || (newX == oldX + 2 && newY == oldY)){
                if(board.getSquare(newX,newY)!=nullptr){// checks desitination point
                    valid = false;
                }else if(board.getSquare(newX,newY) == nullptr){
                    valid = true;
                    //if(newX == oldX + 2) then assignt set_en_passant == true
                }   
            }

            if(newX == oldX + 1 && newY == oldY + 1 || newX == oldX + 1 && newY == oldY - 1){// standard capture logic will add logic for en passant capture
                if(board.getSquare(newX,newY) != nullptr){
                    if(board.getColourB(oldX,oldY) != board.getColourB(newX,newY) ){
                        valid = true;
                    }
                }
                //TODO : add en passant code here
            } 
            
        }else{
            if(newX == oldX + 1  && newY == oldY){
                if(board.getSquare(newX,newY)!=nullptr){// checks desitination point
                    valid = false;
                }else if(board.getSquare(newX,newY) == nullptr){
                valid = true;
                }  
            }
            if(newX == oldX + 1 && newY == oldY + 1 || newX == oldX + 1 && newY == oldY - 1){
                if(board.getSquare(newX,newY) != nullptr){
                    if(board.getColourB(oldX,oldY) != board.getColourB(newX,newY) ){// capture logic
                        valid = true;
                    }
                }
                //TODO : add en passant code here
            } 
        }
    }

    if(colour_param == 'W'){
        
        if(board.getSquare(oldX,oldY)->getisMoved() == false){
            if((newX == oldX - 1 && newY == oldY) || (newX == oldX - 2   && newY == oldY)){
                if(board.getSquare(newX,newY)!=nullptr){// checks desitination point
                    valid = false;
                }else if(board.getSquare(newX,newY) == nullptr){
                    valid = true;
                }   
            }

            if(newX == oldX - 1 && newY == oldY + 1 || newX == oldX - 1 && newY == oldY - 1){
                if(board.getSquare(newX,newY) != nullptr){
                    if(board.getColourB(oldX,oldY) != board.getColourB(newX,newY) ){// capture logic
                        valid = true;
                    }
                }
                //TODO : add en passant code here
            } 

            
        }else{
            if(newX == oldX - 1 && newY == oldY){
                if(board.getSquare(newX,newY)!=nullptr){// checks desitination point
                    valid = false;
                }else if(board.getSquare(newX,newY) == nullptr){
                    valid = true;
                }   
            }

            if(newX == oldX - 1 && newY == oldY + 1 || newX == oldX - 1 && newY == oldY - 1){// capture logic
                if(board.getSquare(newX,newY) != nullptr){
                    if(board.getColourB(oldX,oldY) != board.getColourB(newX,newY) ){
                        valid = true;
                    }
                }
                //TODO : add en passant code here
            }  
        }

    }
    return valid;
}

 