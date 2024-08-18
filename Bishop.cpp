#include "Bishop.h"

Bishop::Bishop(bool isWhite_param){
    (isWhite_param == true)? symbol_param = 'B' : symbol_param = 'b';
}

bool Bishop::isValidMove(){
    return true;
}