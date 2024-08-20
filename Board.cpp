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
    squares[7][4] = new King(white);
    squares[7][3] = new Queen(white);
    squares[7][7] = new Rook(white);
    squares[7][0] = new Rook(white);
    squares[7][2] = new Bishop(white);
    squares[7][5] = new Bishop(white);
    squares[7][1] = new Knight(white);
    squares[7][6] = new Knight(white);
    
    for(int j{}; j < dim; ++j){
        squares[6][j] = new Pawn(white);
    }

    // *** BLACK PIECES ***
    squares[0][4] = new King(black);
    squares[0][3] = new Queen(black);
    squares[0][7] = new Rook(black);
    squares[0][0] = new Rook(black);
    squares[0][2] = new Bishop(black);
    squares[0][5] = new Bishop(black);
    squares[0][1] = new Knight(black);
    squares[0][6] = new Knight(black);
    for(int j{}; j < dim; ++j){
        squares[1][j] = new Pawn(black);
    }
    
    
    for(int i{}; i < dim; ++i){
        for(int j{}; j < dim; ++j){
            squares_t[i][j] = squares[i][j];//squares_t is for printing possible moves...
        }
    }

}


void Board::printBoard(){
    for(int i{}; i < dim; ++i){
        for(int j{}; j < dim; ++j){
            if(squares[i][j] == nullptr){
                std::cout << std::setw(2) << '.';
            }
            else{
                squares[i][j]->display();
            }          
        }
        std::cout << '\n';
    }
}

void Board::movePiece(int startX, int startY, int endX, int endY){
    //std::cout <<  " piece coordinate address(before assignment) : " << &squares[startX][startY] << std::endl; //0x7ffde32f0fa8
    //std::cout <<  " position coordinate address(before assignment) : " << &squares[endX][endY] << std::endl; //x7ffde32f0f28
    squares[endX][endY] = squares[startX][startY];
    //std::cout <<  " old piece coordinate address(after assignment) : " << &squares[startX][startY] << std::endl; //0x7ffde32f0fa8
    //std::cout <<  " piece coordinate address(after assignment) : " << &squares[endX][endY] << std::endl; //0x7ffde32f0f28
    squares[startX][startY] = nullptr;
    //why doesnt it segfault when checking the address at the nullptr? is it because the 2d array

}
/*
    pt1
    if i were to have an empty space object
    delete empty space
    assign nullptr to empty space
    then move piece to nullptr

    pt2
    delete piece at old square
    then assign nullptr
    then assign new empty space

*/

