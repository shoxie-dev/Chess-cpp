#include "King.h"
#include "Board.h"

King::King(int x_param, int y_param,char colour_param) : Piece(x_param, y_param,(colour_param == 'W')? symbol_param = 'K' : symbol_param = 'k', colour_param){

}

bool King::isKingSafe(int oldX, int oldY,int newX, int newY, Board& board){
    bool safe{true};

    Board board_copy;
    board_copy = board;

    char attack_colour{' '};
    for(int i{}; i < 8; ++i){
        for(int j{}; j < 8; ++j){
            if(board.getSquare(i, j) != nullptr){
                if(board.getColourB(oldX,oldY) != board.getColourB(i, j)){ // this assumes square is empty
                    attack_colour = board.getColourB(i, j);
                    if(board.getSquare(i, j)->isValidMove(i, j, newX, newY, board, attack_colour)){
                        return false;
                    }
                    if(board.getSquare(newX, newY) != nullptr){//if square is not empty.
                        board_copy.setNull(newX,newY);
                        if(board.getSquare(i, j)->isValidMove(i, j, newX, newY, board_copy, attack_colour)){
                            return false;
                        }
                    }
                }
            }
        }
    }

    
    return safe;
}

bool King::isValidMove(int oldX, int oldY, int newX, int newY, Board& board, char colour_param){//colour_param = currentPlayer colour
    bool valid = false;
    if((newX == oldX - 1) && (newY == oldY)||(newX == oldX) && (newY == oldY + 1)||(newX == oldX + 1) && (newY == oldY)||(newX == oldX) && (newY == oldY - 1)){
        if(board.getSquare(newX,newY)!=nullptr && isKingSafe(oldX, oldY, newX, newY, board)){// checks desitination point and needs a different functio
            valid = false;
            if((board.getColourB(oldX,oldY) != board.getColourB(newX,newY)) && isKingSafe(oldX, oldY, newX, newY, board)){// capture logic also needs &&isKingSafe(newX,newY)
                valid = true;
            }
        }else if(board.getSquare(newX,newY) == nullptr  && isKingSafe(oldX, oldY, newX, newY, board)){// &&isKingSafe(newX,newY)
            valid = true;
        }    
    }  

    if(((newX == oldX - 1) && (newY == oldY - 1) )||( (newX == oldX + 1) && (newY == oldY + 1) )||( (newX == oldX + 1) && (newY == oldY - 1) )||( (newX == oldX - 1) && (newY == oldY + 1) )){
        if(board.getSquare(newX,newY)!=nullptr && isKingSafe(oldX, oldY, newX, newY, board)){// checks desitination point
            valid = false;
            if((board.getColourB(oldX,oldY) != board.getColourB(newX,newY)) && isKingSafe(oldX, oldY, newX, newY, board)){// capture logic
                valid = true;
            }
        }else if(board.getSquare(newX,newY) == nullptr && isKingSafe(oldX, oldY, newX, newY, board)){
            valid = true;
        }    
    }
    return valid;
}

 