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
    bool block_possible = false;
    int king_x_check{};
    int king_y_check{};
    std::pair<int,int> pieceXY;
    std::pair<int,int> posXY;
    bool list_piece{false};
    bool valid_piece{false};
    char choice{'y'};
    bool stale_mate = false;
    bool not_nullptr = false;
    bool current_colour = false;
    bool double_check = false;
    int attack_x;
    int attack_y;
    std::pair<int,int> piece_list[128];
    std::pair<int,int> chosen_pieces[128];
    std::pair<int,int> moves[128];

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
                if(double_check == true){
                    std::cout << "King has been double checked, move to safety." << '\n';
                    pieceXY = std::make_pair(king_x_check, king_y_check);
                }else{
                    while(valid_piece == false){
                        std::cout << "Choose piece to lift check or move king : " << currentPlayer->getName() << '\n';
                        block_possible = board.blockCheckPossible(currentPlayer->getColour(),piece_list,chosen_pieces, moves ,attack_x, attack_y, king_x_check, king_y_check);
                        pieceXY = board.inputCoords();

                        not_nullptr = (board.getSquare(pieceXY.first,pieceXY.second)!= nullptr);
                        if(not_nullptr){//avoids segfaulting
                            current_colour = (board.getColourB(pieceXY.first,pieceXY.second) == currentPlayer->getColour());
                        }

                        for(int i{}; i < 128; ++i){
                            if( pieceXY == chosen_pieces[i]){
                                list_piece = true;
                                break;
                            }
                        }
                        valid_piece = not_nullptr && current_colour && list_piece;
                        if(valid_piece == true){
                            std::cout << "Valid Piece selected" << '\n';
                            std::cout << "Change piece? y/n" << '\n';
                            std::cin >> choice;
                            if(choice == 'y'){
                                valid_piece = false;
                            }else if( choice == 'n'){
                                break;
                            }
                        }else{
                            std::cout << "Invalid piece selected " << '\n';
                        }
                    }
                }
            }
            //making move logic
            if(king_check == false){
                std::cout << "Make move: " << '\n';
                posXY = board.inputCoords();//need to add an if else statement here as well for if king is in check or not and forcing the player to choose moves from that set which it will always be correct or choosing the king to move out of hte fucking way 
                valid_move = board.getSquare(pieceXY.first,pieceXY.second)->isValidMove(pieceXY.first,pieceXY.second,posXY.first,posXY.second,board,currentPlayer->getColour());
                if(valid_move == true){
                    board.movePiece(pieceXY.first,pieceXY.second, posXY.first, posXY.second);
                    king_check = board.isCheck(currentPlayer->getColour(), attack_x, attack_y, king_x_check, king_y_check, double_check);
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
                    king_check = board.isCheck(currentPlayer->getColour(),attack_x, attack_y, king_x_check, king_y_check, double_check);
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
            }else{
                std::cout << "Make move: " << '\n';
                if(pieceXY.first == king_x_check && pieceXY.second == king_y_check){
                    posXY = board.inputCoords();
                    valid_move = board.getSquare(pieceXY.first,pieceXY.second)->isValidMove(pieceXY.first,pieceXY.second,posXY.first,posXY.second,board,currentPlayer->getColour());
                }else{
                    posXY = board.inputCoords();
                    for(int i{}; i < 128; ++i){
                        if(posXY == moves[i]){
                            valid_move = true;
                            break;
                        }
                    }
                }
                if(valid_move == true){
                    board.movePiece(pieceXY.first,pieceXY.second, posXY.first, posXY.second);
                    king_check = board.isCheck(currentPlayer->getColour(), attack_x, attack_y, king_x_check, king_y_check, double_check);
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
                        if(pieceXY.first == king_x_check && pieceXY.second == king_y_check){
                            posXY = board.inputCoords();
                            valid_move = board.getSquare(pieceXY.first,pieceXY.second)->isValidMove(pieceXY.first,pieceXY.second,posXY.first,posXY.second,board,currentPlayer->getColour());
                        }else{
                            posXY = board.inputCoords();
                            for(int i{}; i < 128; ++i){
                                if(posXY == moves[i]){
                                    valid_move = true;
                                    break;
                                }
                            }
                        }
                    }
                    std::cout << "Valid move made." << '\n';
                    board.movePiece(pieceXY.first,pieceXY.second, posXY.first, posXY.second);
                    king_check = board.isCheck(currentPlayer->getColour(),attack_x, attack_y, king_x_check, king_y_check, double_check);
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
        }
        switchTurn();
        pieceXY = {};
        posXY = {};
        for(int i{}; i < 128; ++i){
            piece_list[i] = {};
            chosen_pieces[i] = {};
            moves[i] = {};
        }
        valid_piece = false;
    }
    board.printBoard();
}
