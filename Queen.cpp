#include "Queen.h"

Queen::Queen(int x_param, int y_param,char colour_param) : Piece(x_param, y_param,(colour_param == 'W')? symbol_param = 'Q' : symbol_param = 'q', colour_param){
    
}

bool Queen::isValidMove(int oldX, int oldY, int newX, int newY, const Board& board, char colour_param){
    return true;
}