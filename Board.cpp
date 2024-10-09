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

    initPiece(7, 4, new King(white)); // 7 4

    initPiece(7, 3, new Queen(white));// 7 3
    initPiece(7, 0, new Rook(white));// 7 0
    initPiece(7, 7, new Rook(white));// 7 7
    initPiece(7, 2, new Bishop(white));// 7 2
    initPiece(7, 5, new Bishop(white));// 7 5
    initPiece(7, 1, new Knight(white));// 7 1
    initPiece(7, 6, new Knight(white));// 7 6

  
    for(int j{}; j < dim; ++j){
        initPiece(6 , j, new Pawn(white)); // 6, 0 <= j < 8 default
    }




    // *** BLACK PIECES ***

    initPiece(0, 4, new King(black)); // 0 4


    initPiece(0, 3, new Queen(black));// 0 3
    initPiece(0, 0, new Rook(black));// 0 0
    initPiece(0, 7, new Rook(black));// 0 7
    initPiece(0, 2, new Bishop(black));// 0 2
    initPiece(0, 5, new Bishop(black));// 0 5
    initPiece(0, 1, new Knight(black));// 0 1
    initPiece(0, 6, new Knight(black));// 0 6


    for(int j{}; j < dim; ++j){
        initPiece(1 , j, new Pawn(black));//1, 0 <= j < 8 is default
    }


}


void Board::printBoard(){
    for(int i{}; i < dim; ++i){
        for(int j{}; j < dim; ++j){
            if(getSquare(i, j) == nullptr){
                std::cout << std::setw(2) << '.';
            }
            else {
                getSquare(i,j)->display();
            }          
        }
        std::cout << '\n';
    }
}

void Board::movePiece(int x_i, int y_i, int x_f, int y_f){
    if(getSquare(x_f,y_f)!=nullptr){ // code for when piece is getting taken
        setTaken(x_f,y_f);
    }

    if(getSymbolB(x_i, y_i) == 'P'|| getSymbolB(x_i, y_i) == 'p'){
        if((x_i - 1 == x_f && y_i - 1 == y_f) || (x_i - 1 == x_f && y_i + 1 == y_f) || (x_i + 1 == x_f && y_i - 1 == y_f ||x_i + 1 == x_f && y_i + 1 == y_f)){
            takeEnPassant(x_i, y_i, x_f, y_f);
        }
    }


    if(getSymbolB(x_i, y_i) == 'K'|| getSymbolB(x_i, y_i) == 'k'){   
        castleRook(x_i, y_i, x_f, y_f);
    }
    
    setSquare(x_f, y_f, x_i, y_i);

    if(getSquare(x_i, y_i)->getisMoved() == false){// setting if a piece has been moved
        getSquare(x_f, y_f)->setMoved();
    }

    setNull(x_i, y_i);
}

void Board::castleRook(int x_i, int y_i, int x_f, int y_f){
    if(getSquare(x_i, y_i)->getCastled() == true && getCastle_onceW() == true){//code to move Rook if castling takes place.
        setCastle_onceW();
        if(y_i > y_f){
            setSquare(x_f, y_i-1, x_f, 0);
            setNull(x_f, 0);
        }else if(y_i < y_f){
            setSquare(x_f, y_i+1, x_f, 7);
            setNull(x_f, 7);
        }
    } else if(getSquare(x_i, y_i)->getCastled() == true && getCastle_onceB() == true){
        setCastle_onceB();
        if(y_i > y_f){
            setSquare(x_f, y_i-1, x_f, 0);
            setNull(x_f, 0);
        }else if(y_i < y_f){
            setSquare(x_f, y_i+1, x_f, 7);
            setNull(x_f, 7);
        }
    }

}

void Board::takeEnPassant(int x_i, int y_i, int x_f, int y_f){
    if(getSquare(x_i,y_i+1) != nullptr){
        if(getSquare(x_i,y_i+1)->getenPassant() == true){// code for en passant capture
            std::cout << "inside enPassant movePiece code" << '\n';
            if(getColourB(x_i,y_i) == 'W'){
                setTaken(x_f+1,y_f);
            }
            if(getColourB(x_i,y_i) == 'B'){
                std::cout << "inside enPassant movePiece black" << '\n';
                setTaken(x_f-1,y_f);    
            }
        }
    }
    
    if(getSquare(x_i, y_i-1) != nullptr){
        if(getSquare(x_i,y_i-1)->getenPassant() == true){// code for en passant capture
            std::cout << "inside enPassant movePiece code" << '\n';
            if(getColourB(x_i,y_i) == 'W'){
                setTaken(x_f+1,y_f);
            }
            if(getColourB(x_i,y_i) == 'B'){
                std::cout << "inside enPassant movePiece black" << '\n';
                setTaken(x_f-1,y_f);    
            }
        }
    }
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
                        initPiece( 7, found, new Queen('B'));
                        break;
                    }else if(choice == 2){
                        setTaken(7,found);
                        initPiece( 7, found, new Knight('B'));
                        break;
                    }else if(choice == 3){
                        setTaken(7,found);
                        initPiece( 7, found, new Bishop('B'));
                        break;
                    }else if(choice == 4){
                        setTaken(7,found);
                        initPiece( 7, found, new Rook('B'));
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
                        initPiece(0, found, new Queen('W'));
                        break;
                    }else if(choice == 2){
                        setTaken(0,found);
                        initPiece(0, found, new Knight('W'));
                        break;
                    }else if(choice == 3){
                        setTaken(0,found);
                        initPiece(0, found, new Bishop('W'));
                        break;
                    }else if(choice == 4){
                        setTaken(0,found);
                        initPiece(0, found, new Rook('W'));
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

bool Board::isCheck(char colour,int& attack_x, int& attack_y, int& k_x, int& k_y, bool& double_check){//player colour and coordinates of  king piece
    bool king_check{false};
    
    if(colour == 'B'){// if colour b made a move check if White is in check after that move
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
        int count{};
        for(int i{}; i < 8; ++i){
            for(int j{}; j < 8; ++j){
                if(getSquare(i, j) != nullptr){
                    if(getColourB(k_x, k_y) != getColourB(i, j)){ 
                        attack_colour = getColourB(i, j);
                        if(getSquare(i, j)->isValidMove(i, j, k_x, k_y, *this, attack_colour)){
                            attack_x = i;
                            attack_y = j;
                            king_check = true;
                            ++count;
                        }
                    }
                }
            } 
        }

        if(king_check == true){// to break out of outer loop
            std::cout << "White King is in check" << '\n';
        }
        if(count >= 2){
            double_check = true;
            std::cout << "King is double checked." << '\n';
        }

    }else if(colour == 'W'){// if white made a move check if Black king is in check
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
        int count{};
        for(int i{}; i < 8; ++i){
            for(int j{}; j < 8; ++j){
                if(getSquare(i, j) != nullptr){
                    if(getColourB(k_x, k_y) != getColourB(i, j)){ 
                        attack_colour = getColourB(i, j);
                        if(getSquare(i, j)->isValidMove(i, j, k_x, k_y, *this, attack_colour)){
                            attack_x = i;
                            attack_y = j;
                            king_check = true;
                            ++count;
                        }
                    }
                }
            }
        }
        if(king_check == true){
            std::cout << "Black King is in check" << '\n';
        }
        if(count >= 2){
            double_check = true;
            std::cout << "King is double checked." << '\n';
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
        }

        // i think this is probably the worst thing i have ever coded, lord please forgive me

        if(b1 == false && b2 == false && b3 == false && b4 == false && b5 == false && b6 == false && b7 == false && b8 == false){
            king_checkmate = true;
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
        }


        if(b1 == false && b2 == false && b3 == false && b4 == false && b5 == false && b6 == false && b7 == false && b8 == false){
            king_checkmate = true;
        }

    }


    return king_checkmate;
}

bool Board::isKingSafeB(int x_i, int y_i,int x_f, int y_f){
    bool safe{true};

    Board board_copy;// this is bad because it copies inital board NOT CURRENT
    board_copy = *this;
    board_copy.setNull(x_i,y_i);    

    char attack_colour{' '};
    for(int i{}; i < 8; ++i){
        for(int j{}; j < 8; ++j){
            if(getSquare(i, j) != nullptr){
                if(getColourB(x_i,y_i) != getColourB(i, j)){ // this assumes square is empty
                    attack_colour = getColourB(i, j);
                    if(getSquare(i,j)->getSymbol()!= 'K' && getSquare(i,j)->getSymbol()!='k'){
                        if(getSquare(i, j)->isValidMove(i, j, x_f, y_f, board_copy, attack_colour)){
                            safe = false;
                            
                        }
                        if(getSquare(x_f, y_f) != nullptr){//if square is not empty.
                                board_copy.setNull(x_f,y_f);
                            if(getSquare(i, j)->isValidMove(i, j, x_f, y_f, board_copy, attack_colour)){
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
    
    bool stale_mate{false};
    bool b1{false};
    bool b2{false};
    bool b3{false};
    bool b4{false};
    bool b5{false};
    bool b6{false};
    bool b7{false};
    bool b8{false};

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

    
    return stale_mate;
}

bool Board::blockCheckPossible(char colour,std::pair<int,int> pieces_avail[128], std::pair<int,int> pieces_block[128], std::pair<int,int> moves[128],int attack_x, int attack_y, int k_x, int k_y){
    bool possible{false};                     
    int count{};
    for(int i{}; i < 8; ++i){//code to find all pieces currently on the board
        for(int j{}; j < 8; ++j){
            if(getSquare(i, j) != nullptr && getColourB(i, j) == colour){ 
                pieces_avail[count].first = i;
                pieces_avail[count].second = j;
                ++count;
            }
        }
    }
    int count_select{};
    int count_move{};
    for(int k{}; k < 16; ++k){// need to write this better and not using 3 128 arrays(128 because 16 pieces can move in 8 possible direction, probably a brutal overestimation but yeah)
        if(k != 0){
            if(pieces_avail[k].first == 0 && pieces_avail[k].second == 0){
                break;
            }
        }
        
        if(attack_x == k_x){// i guess the cool thing is that k index correspondence between the pieces_block and moves array with this code
            if(k_y < attack_y){
                for(int j{k_y+1}; j <= attack_y; ++j){
                    if(getSquare(pieces_avail[k].first, pieces_avail[k].second)!= nullptr && isValidMoveB(pieces_avail[k].first,pieces_avail[k].second,k_x,j,colour)== true){
                        possible = true;
                        pieces_block[count_select] = pieces_avail[k];
                        moves[count_move]= std::make_pair(k_x,j);
                        std::cout << "Move piece: (" << pieces_avail[k].first << ", " << pieces_avail[k].second << ')' <<
                            " to (" << moves[count_move].first << ", " << moves[count_move].second << ") to block check. " << '\n';
                        ++count_move; 
                        ++count_select;
                    }   
                }
            }

            if(attack_y < k_y){
                for(int j{k_y-1}; j >= attack_y; --j){
                    if(getSquare(pieces_avail[k].first, pieces_avail[k].second)!= nullptr && isValidMoveB(pieces_avail[k].first,pieces_avail[k].second,k_x,j,colour)== true){
                        possible = true;
                        pieces_block[count_select] = pieces_avail[k];
                        moves[count_move]= std::make_pair(k_x,j);
                        std::cout << "Move piece: (" << pieces_avail[k].first << ", " << pieces_avail[k].second << ')' <<
                            " to (" << moves[count_move].first << ", " << moves[count_move].second << ") to lift check. " << '\n';
                        ++count_move; 
                        ++count_select;
                    }  
                }
                
            }
        }

        if(attack_y == k_y){
            if(attack_x < k_x){
                for(int i{k_x-1}; i >= attack_x; --i){
                    if(getSquare(pieces_avail[k].first, pieces_avail[k].second)!= nullptr && isValidMoveB(pieces_avail[k].first, pieces_avail[k].second, i, k_y, colour) == true){
                        possible = true;
                        pieces_block[count_select] = pieces_avail[k];
                        moves[count_move]= std::make_pair(i, k_y);
                        std::cout << "Move piece: (" << pieces_avail[k].first << ", " << pieces_avail[k].second << ')' <<
                            " to (" << moves[count_move].first << ", " << moves[count_move].second << ") to lift check. " << '\n';
                        ++count_move; 
                        ++count_select;
                    }
                }
            }

            if(k_x < attack_x){
                for(int i{k_x+1}; i <= attack_x; ++i){
                    if(getSquare(pieces_avail[k].first, pieces_avail[k].second)!=nullptr && isValidMoveB(pieces_avail[k].first, pieces_avail[k].second, i, k_y, colour) == true){
                        possible = true;
                        pieces_block[count_select] = pieces_avail[k];
                        moves[count_move]= std::make_pair(i, k_y);
                        std::cout << "Move piece: (" << pieces_avail[k].first << ", " << pieces_avail[k].second << ')' <<
                            " to (" << moves[count_move].first << ", " << moves[count_move].second << ") to lift check. " << '\n';
                        ++count_move; 
                        ++count_select;
                    }
                }
            }

        }

        
            
        int dC = k_x + k_y;
        if(attack_y == -attack_x + dC){
            if(attack_x < k_x){
                for(int i{k_x - 1}; i >= attack_x ; --i){
                    int j = -i + dC;
                    if(getSquare(pieces_avail[k].first, pieces_avail[k].second)!=nullptr && isValidMoveB(pieces_avail[k].first, pieces_avail[k].second, i, j, colour)==true){
                        possible = true;
                        pieces_block[count_select] = pieces_avail[k];
                        moves[count_move]= std::make_pair(i, j);
                        std::cout << "Move piece: (" << pieces_avail[k].first << ", " << pieces_avail[k].second << ')' <<
                            " to (" << moves[count_move].first << ", " << moves[count_move].second << ") to lift check. " << '\n';
                        ++count_move; 
                        ++count_select;
                    }
                }
            }

            if(k_x < attack_x){
                for(int i{k_x + 1}; i <= attack_x; ++i){
                    int j = -i + dC;
                    if(getSquare(pieces_avail[k].first, pieces_avail[k].second)!=nullptr && isValidMoveB(pieces_avail[k].first, pieces_avail[k].second, i, j, colour)==true){
                        possible = true;
                        pieces_block[count_select] = pieces_avail[k];
                        moves[count_move]= std::make_pair(i, j);
                        std::cout << "Move piece: (" << pieces_avail[k].first << ", " << pieces_avail[k].second << ')' <<
                            " to (" << moves[count_move].first << ", " << moves[count_move].second << ") to lift check. " << '\n';
                        ++count_move; 
                        ++count_select;
                    }

                }
            }
        
        }

        int odC = k_y - k_x;
        if(attack_y == attack_x + odC){
            if(attack_x < k_x){
                for(int i{k_x - 1}; i >= attack_x ; --i){
                    int j = i + odC;
                    if(getSquare(pieces_avail[k].first, pieces_avail[k].second)!=nullptr && isValidMoveB(pieces_avail[k].first, pieces_avail[k].second, i, j, colour)==true){
                        possible = true;
                        pieces_block[count_select] = pieces_avail[k];
                        moves[count_move]= std::make_pair(i, j);
                        std::cout << "Move piece: (" << pieces_avail[k].first << ", " << pieces_avail[k].second << ')' <<
                            " to (" << moves[count_move].first << ", " << moves[count_move].second << ") to lift check. " << '\n';
                        ++count_move; 
                        ++count_select;
                    }
                }
            }

            if(k_x < attack_x){
                for(int i{k_x + 1}; i <= attack_x; ++i){
                    int j = i + odC;
                    if(getSquare(pieces_avail[k].first, pieces_avail[k].second)!=nullptr && isValidMoveB(pieces_avail[k].first, pieces_avail[k].second, i, j, colour)==true){
                        possible = true;
                        pieces_block[count_select] = pieces_avail[k];
                        moves[count_move]= std::make_pair(i, j);
                        std::cout << "Move piece: (" << pieces_avail[k].first << ", " << pieces_avail[k].second << ')' <<
                            " to (" << moves[count_move].first << ", " << moves[count_move].second << ") to lift check. " << '\n';
                        ++count_move; 
                        ++count_select;
                    }

                }
            }

        }
    }
    
    return possible;
}


