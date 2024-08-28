#include "Pawn.h"
#include "Board.h"

Pawn::Pawn(int x_param, int y_param,char colour_param) : Piece(x_param, y_param,(colour_param == 'W')? symbol_param = 'P' : symbol_param = 'p', colour_param){
   
}

bool Pawn::isValidMove(int oldX, int oldY, int newX, int newY, Board& board, char colour_param){
    bool valid = false;
    if(colour_param == 'B'){
        if(board.getSquare(oldX,oldY)->getisMoved() == false){// strictly movement
            if((newX == oldX + 1 && newY == oldY) || (newX == oldX + 2 && newY == oldY)){
                if(board.getSquare(newX,newY)!=nullptr){// checks desitination point
                    valid = false;
                }else if(board.getSquare(newX,newY) == nullptr){
                    valid = true;
                    if(newX == oldX + 2 && newY == oldY){
                        std::cout << "En passant active" << '\n';
                        board.getSquare(oldX,oldY)->setenPassant(true);
                    }
                }   
            }

            if(newX == oldX + 1 && newY == oldY + 1 || newX == oldX + 1 && newY == oldY - 1){
                if(board.getSquare(newX,newY) != nullptr){
                    if(board.getColourB(oldX,oldY) != board.getColourB(newX,newY) ){
                        valid = true;
                    }
                }

            } 
            
        }else{
            if(newX == oldX + 1  && newY == oldY){
                if(board.getSquare(newX,newY)!=nullptr){// checks desitination point
                    valid = false;
                }else if(board.getSquare(newX,newY) == nullptr){
                    valid = true;
                    board.getSquare(oldX,oldY)->setenPassant(false);
                }  
            }
            if(newX == oldX + 1 && newY == oldY + 1 || newX == oldX + 1 && newY == oldY - 1){
                if(board.getSquare(newX,newY) != nullptr){
                    if(board.getColourB(oldX,oldY) != board.getColourB(newX,newY) ){// capture logic
                        valid = true;
                        board.getSquare(oldX,oldY)->setenPassant(false);
                    }
                }
                //En_Passant capture
                if(board.getSquare(oldX,oldY - 1) != nullptr){
                    if(board.getColourB(oldX,oldY) != board.getColourB(oldX,oldY - 1)){
                        if(board.getSquare(oldX,oldY - 1) -> getenPassant() == true){
                            if(board.getSquare(newX - 1, newY) != nullptr){
                                if(board.getSquare(newX - 1,newY)->getSymbol() == 'P'){
                                    valid = true;
                                    board.getSquare(oldX,oldY)->setenPassant(false);
                                    board.getSquare(oldX,oldY)->setenPassant_capture();
                                }
                            }
                        }                          
                    }
                }
                if(board.getSquare(oldX,oldY + 1) != nullptr){
                    if(board.getColourB(oldX,oldY) != board.getColourB(oldX,oldY + 1) ){
                        if(board.getSquare(oldX,oldY + 1) -> getenPassant() == true ){
                            if(board.getSquare(newX - 1, newY) != nullptr){
                                if(board.getSquare(newX - 1,newY)->getSymbol() == 'P'){
                                    valid = true;
                                    board.getSquare(oldX,oldY)->setenPassant(false);
                                    board.getSquare(oldX,oldY)->setenPassant_capture();
                                }
                            }
                        }                          
                    }
                }
            } 
        }
    }

    if(colour_param == 'W'){
        
        if(board.getSquare(oldX,oldY)->getisMoved() == false){
            if((newX == oldX - 1 && newY == oldY) || (newX == oldX - 2   && newY == oldY)){
                if(board.getSquare(newX,newY)!=nullptr){// checks desitination point
                    valid = false;
                }else if(board.getSquare(newX,newY) == nullptr){
                    valid = true;
                    if(newX == oldX - 2 && newY == oldY){
                        std::cout << "En passant active" << '\n';
                        board.getSquare(oldX,oldY)->setenPassant(true);
                    }
                }   
            }

            if(newX == oldX - 1 && newY == oldY + 1 || newX == oldX - 1 && newY == oldY - 1){
                if(board.getSquare(newX,newY) != nullptr){
                    if(board.getColourB(oldX,oldY) != board.getColourB(newX,newY) ){// capture logic
                        valid = true;
                    }
                }
            } 

            
        }else{
            if(newX == oldX - 1 && newY == oldY){
                if(board.getSquare(newX,newY)!=nullptr){// checks desitination point
                    valid = false;
                }else if(board.getSquare(newX,newY) == nullptr){
                    valid = true;
                    board.getSquare(oldX,oldY)->setenPassant(false);
                }   
            }

            if(newX == oldX - 1 && newY == oldY + 1 || newX == oldX - 1 && newY == oldY - 1){// capture logic
                if(board.getSquare(newX,newY) != nullptr){
                    if(board.getColourB(oldX,oldY) != board.getColourB(newX,newY) ){
                        valid = true;
                    }
                }
                //En_Passant capture 
                if(board.getSquare(oldX,oldY - 1) != nullptr){
                    if(board.getColourB(oldX,oldY) != board.getColourB(oldX,oldY - 1)){
                        if(board.getSquare(oldX,oldY - 1) -> getenPassant()==true){
                            if(board.getSquare(newX + 1, newY) != nullptr){
                                if(board.getSquare(newX + 1,newY)->getSymbol() == 'p'){
                                    valid = true;
                                    board.getSquare(oldX,oldY)->setenPassant(false);
                                    board.getSquare(oldX,oldY)->setenPassant_capture();
                                }
                            }
                        }                          
                    }
                }
                if(board.getSquare(oldX,oldY + 1) != nullptr){
                    if(board.getColourB(oldX,oldY) != board.getColourB(oldX,oldY + 1) ){
                        if(board.getSquare(oldX,oldY + 1) -> getenPassant()==true ){
                            if(board.getSquare(newX + 1, newY) != nullptr){
                                if(board.getSquare(newX + 1,newY)->getSymbol() == 'p'){
                                    valid = true;
                                    board.getSquare(oldX,oldY)->setenPassant(false);
                                    board.getSquare(oldX,oldY)->setenPassant_capture();
                                }
                            }
                        }                          
                    }
                }
            }  
        }

    }
    return valid;
}

 