#include "Bishop.h"

Bishop::Bishop(char isWhite_param){
    (isWhite_param == 'W')? symbol_param = 'B' : symbol_param = 'b';
}

bool Bishop::isValidMove(int oldX, int oldY, int newX, int newY, const Board& board,char isWhite_param){
    return true;
}