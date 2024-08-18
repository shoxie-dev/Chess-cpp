#include "Knight.h"

Knight::Knight(bool isWhite_param){
    (isWhite_param == true)? symbol_param = 'N' : symbol_param = 'n';
}

bool Knight::isValidMove(){
    return true;
}