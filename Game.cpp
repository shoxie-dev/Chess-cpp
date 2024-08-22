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
    
    board.printBoard();
    while(gameEnd != true){
        if(currentPlayer){
            std::cout << "Choose piece " << currentPlayer->getName() << ":" << std::endl;
            std::pair<int,int> pieceXY = board.inputCoords();
            if(board.getColourB(pieceXY.first,pieceXY.second) == currentPlayer->getColor()){// btw if you pick nullptr it breaks so maybe
                std::cout << "Valid piece selected." << std::endl;
            }else{ 
                bool valid_piece = false;
                while(valid_piece == false){
                    std::cout << "Invalid piece selected, select again." << std::endl;
                    pieceXY = board.inputCoords();
                    valid_piece = (board.getColourB(pieceXY.first,pieceXY.second) == currentPlayer->getColor());
                }
                std::cout << "Valid piece selected." << std::endl;
            }
            std::cout << "Make move: " << std::endl;
            std::pair<int,int> posXY = board.inputCoords();
            bool valid_move = board.getPiece(pieceXY.first,pieceXY.second)->isValidMove(pieceXY.first,pieceXY.second,posXY.first,posXY.second,board,currentPlayer->getColor());
                if(valid_move == true){
                    board.movePiece(pieceXY.first,pieceXY.second, posXY.first, posXY.second);
                    board.printBoard();
                }else{
                    bool valid_move = false;
                    while(valid_move == false){
                        std::cout << "Invalid move, select again.  " << std::endl;
                        posXY = board.inputCoords();
                        valid_move = board.getPiece(pieceXY.first,pieceXY.second)->isValidMove(pieceXY.first,pieceXY.second,posXY.first,posXY.second,board,currentPlayer->getColor());
                    }
                    std::cout << "Valid move made." << std::endl;
                    board.movePiece(pieceXY.first,pieceXY.second, posXY.first, posXY.second);
                    board.printBoard();
                }
        }

        
        switchTurn();

    }
    board.printBoard();
}

bool Game::isGameOver() const{
    return false;
}