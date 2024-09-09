#include "Game.h"

Game::Game(std::string name1, std::string name2){
    
    player1.setName(name1); 
    player1.setColour('W');

    player2.setName(name2);
    player2.setColour('B');

    currentPlayer = &player1;

}

Game::~Game(){ // deletes remaining pieces on board that is dynamically allocated 
    std::cout << "Game destructor called " << '\n';
    for(int i{}; i < 8; ++i){
        for(int j{}; j < 8; ++j){
            if(board.getSquare(i,j) != nullptr){
                delete board.getSquare(i, j);
            }
        }
    }
}

void Game::switchTurn(){
    if(currentPlayer == &player1){
        currentPlayer = &player2;
    }else{
        currentPlayer = &player1;
    }
}

void Game::start(){
    bool king_checkmate = false;
    bool valid_move = false;
    bool king_check = false;
    int king_x_check{};
    int king_y_check{};
    std::pair<int,int> pieceXY;
    std::pair<int,int> posXY;
    bool valid_piece{false};
    char choice{'y'};
    bool stale_mate = false;
    bool not_nullptr = false;
    bool current_colour = false;

    while(king_checkmate != true && stale_mate != true){
        board.printBoard();
        if(currentPlayer){      
            if(king_check == false){
                while(valid_piece == false){
                    std::cout << "Choose piece " << currentPlayer->getName() << ":" << '\n';
                    pieceXY = board.inputCoords();
                    not_nullptr = (board.getSquare(pieceXY.first,pieceXY.second)!= nullptr);
                    if(not_nullptr){//avoids segfaulting
                        current_colour = (board.getColourB(pieceXY.first,pieceXY.second) == currentPlayer->getColour());
                    }
                    valid_piece = not_nullptr && current_colour;
                    if(valid_piece == true){
                        std::cout << "Valid Piece selected" << '\n';
                        std::cout << "Change piece? y/n" << '\n';
                        std::cin >> choice;
                        if(choice == 'y'){
                            valid_piece = false;
                        }else if(choice == 'n'){
                            break;
                        }
                    }else{
                        std::cout << "Invalid piece selected" << '\n';
                    } 
                } 
            
            }else{
                std::cout << "Choose piece to lift check or move king : " << currentPlayer->getName() << '\n';
                //pieceXY.first =  king_x_check;
                //pieceXY.second = king_y_check;
                pieceXY = board.inputCoords();
                std::cout << "( " <<  king_x_check << ", " << king_y_check << ")" <<'\n';
            }
            
            std::cout << "Make move: " << '\n';
            posXY = board.inputCoords();
                valid_move = board.getSquare(pieceXY.first,pieceXY.second)->isValidMove(pieceXY.first,pieceXY.second,posXY.first,posXY.second,board,currentPlayer->getColour());
                std::cout << std::boolalpha << valid_move << '\n';
                if(valid_move == true){
                    board.movePiece(pieceXY.first,pieceXY.second, posXY.first, posXY.second);
                    king_check = board.isCheck(currentPlayer->getColour(), king_x_check, king_y_check);
                    if(king_check == false){
                        stale_mate = board.isStalemate(currentPlayer->getColour(),king_x_check,king_y_check);
                        if(stale_mate == true){
                            break;
                        }
                    }
                    king_checkmate = board.isCheckmate(currentPlayer->getColour());
                    if(king_checkmate == true){
                        std::cout << "Player " << currentPlayer->getColour() << " wins" <<'\n';
                        break;
                    }

                    board.pawnPromotion(currentPlayer->getColour());
                }else{
                    valid_move = false;
                    while(valid_move == false){
                        std::cout << "Invalid move, select again.  " << '\n';
                        posXY = board.inputCoords();
                        valid_move = board.getSquare(pieceXY.first,pieceXY.second)->isValidMove(pieceXY.first,pieceXY.second,posXY.first,posXY.second,board,currentPlayer->getColour());
                    }
                    std::cout << "Valid move made." << '\n';
                    board.movePiece(pieceXY.first,pieceXY.second, posXY.first, posXY.second);
                    king_check = board.isCheck(currentPlayer->getColour(), king_x_check, king_y_check);
                    if(king_check == false){
                        stale_mate = board.isStalemate(currentPlayer->getColour(),king_x_check,king_y_check);
                        if(stale_mate == true){
                            break;
                        }
                    }
                    king_checkmate = board.isCheckmate(currentPlayer->getColour());
                    if(king_checkmate == true){
                        std::cout << "Player " << currentPlayer->getColour() << " wins" <<'\n';
                        break;
                    }
                    board.pawnPromotion(currentPlayer->getColour());
                }
        }
        switchTurn();
        pieceXY.first = 0;
        pieceXY.second = 0;
        posXY.first = 0;
        posXY.second = 0;
        valid_piece = false;


    }
    board.printBoard();
}
