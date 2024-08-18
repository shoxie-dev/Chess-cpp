#include "Queen.h"

Queen::Queen(bool isWhite_param){
    (isWhite_param == true)? symbol_param = 'Q' : symbol_param = 'q';
}

bool Queen::isValidMove(){
    return true;
}