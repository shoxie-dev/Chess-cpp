#include "Board.h"
#include "Pawn.h"
#include "King.h"
#include "Queen.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Player.h"
#include <iostream>
#include <iomanip>

Board::Board(){
    char white = 'W';
    char black = 'B';

    // *** WHITE PIECES ***

//    squares[7][4] = new King(7,4,white);
    
//    squares[6][4] = new Queen(6,4,white); //7 3
//    squares[7][0] = new Rook(7,0,white);
//    squares[7][7] = new Rook(7,7,white);
//    squares[4][4] = new Bishop(4,4,white);
//    squares[6][6] = new Bishop(6,6,white);
//    squares[7][1] = new Knight(7,1,white);
//    squares[7][5] = new Knight(7,5,white);
   

    for(int j{}; j < dim; ++j){
        squares[1][j] = new Pawn(1,j,white);
    }


    // *** BLACK PIECES ***

//    squares[0][4] = new King(0,4,black);

//    squares[2][4] = new Queen(2,4,black); // 0 3
//    squares[0][0] = new Rook(0,0,black);
//    squares[0][7] = new Rook(0,7,black);
//    squares[6][5] = new Bishop(6,5,black);
//    squares[6][6] = new Bishop(6,6,black);
//    squares[0][1] = new Knight(0,1,black);
//    squares[0][6] = new Knight(0,6,black);


    for(int j{}; j < dim; ++j){
        squares[6][j] = new Pawn(6,j,black);
    }




    
/*  
    for(int i{}; i < dim; ++i){
        for(int j{}; j < dim; ++j){
            squares_t[i][j] = squares[i][j]->getSymbol();//squares_t is for printing possible moves...
        }
    }
*/


}


void Board::printBoard(){
    for(int i{}; i < dim; ++i){
        for(int j{}; j < dim; ++j){
            if(squares[i][j] == nullptr){
                
                std::cout << std::setw(2) << '.';
            }
            else {
                getSquare(i,j)->display();
            }          
        }
        std::cout << '\n';
    }
}

void Board::movePiece(int startX, int startY, int endX, int endY){
    if(getSquare(endX,endY)!=nullptr){
        if(getSquare(startX,startY)->getSymbol() != getSquare(endX,endY)->getSymbol() ){// code for when a piece is getting taken
            setEmpty(endX,endY);
        }
    }

    if(getSquare(startX,startY)->capture_enPassant == true){// code for en passant capture
        std::cout << "inside enPassant movePiece code" << '\n';
        if(getSquare(startX,startY)->getColour() == 'W'){
            setEmpty(endX+1,endY);
        }
        std::cout << "fuck you: " << getSquare(startX,startY)-> getColour() << '\n';
        if(getSquare(startX,startY)->getColour() == 'B'){
            std::cout << "inside enPassant movePiece black" << '\n';
            setEmpty(endX-1,endY);    
        }
    }

    if(getSquare(startX, startY)->getCastled() == true && getCastle_onceW() == true){
        setCastle_onceW();
        if(startY > endY){
            squares[endX][startY-1] = squares[endX][0];
            squares[endX][0] = nullptr;
        }else if(startY < endY){
            squares[endX][startY+1] = squares[endX][7];
            squares[endX][7] = nullptr;
        }
    } else if(getSquare(startX, startY)->getCastled() == true && getCastle_onceB() == true){
        setCastle_onceB();
        if(startY > endY){
            squares[endX][startY-1] = squares[endX][0];
            squares[endX][0] = nullptr;
        }else if(startY < endY){
            squares[endX][startY+1] = squares[endX][7];
            squares[endX][7] = nullptr;
        }
    }


    squares[endX][endY] = squares[startX][startY];

    if(squares[startX][startY]->getisMoved() == false){
        squares[endX][endY]->setMoved();
    }


    squares[startX][startY] = nullptr; 
  
    squares[endX][endY]->setPosition(endX,endY);//useless get rid of it


}

void Board::pawnPromotion(char colour){
    if(colour == 'B'){
        int found{};
        for(int j{}; j < 8; ++j){
            if(getSquare(7,j) != nullptr && getSymbolB(7, j) == 'p'){
                found = j;
                bool valid_piece{false};
                int choice{};
                std::cout << "Choose a piece(numbers): " << '\n';
                std::cout << "1: Queen " << '\n';
                std::cout << "2: Knight " << '\n';
                std::cout << "3: Bishop " << '\n';
                std::cout << "4: Rook " << '\n';
                while(valid_piece == false){
                    std::cin >> choice;
                    if(choice == 1){
                        //setEmpty(7,found);
                        squares[7][found] = new Queen(7,found,'B');
                        break;
                    }else if(choice == 2){
                        //setEmpty(7,found);
                        squares[7][found] = new Knight(7,found,'B');
                        break;
                    }else if(choice == 3){
                        //setEmpty(7,found);
                        squares[7][found] = new Bishop(7,found,'B');
                        break;
                    }else if(choice == 4){
                        //setEmpty(7,found);
                        squares[7][found] = new Rook(7,found,'B');
                        break;
                    }else{
                        std::cout << "invalid piece selected, try again: " << '\n';
                    }
                }
                break;
            }
        }

    }

    if(colour == 'W'){
        int found{};
        for(int j{}; j < 8; ++j){
            if(getSquare(0,j) != nullptr && getSymbolB(0, j) == 'P'){
                found = j;
                bool valid_piece{false};
                int choice{};
                std::cout << "Choose a piece(numbers): " << '\n';
                std::cout << "1: Queen " << '\n';
                std::cout << "2: Knight " << '\n';
                std::cout << "3: Bishop " << '\n';
                std::cout << "4: Rook " << '\n';
                while(valid_piece == false){
                    std::cin >> choice;
                    if(choice == 1){
                        setEmpty(0,found);
                        squares[0][found] = new Queen(0,found,'W');
                        break;
                    }else if(choice == 2){
                        setEmpty(0,found);
                        squares[0][found] = new Knight(0,found,'W');
                        break;
                    }else if(choice == 3){
                        setEmpty(0,found);
                        squares[0][found] = new Bishop(0,found,'W');
                        break;
                    }else if(choice == 4){
                        setEmpty(0,found);
                        squares[0][found] = new Rook(0,found,'W');
                        break;
                    }else{
                        std::cout << "invalid piece selected, try again: " << '\n';
                    }
                }
                break;
            }
        }

    }
}




