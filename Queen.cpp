#include "Queen.h"

Queen::Queen(int x_param, int y_param,char colour_param) : Piece(x_param, y_param,(colour_param == 'W')? symbol_param = 'Q' : symbol_param = 'q', colour_param){
    
}

bool Queen::isValidMove(int oldX, int oldY, int newX, int newY, Board& board, char colour_param){
    bool valid = false;
    int dC = oldX + oldY;   //y = mx + c
    int odC = oldX - oldY;
    if(newY == newX + odC || newY == -newX + dC){//bishop code
        valid = true;
    } else if((newX == oldX )||(newY == oldY)){//rook code
        valid = true;
    }
    return valid;
}