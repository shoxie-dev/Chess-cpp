#include "Knight.h"

Knight::Knight(char isWhite_param){
    (isWhite_param == 'W')? symbol_param = 'N' : symbol_param = 'n';
}

bool Knight::isValidMove(int oldX, int oldY, int newX, int newY, const Board& board, char isWhite_param){
    return true;
}