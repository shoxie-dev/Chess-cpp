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

Board::Board(){//x y (is default positions)
    char white = 'W';
    char black = 'B';

    // *** WHITE PIECES ***

    squares[7][4] = new King(7,4,white); // 7 4
    
    squares[1][5] = new Queen(1,5,white); //7 3
//    squares[7][0] = new Rook(7,0,white); // 7 0
//    squares[7][7] = new Rook(7,7,white); // 7 7
//    squares[7][2] = new Bishop(7,2,white); // 7 2
//    squares[7][5] = new Bishop(7,5,white); // 7 5
//    squares[7][1] = new Knight(7,1,white); // 7 1
//    squares[7][6] = new Knight(7,6,white); // 7 6
   
/*
    for(int j{}; j < dim; ++j){
        squares[6][j] = new Pawn(6,j,white);
    }
*/


    // *** BLACK PIECES ***

    squares[0][0] = new King(0,0,black); //0 4

//    squares[0][3] = new Queen(0,3,black); // 0 3
//    squares[0][0] = new Rook(0,0,black); // 0 0
//    squares[0][7] = new Rook(0,7,black); // 0 7
//    squares[0][5] = new Bishop(0,5,black); // 0 5
//    squares[0][2] = new Bishop(0,2,black); // 0 2
//    squares[0][1] = new Knight(0,1,black); // 0 1
//    squares[0][6] = new Knight(0,6,black); // 0 6

/*
    for(int j{}; j < dim; ++j){
        squares[1][j] = new Pawn(1,j,black);
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
            setTaken(endX,endY);
        }
    }

    if(getSquare(startX,startY)->capture_enPassant == true){// code for en passant capture
        std::cout << "inside enPassant movePiece code" << '\n';
        if(getSquare(startX,startY)->getColour() == 'W'){
            setTaken(endX+1,endY);
        }
        std::cout << "fuck you: " << getSquare(startX,startY)-> getColour() << '\n';
        if(getSquare(startX,startY)->getColour() == 'B'){
            std::cout << "inside enPassant movePiece black" << '\n';
            setTaken(endX-1,endY);    
        }
    }

    if(getSquare(startX, startY)->getCastled() == true && getCastle_onceW() == true){//using squares directly is bad use setters and getters
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
                        setTaken(7,found);
                        squares[7][found] = new Queen(7,found,'B');
                        break;
                    }else if(choice == 2){
                        setTaken(7,found);
                        squares[7][found] = new Knight(7,found,'B');
                        break;
                    }else if(choice == 3){
                        setTaken(7,found);
                        squares[7][found] = new Bishop(7,found,'B');
                        break;
                    }else if(choice == 4){
                        setTaken(7,found);
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
                        setTaken(0,found);
                        squares[0][found] = new Queen(0,found,'W');
                        break;
                    }else if(choice == 2){
                        setTaken(0,found);
                        squares[0][found] = new Knight(0,found,'W');
                        break;
                    }else if(choice == 3){
                        setTaken(0,found);
                        squares[0][found] = new Bishop(0,found,'W');
                        break;
                    }else if(choice == 4){
                        setTaken(0,found);
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

bool Board::isCheck(char colour,int& k_x, int& k_y){//player colour and coordinates of  king piece
    bool king_check{false};
    
    if(colour == 'B'){
        std::cout << "inside W check" << '\n'; 
        bool found{false};
        for(int i{}; i < 8; ++i){ // code to find king on board
            for(int j{}; j < 8; ++j){
                if(getSquare(i, j) != nullptr){
                    if(getSquare(i, j) -> getSymbol() == 'K'){
                        k_x = i;
                        k_y = j;
                        found = true;
                        break;
                    }
                }
            }
            if(found == true){
                break;
            }
        }
        char attack_colour{' '};
        for(int i{}; i < 8; ++i){
            for(int j{}; j < 8; ++j){
                if(getSquare(i, j) != nullptr){
                    if(getColourB(k_x, k_y) != getColourB(i, j)){ 
                        attack_colour = getColourB(i, j);
                        if(getSquare(i, j)->isValidMove(i, j, k_x, k_y, *this, attack_colour)){
                            king_check = true;
                            std::cout << "White King is in check" << '\n';
                            break;
                        }
                    }
                }
            }
            if(king_check == true){// to break out of outer loop
                break;
            }
            
        }

    }else if(colour == 'W'){
        bool found{false};
        for(int i{}; i < 8; ++i){ // code to find king on board
            for(int j{}; j < 8; ++j){
                if(getSquare(i, j) != nullptr){
                    if(getSquare(i, j) -> getSymbol() == 'k'){
                        k_x = i;
                        k_y = j;
                        found = true;
                        break;
                    }
                }
            }
            if(found == true){
                break;
            }
        }
        char attack_colour{' '};
        for(int i{}; i < 8; ++i){
            for(int j{}; j < 8; ++j){
                if(getSquare(i, j) != nullptr){
                    if(getColourB(k_x, k_y) != getColourB(i, j)){ 
                        attack_colour = getColourB(i, j);
                        if(getSquare(i, j)->isValidMove(i, j, k_x, k_y, *this, attack_colour)){
                            king_check = true;
                            std::cout << "Black King is in check" << '\n';
                            break;
                        }
                    }
                }
            }
            if(king_check == true){// to break out of outer loop
                break;
            }
            
        }

    }
    
    return king_check;
}

bool Board::isCheckmate(char colour){//attacking colour

    bool king_checkmate{false};

    if(colour == 'B'){//check if W is checkmated
        bool found{false};
        int k_x{};
        int k_y{};
        bool b1{false};
        bool b2{false};
        bool b3{false};
        bool b4{false};
        bool b5{false};
        bool b6{false};
        bool b7{false};
        bool b8{false};
        for(int i{}; i < 8; ++i){
            for(int j{}; j < 8; ++j){
                if(getSquare(i,j) != nullptr && getSymbolB(i, j) == 'K'){
                    k_x = i;
                    k_y = j;
                    found = true;
                    break;
                }
            }
            if(found == true){
                break;
            }
        }
        
        if(k_x - 1 >= 0){
            
            if((k_y - 1)>=0){
                b1 = isKingSafeB(k_x, k_y, k_x - 1, k_y - 1);
                
            }
            if(k_y + 1 < 8){
                b2 =isKingSafeB(k_x, k_y, k_x - 1, k_y + 1); 
                  
            }
            b3 = isKingSafeB(k_x, k_y, k_x - 1, k_y);
            
        }

        if( (k_x + 1 < 8) ){
            
            if((k_y - 1)>= 0){
                b4 = isKingSafeB(k_x, k_y, k_x + 1, k_y - 1);
                
            }
            if(k_y + 1 < 8){
                b5 = isKingSafeB(k_x, k_y, k_x + 1, k_y + 1 );
                   
            }
            b6 = isKingSafeB(k_x, k_y, k_x + 1, k_y);
           

        }

        if(k_y - 1 >= 0){//k_x
            b7 = isKingSafeB(k_x, k_y, k_x , k_y - 1);
            
        }
        if(k_y + 1 < 8){
           b8 = isKingSafeB(k_x, k_y, k_x , k_y + 1);
            std::cout << "b8 : " << b8 << '\n';
        }

        // i think this is probably the worst thing i have ever coded, lord please forgive me

        if(b1 == false && b2 == false && b3 == false && b4 == false && b5 == false && b6 == false && b7 == false && b8 == false){
            king_checkmate = true;
            std::cout << "Checkmate: white wins" << '\n';
        }


    }else if(colour == 'W'){//check if B is checkmated
        bool found{false};
        int k_x{};
        int k_y{};
        bool b1{false};
        bool b2{false};
        bool b3{false};
        bool b4{false};
        bool b5{false};
        bool b6{false};
        bool b7{false};
        bool b8{false};
        for(int i{}; i < 8; ++i){
            for(int j{}; j < 8; ++j){
                if(getSquare(i,j) != nullptr && getSymbolB(i, j) == 'k'){
                    k_x = i;
                    k_y = j;
                    found = true;
                    break;
                }
            }
            if(found == true){
                break;
            }
        }
        
        if(k_x - 1 >= 0){
            
            if((k_y - 1)>=0){
                b1 = isKingSafeB(k_x, k_y, k_x - 1, k_y - 1);
                
            }
            if(k_y + 1 < 8){
                b2 =isKingSafeB(k_x, k_y, k_x - 1, k_y + 1); 
                  
            }
            b3 = isKingSafeB(k_x, k_y, k_x - 1, k_y);
            
        }

        if( (k_x + 1 < 8) ){
            
            if((k_y - 1)>= 0){
                b4 = isKingSafeB(k_x, k_y, k_x + 1, k_y - 1);
                
            }
            if(k_y + 1 < 8){
                b5 = isKingSafeB(k_x, k_y, k_x + 1, k_y + 1 );
                   
            }
            b6 = isKingSafeB(k_x, k_y, k_x + 1, k_y);
           

        }

        if(k_y - 1 >= 0){//k_x
            b7 = isKingSafeB(k_x, k_y, k_x , k_y - 1);
            
        }
        if(k_y + 1 < 8){
           b8 = isKingSafeB(k_x, k_y, k_x , k_y + 1);
            std::cout << "b8 : " << b8 << '\n';
        }

        // i think this is probably the worst thing i have ever coded, lord please forgive me

        if(b1 == false && b2 == false && b3 == false && b4 == false && b5 == false && b6 == false && b7 == false && b8 == false){
            king_checkmate = true;
            std::cout << "Checkmate: white wins" << '\n';
        }

    }


    return king_checkmate;
}

bool Board::isKingSafeB(int oldX, int oldY,int newX, int newY){
    bool safe{true};

    Board board_copy;
    board_copy = *this;
    board_copy.setNull(oldX,oldY);    

    char attack_colour{' '};
    for(int i{}; i < 8; ++i){
        for(int j{}; j < 8; ++j){
            if(getSquare(i, j) != nullptr){
                if(getColourB(oldX,oldY) != getColourB(i, j)){ // this assumes square is empty
                    attack_colour = getColourB(i, j);
                    if(getSquare(i,j)->getSymbol()!= 'K' && getSquare(i,j)->getSymbol()!='k'){
                    if(getSquare(i, j)->isValidMove(i, j, newX, newY, board_copy, attack_colour)){
                        safe = false;
                        
                    }
                    if(getSquare(newX, newY) != nullptr){//if square is not empty.
                            board_copy.setNull(newX,newY);
                        if(getSquare(i, j)->isValidMove(i, j, newX, newY, board_copy, attack_colour)){
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

bool Board::isStalemate(char colour, int k_x, int k_y){
    
    bool king_check = isCheck(colour,k_x, k_y);
    bool stale_mate{false};
    bool b1{false};
    bool b2{false};
    bool b3{false};
    bool b4{false};
    bool b5{false};
    bool b6{false};
    bool b7{false};
    bool b8{false};

    if(king_check == false){
        if(k_x - 1 >= 0){
            
            if((k_y - 1)>=0){
                b1 = isKingSafeB(k_x, k_y, k_x - 1, k_y - 1);
                
            }
            if(k_y + 1 < 8){
                b2 =isKingSafeB(k_x, k_y, k_x - 1, k_y + 1); 
                  
            }
            b3 = isKingSafeB(k_x, k_y, k_x - 1, k_y);
            
        }

        if( (k_x + 1 < 8) ){
            
            if((k_y - 1)>= 0){
                b4 = isKingSafeB(k_x, k_y, k_x + 1, k_y - 1);
                
            }
            if(k_y + 1 < 8){
                b5 = isKingSafeB(k_x, k_y, k_x + 1, k_y + 1 );
                   
            }
            b6 = isKingSafeB(k_x, k_y, k_x + 1, k_y);
           

        }

        if(k_y - 1 >= 0){//k_x
            b7 = isKingSafeB(k_x, k_y, k_x , k_y - 1);
            
        }
        if(k_y + 1 < 8){
           b8 = isKingSafeB(k_x, k_y, k_x , k_y + 1);
        }
         if(b1 == false && b2 == false && b3 == false && b4 == false && b5 == false && b6 == false && b7 == false && b8 == false){
            stale_mate = true;
            std::cout << "Stalemate: draw " << '\n';
        }

    }
    return stale_mate;
}



