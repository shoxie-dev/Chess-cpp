#include "King.h"

King::King(int x_param, int y_param,char colour_param) : Piece(x_param, y_param,(colour_param == 'W')? symbol_param = 'K' : symbol_param = 'k', colour_param){

}

bool King::isValidMove(int oldX, int oldY, int newX, int newY, const Board& board, char colour_param){
    return true;
}