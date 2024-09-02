#include "Pawn.h"
#include "Board.h"

Pawn::Pawn(char colour_param) : Piece((colour_param == 'W')? symbol_param = 'P' : symbol_param = 'p', colour_param){
   
}

bool Pawn::isValidMove(int x_i, int y_i, int x_f, int y_f, Board& board, char colour_param){
    bool valid = false;
    if(colour_param == 'B'){
        if(board.getSquare(x_i,y_i)->getisMoved() == false){// strictly movement
            if((x_f == x_i + 1 && y_f == y_i) || (x_f == x_i + 2 && y_f == y_i)){
                if(board.getSquare(x_f,y_f)!=nullptr){// checks desitination point
                    valid = false;
                }else if(board.getSquare(x_f,y_f) == nullptr){
                    valid = true;
                    if(x_f == x_i + 2 && y_f == y_i){
                        std::cout << "En passant active" << '\n';
                        board.getSquare(x_i,y_i)->setenPassant(true);
                    }
                }   
            }

            if(x_f == x_i + 1 && y_f == y_i + 1 || x_f == x_i + 1 && y_f == y_i - 1){
                if(board.getSquare(x_f,y_f) != nullptr){
                    if(board.getColourB(x_i,y_i) != board.getColourB(x_f,y_f) ){
                        valid = true;
                    }
                }

            } 
            
        }else{
            if(x_f == x_i + 1  && y_f == y_i){
                if(board.getSquare(x_f,y_f)!=nullptr){// checks desitination point
                    valid = false;
                }else if(board.getSquare(x_f,y_f) == nullptr){
                    valid = true;
                    board.getSquare(x_i,y_i)->setenPassant(false);
                }  
            }
            if(x_f == x_i + 1 && y_f == y_i + 1 || x_f == x_i + 1 && y_f == y_i - 1){
                if(board.getSquare(x_f,y_f) != nullptr){
                    if(board.getColourB(x_i,y_i) != board.getColourB(x_f,y_f) ){// capture logic
                        valid = true;
                        board.getSquare(x_i,y_i)->setenPassant(false);
                    }
                }
                //En_Passant capture
                if(board.getSquare(x_i,y_i - 1) != nullptr){
                    if(board.getColourB(x_i,y_i) != board.getColourB(x_i,y_i - 1)){
                        if(board.getSquare(x_i,y_i - 1) -> getenPassant() == true){
                            if(board.getSquare(x_f - 1, y_f) != nullptr){
                                if(board.getSquare(x_f - 1,y_f)->getSymbol() == 'P'){
                                    valid = true;
                                    board.getSquare(x_i,y_i)->setenPassant(false);
                                    board.getSquare(x_i,y_i)->setenPassant_capture();
                                }
                            }
                        }                          
                    }
                }
                if(board.getSquare(x_i,y_i + 1) != nullptr){
                    if(board.getColourB(x_i,y_i) != board.getColourB(x_i,y_i + 1) ){
                        if(board.getSquare(x_i,y_i + 1) -> getenPassant() == true ){
                            if(board.getSquare(x_f - 1, y_f) != nullptr){
                                if(board.getSquare(x_f - 1,y_f)->getSymbol() == 'P'){
                                    valid = true;
                                    board.getSquare(x_i,y_i)->setenPassant(false);
                                    board.getSquare(x_i,y_i)->setenPassant_capture();
                                }
                            }
                        }                          
                    }
                }
            } 
        }
    }

    if(colour_param == 'W'){
        
        if(board.getSquare(x_i,y_i)->getisMoved() == false){
            if((x_f == x_i - 1 && y_f == y_i) || (x_f == x_i - 2   && y_f == y_i)){
                if(board.getSquare(x_f,y_f)!=nullptr){// checks desitination point
                    valid = false;
                }else if(board.getSquare(x_f,y_f) == nullptr){
                    valid = true;
                    if(x_f == x_i - 2 && y_f == y_i){
                        std::cout << "En passant active" << '\n';
                        board.getSquare(x_i,y_i)->setenPassant(true);
                    }
                }   
            }

            if(x_f == x_i - 1 && y_f == y_i + 1 || x_f == x_i - 1 && y_f == y_i - 1){
                if(board.getSquare(x_f,y_f) != nullptr){
                    if(board.getColourB(x_i,y_i) != board.getColourB(x_f,y_f) ){// capture logic
                        valid = true;
                    }
                }
            } 

            
        }else{
            if(x_f == x_i - 1 && y_f == y_i){
                if(board.getSquare(x_f,y_f)!=nullptr){// checks desitination point
                    valid = false;
                }else if(board.getSquare(x_f,y_f) == nullptr){
                    valid = true;
                    board.getSquare(x_i,y_i)->setenPassant(false);
                }   
            }

            if(x_f == x_i - 1 && y_f == y_i + 1 || x_f == x_i - 1 && y_f == y_i - 1){// capture logic
                if(board.getSquare(x_f,y_f) != nullptr){
                    if(board.getColourB(x_i,y_i) != board.getColourB(x_f,y_f) ){
                        valid = true;
                    }
                }
                //En_Passant capture 
                if(board.getSquare(x_i,y_i - 1) != nullptr){
                    if(board.getColourB(x_i,y_i) != board.getColourB(x_i,y_i - 1)){
                        if(board.getSquare(x_i,y_i - 1) -> getenPassant()==true){
                            if(board.getSquare(x_f + 1, y_f) != nullptr){
                                if(board.getSquare(x_f + 1,y_f)->getSymbol() == 'p'){
                                    valid = true;
                                    board.getSquare(x_i,y_i)->setenPassant(false);
                                    board.getSquare(x_i,y_i)->setenPassant_capture();
                                }
                            }
                        }                          
                    }
                }
                if(board.getSquare(x_i,y_i + 1) != nullptr){
                    if(board.getColourB(x_i,y_i) != board.getColourB(x_i,y_i + 1) ){
                        if(board.getSquare(x_i,y_i + 1) -> getenPassant()==true ){
                            if(board.getSquare(x_f + 1, y_f) != nullptr){
                                if(board.getSquare(x_f + 1,y_f)->getSymbol() == 'p'){
                                    valid = true;
                                    board.getSquare(x_i,y_i)->setenPassant(false);
                                    board.getSquare(x_i,y_i)->setenPassant_capture();
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

 