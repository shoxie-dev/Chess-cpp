#include "King.h"
#include "Board.h"

King::King(int x_param, int y_param,char colour_param) : Piece(x_param, y_param,(colour_param == 'W')? symbol_param = 'K' : symbol_param = 'k', colour_param){

}

bool King::isKingSafe(int oldX, int oldY,int newX, int newY, Board& board){
    bool safe{true};

    Board board_copy;
    board_copy = board;
    board_copy.setNull(oldX,oldY);

    char attack_colour{' '};
    for(int i{}; i < 8; ++i){
        for(int j{}; j < 8; ++j){
            if(board.getSquare(i, j) != nullptr){
                if(board.getColourB(oldX,oldY) != board.getColourB(i, j)){ // this assumes square is empty
                    attack_colour = board.getColourB(i, j);
                    if(board.getSquare(i,j)->getSymbol()!= 'K' && board.getSquare(i,j)->getSymbol()!='k'){
                        //std::cout << "Symbol "  << board.getSquare(i,j)-> getSymbol() << " @ : (" << i << ", " << j << ")\n" ; 
                    if(board.getSquare(i, j)->isValidMove(i, j, newX, newY, board_copy, attack_colour)){
                        safe = false;
                        
                    }
                    if(board.getSquare(newX, newY) != nullptr){//if square is not empty.
                            board_copy.setNull(newX,newY);
                        if(board.getSquare(i, j)->isValidMove(i, j, newX, newY, board_copy, attack_colour)){
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

bool King::isValidMove(int oldX, int oldY, int newX, int newY, Board& board, char colour_param){//colour_param = currentPlayer colour
    bool valid = false;
    if((newX == oldX - 1) && (newY == oldY)||(newX == oldX) && (newY == oldY + 1)||(newX == oldX + 1) && (newY == oldY)||(newX == oldX) && (newY == oldY - 1)){
        if(isKingSafe(oldX, oldY, newX, newY, board) && board.getSquare(newX,newY)!=nullptr ){// checks desitination point and needs a different functio
            valid = false;
            if(isKingSafe(oldX, oldY, newX, newY, board) && (board.getColourB(oldX,oldY) != board.getColourB(newX,newY)) ){// capture logic also needs &&isKingSafe(newX,newY)
                valid = true;
            }
        }else if( isKingSafe(oldX, oldY, newX, newY, board) && board.getSquare(newX,newY) == nullptr  ){// &&isKingSafe(newX,newY)
            valid = true;
        }    
    }  

    if(((newX == oldX - 1) && (newY == oldY - 1) )||( (newX == oldX + 1) && (newY == oldY + 1) )||( (newX == oldX + 1) && (newY == oldY - 1) )||( (newX == oldX - 1) && (newY == oldY + 1) )){
        if( isKingSafe(oldX, oldY, newX, newY, board) && board.getSquare(newX,newY)!=nullptr){// checks desitination point
            valid = false;
            if(isKingSafe(oldX, oldY, newX, newY, board) && (board.getColourB(oldX,oldY) != board.getColourB(newX,newY)) ){// capture logic
                valid = true;
            }
        }else if(isKingSafe(oldX, oldY, newX, newY, board) && board.getSquare(newX,newY) == nullptr ){
            valid = true;
        }    
    }

    //castling code
    if(newX == oldX && newY == oldY - 2){
        if(board.getSquare(oldX, oldY) != nullptr && board.getSquare(oldX , 0) != nullptr){//lhs rook
            if(isKingSafe(oldX, oldY, oldX, oldY-2,board) && board.getSquare(oldX,oldY)->getisMoved()==false && board.getSquare(oldX,0)->getisMoved()==false){
                if(board.getSquare(oldX, oldY - 1) == nullptr && board.getSquare(oldX, oldY - 2) == nullptr && board.getSquare(oldX, oldY - 3)== nullptr){
                    valid = true;
                    board.getSquare(oldX,oldY)->setCastled();
                }
            }
        }
    } else if(newX == oldX && newY == oldY + 2){
        if(board.getSquare(oldX, oldY) != nullptr && board.getSquare(oldX , 7) != nullptr){//lhs rook
            if(isKingSafe(oldX, oldY, oldX, oldY + 2,board) && board.getSquare(oldX,oldY)->getisMoved()==false && board.getSquare(oldX,7)->getisMoved()==false){
                if(board.getSquare(oldX, oldY + 1) == nullptr && board.getSquare(oldX, oldY + 2) == nullptr){
                    valid = true;
                    board.getSquare(oldX,oldY)->setCastled();
                }
            }
        }

    }

    return valid;
}

 