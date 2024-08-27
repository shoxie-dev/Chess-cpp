#include "King.h"
#include "Board.h"

King::King(int x_param, int y_param,char colour_param) : Piece(x_param, y_param,(colour_param == 'W')? symbol_param = 'K' : symbol_param = 'k', colour_param){

}

bool King::isValidMove(int oldX, int oldY, int newX, int newY, Board& board, char colour_param){
    //TODO : isKingSafe(newX,newY)
    bool valid = false;
    if((newX == oldX - 1) && (newY == oldY)||(newX == oldX) && (newY == oldY + 1)||(newX == oldX + 1) && (newY == oldY)||(newX == oldX) && (newY == oldY - 1)){
        if(board.getSquare(newX,newY)!=nullptr){// checks desitination point and needs a different functio
            valid = false;
            if(board.getColourB(oldX,oldY) != board.getColourB(newX,newY) ){// capture logic also needs isKingSafe(newX,newY)
                valid = true;
            }
        }else if(board.getSquare(newX,newY) == nullptr){// isKingSafe(newX,newY)
            valid = true;
        }    
    }  

    if(((newX == oldX - 1) && (newY == oldY - 1) )||( (newX == oldX + 1) && (newY == oldY + 1) )||( (newX == oldX + 1) && (newY == oldY - 1) )||( (newX == oldX - 1) && (newY == oldY + 1) )){
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

 