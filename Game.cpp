#include "Game.h"

Game::Game(std::string name1, std::string name2){
    
    player1.setName(name1); 
    player1.setColor('W');

    player2.setName(name2);
    player2.setColor('B');

    currentPlayer = &player1;

}

void Game::switchTurn(){
    if(currentPlayer == &player1){
        currentPlayer = &player2;
    }else{
        currentPlayer = &player1;
    }
}

void Game::start(){
    bool gameEnd = isGameOver();
    bool king_check = false;
    int king_x_check{};
    int king_y_check{};
    std::pair<int,int> pieceXY;
    std::pair<int,int> posXY;
    bool final_piece{false};
    char ans{'s'};

    board.printBoard();
    while(gameEnd != true){
        if(currentPlayer){      
            if(king_check == false){
                while(final_piece == false){
                    std::cout << "Choose piece " << currentPlayer->getName() << ":" << '\n';
                    pieceXY = board.inputCoords();
                    std::cout << "Change piece? y/n" << '\n';
                    std::cin >> ans;
                    if(ans == 'n'){
                        final_piece = true;
                    } 
                }
                
                
            }else{
                std::cout << "King is selected : " << currentPlayer->getName() << '\n';
                pieceXY.first =  king_x_check;
                pieceXY.second = king_y_check;
                std::cout << "( " <<  king_x_check << ", " << king_y_check << ")" <<'\n';
            }
            
            if(board.getSquare(pieceXY.first,pieceXY.second)!= nullptr && board.getColourB(pieceXY.first,pieceXY.second) == currentPlayer->getColor()){// btw if you pick nullptr it breaks so maybe
                std::cout << "Valid piece selected." << '\n';
            }else{ 
                bool valid_piece = false;
                while(valid_piece == false){
                    std::cout << "Invalid piece selected, select again." << '\n';
                    pieceXY = board.inputCoords();
                    valid_piece = (board.getSquare(pieceXY.first,pieceXY.second)!= nullptr) && (board.getColourB(pieceXY.first,pieceXY.second) == currentPlayer->getColor());
                }
                std::cout << "Valid piece selected." << '\n';
            }
            std::cout << "Make move: " << '\n';
            posXY = board.inputCoords();
            bool valid_move = board.getSquare(pieceXY.first,pieceXY.second)->isValidMove(pieceXY.first,pieceXY.second,posXY.first,posXY.second,board,currentPlayer->getColor());
                if(valid_move == true){
                    board.movePiece(pieceXY.first,pieceXY.second, posXY.first, posXY.second);
                    std::cout << "before checking if a king is in check" << '\n';
                    king_check = board.isCheck(currentPlayer->getColor(), king_x_check, king_y_check);
                    board.pawnPromotion(currentPlayer->getColor());
                    board.printBoard();
                }else{
                    bool valid_move = false;
                    while(valid_move == false){
                        std::cout << "Invalid move, select again.  " << '\n';
                        posXY = board.inputCoords();
                        valid_move = board.getSquare(pieceXY.first,pieceXY.second)->isValidMove(pieceXY.first,pieceXY.second,posXY.first,posXY.second,board,currentPlayer->getColor());
                    }
                    std::cout << "Valid move made." << '\n';
                    board.movePiece(pieceXY.first,pieceXY.second, posXY.first, posXY.second);
                    king_check = board.isCheck(currentPlayer->getColor(), king_x_check, king_y_check);
                    board.pawnPromotion(currentPlayer->getColor());
                    board.printBoard();
                }
        }

        
        switchTurn();
        pieceXY.first = 0;
        pieceXY.second = 0;
        posXY.first = 0;
        posXY.second = 0;
        final_piece = false;


    }
    board.printBoard();
}

bool Game::isGameOver() const{
    return false;
}