#include "Rook.h"
#include "Board.h"

Rook::Rook(int x_param, int y_param, char colour_param) : Piece(x_param, y_param, (colour_param == 'W')? symbol_param = 'R' : symbol_param = 'r', colour_param){
    
}

bool Rook::isValidMove(int oldX, int oldY, int newX, int newY,Board& board, char colour_param){
    bool valid = false;
    if((newX == oldX)){
        int n = newY - oldY;
        if(n > 0){ // this is for rhs of rook
            for(int j{oldY+1}; j < newY + 1 ; ++j){
                if(board.getPiece(oldX,j)!=nullptr){// checks gap between two points excluding the beginning and ending points
                    valid = false;
                    break;
                }else if(board.getPiece(oldX,j) == nullptr){
                    valid = true;
                }
            }
            if(board.getPiece(oldX,newY)!=nullptr){ //checks if ending point is not a nullptr first and a friendly piece afterwards if enemy piece will take it.
                if(board.getPiece(oldX,oldY)->getSymbol() != board.getPiece(oldX,newY)->getSymbol() ){
                    valid = true;
                }
            }   
        }
        
        if(n < 0){
            
        }
          
    } else if(newY == oldY){
        

    }  

    return valid;
}
