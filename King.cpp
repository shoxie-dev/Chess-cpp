#include "King.h"
#include "Board.h"

King::King(char colour_param) : Piece((colour_param == 'W')? symbol_param = 'K' : symbol_param = 'k', colour_param){

}

bool King::isKingSafe(int x_i, int y_i,int x_f, int y_f, Board& board){
    bool safe{true};

    Board board_copy;
    board_copy = board;
    board_copy.setNull(x_i,y_i);

    char attack_colour{' '};
    for(int i{}; i < 8; ++i){
        for(int j{}; j < 8; ++j){
            if(board.getSquare(i, j) != nullptr){
                if(board.getColourB(x_i,y_i) != board.getColourB(i, j)){ // this assumes square is empty
                    attack_colour = board.getColourB(i, j);
                    if(board.getSquare(i,j)->getSymbol()!= 'K' && board.getSquare(i,j)->getSymbol()!='k'){
                        if(board.getSquare(i, j)->isValidMove(i, j, x_f, y_f, board_copy, attack_colour)){
                            safe = false;
                            
                        }
                        if(board.getSquare(x_f, y_f) != nullptr){//if square is not empty.
                                board_copy.setNull(x_f,y_f);
                            if(board.getSquare(i, j)->isValidMove(i, j, x_f, y_f, board_copy, attack_colour)){
                                safe =  false;
                            
                            }
                        }
                    }
                }
            }
            
        }
    }
    return safe;
}

bool King::isValidMove(int x_i, int y_i, int x_f, int y_f, Board& board, char colour_param){//colour_param = currentPlayer colour
    bool valid = false;
    if((x_f == x_i - 1) && (y_f == y_i)||(x_f == x_i) && (y_f == y_i + 1)||(x_f == x_i + 1) && (y_f == y_i)||(x_f == x_i) && (y_f == y_i - 1)){
        if(isKingSafe(x_i, y_i, x_f, y_f, board) && board.getSquare(x_f,y_f)!=nullptr ){// checks desitination point and needs a different functio
            valid = false;
            if(isKingSafe(x_i, y_i, x_f, y_f, board) && (board.getColourB(x_i,y_i) != board.getColourB(x_f,y_f)) ){// capture logic also needs &&isKingSafe(x_f,y_f)
                valid = true;
            }
        }else if( isKingSafe(x_i, y_i, x_f, y_f, board) && board.getSquare(x_f,y_f) == nullptr  ){// &&isKingSafe(x_f,y_f)
            valid = true;
        }    
    }  

    if(((x_f == x_i - 1) && (y_f == y_i - 1) )||( (x_f == x_i + 1) && (y_f == y_i + 1) )||( (x_f == x_i + 1) && (y_f == y_i - 1) )||( (x_f == x_i - 1) && (y_f == y_i + 1) )){
        if( isKingSafe(x_i, y_i, x_f, y_f, board) && board.getSquare(x_f,y_f)!=nullptr){// checks desitination point
            valid = false;
            if(isKingSafe(x_i, y_i, x_f, y_f, board) && (board.getColourB(x_i,y_i) != board.getColourB(x_f,y_f)) ){// capture logic
                valid = true;
            }
        }else if(isKingSafe(x_i, y_i, x_f, y_f, board) && board.getSquare(x_f,y_f) == nullptr ){
            valid = true;
        }    
    }

    //castling code
    if(x_f == x_i && y_f == y_i - 2){
        if(board.getSquare(x_i, y_i) != nullptr && board.getSquare(x_i , 0) != nullptr){//lhs rook
            if(isKingSafe(x_i, y_i, x_i, y_i-2,board) && board.getSquare(x_i,y_i)->getisMoved()==false && board.getSquare(x_i,0)->getisMoved()==false){
                if(board.getSquare(x_i, y_i - 1) == nullptr && board.getSquare(x_i, y_i - 2) == nullptr && board.getSquare(x_i, y_i - 3)== nullptr){
                    valid = true;
                    board.getSquare(x_i,y_i)->setCastled();
                }
            }
        }
    } else if(x_f == x_i && y_f == y_i + 2){
        if(board.getSquare(x_i, y_i) != nullptr && board.getSquare(x_i , 7) != nullptr){//lhs rook
            if(isKingSafe(x_i, y_i, x_i, y_i + 2,board) && board.getSquare(x_i,y_i)->getisMoved()==false && board.getSquare(x_i,7)->getisMoved()==false){
                if(board.getSquare(x_i, y_i + 1) == nullptr && board.getSquare(x_i, y_i + 2) == nullptr){
                    valid = true;
                    board.getSquare(x_i,y_i)->setCastled();
                }
            }
        }

    }

    return valid;
}

 