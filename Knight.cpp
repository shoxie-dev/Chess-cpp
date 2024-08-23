#include "Knight.h"

Knight::Knight(int x_param, int y_param,char colour_param) : Piece(x_param,y_param,(colour_param == 'W')? symbol_param = 'N' : symbol_param = 'n', colour_param){
 
}

bool Knight::isValidMove(int oldX, int oldY, int newX, int newY, Board& board, char colour_param){
    bool valid = false;
    if((newX == oldX + 2) && (newY == oldY + 1)||(newX == oldX - 2) && (newY == oldY + 1)||(newX == oldX + 2) && (newY == oldY - 1)||(newX == oldX - 2) && (newY == oldY - 1)){
        valid = true;    
    }  

    if(((newX == oldX - 1) && (newY == oldY + 2) )||( (newX == oldX + 1) && (newY == oldY + 2) )||( (newX == oldX + 1) && (newY == oldY - 2) )||( (newX == oldX - 1) && (newY == oldY + 2) )){
        valid = true;    
    }
    return valid;
}

//newX == oldX + 2 && ((newY == oldY + 1) || (newY == oldY - 1)) short hand way to write will put in 