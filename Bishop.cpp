#include "Bishop.h"

Bishop::Bishop(int x_param, int y_param,char colour_param) : Piece(x_param,y_param,(colour_param == 'W')? symbol_param = 'B' : symbol_param = 'b', colour_param){

}

bool Bishop::isValidMove(int oldX, int oldY, int newX, int newY, Board& board,char colour_param){
    bool valid = false;
    int dC = oldX + oldY;   //y = mx + c
    int odC = oldX - oldY;
    if(newY == newX + odC || newY == -newX + dC){
        valid = true;
    }
    return valid;
}