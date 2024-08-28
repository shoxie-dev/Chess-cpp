#include "Knight.h"
#include "Board.h"

Knight::Knight(int x_param, int y_param,char colour_param) : Piece(x_param,y_param,(colour_param == 'W')? symbol_param = 'N' : symbol_param = 'n', colour_param){
 
}

bool Knight::isValidMove(int oldX, int oldY, int newX, int newY, Board& board, char colour_param){
    bool valid = false;
    if((newX == oldX + 2) && (newY == oldY + 1)||(newX == oldX - 2) && (newY == oldY + 1)||(newX == oldX + 2) && (newY == oldY - 1)||(newX == oldX - 2) && (newY == oldY - 1)){
        if(board.getSquare(newX,newY)!=nullptr){// checks desitination point
            valid = false;
            if(board.getColourB(oldX,oldY) != board.getColourB(newX,newY) ){// capture logic
                valid = true;
            }
        }else if(board.getSquare(newX,newY) == nullptr){
            valid = true;
        }   
    }  

    if(((newX == oldX - 1) && (newY == oldY + 2) )||( (newX == oldX + 1) && (newY == oldY + 2) )||( (newX == oldX + 1) && (newY == oldY - 2) )||( (newX == oldX - 1) && (newY == oldY - 2) )){
        if(board.getSquare(newX,newY)!=nullptr){// checks desitination point
            valid = false;
            if(board.getColourB(oldX,oldY) != board.getColourB(newX,newY) ){// capture logic
                valid = true;
            }
        }else if(board.getSquare(newX,newY) == nullptr){
            valid = true;
        }    
    }
    return valid;
}

//newX == oldX + 2 && ((newY == oldY + 1) || (newY == oldY - 1)) short hand way to write will put in 