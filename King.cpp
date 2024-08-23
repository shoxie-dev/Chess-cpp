#include "King.h"

King::King(int x_param, int y_param,char colour_param) : Piece(x_param, y_param,(colour_param == 'W')? symbol_param = 'K' : symbol_param = 'k', colour_param){

}

bool King::isValidMove(int oldX, int oldY, int newX, int newY, Board& board, char colour_param){
    bool valid = false;
    if((newX == oldX - 1) && (newY == oldY)||(newX == oldX) && (newY == oldY + 1)||(newX == oldX + 1) && (newY == oldY)||(newX == oldX) && (newY == oldY - 1)){
        valid = true;    
    }  

    if(((newX == oldX - 1) && (newY == oldY - 1) )||( (newX == oldX + 1) && (newY == oldY + 1) )||( (newX == oldX + 1) && (newY == oldY - 1) )||( (newX == oldX - 1) && (newY == oldY + 1) )){
        valid = true;    
    }
    return valid;
}