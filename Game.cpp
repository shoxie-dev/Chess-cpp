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
            std::cout << "Choose piece " << currentPlayer->getName() << ":" << '\n';
            std::pair<int,int> pieceXY = board.inputCoords();
            if(board.getColourB(pieceXY.first,pieceXY.second) == currentPlayer->getColor()){// btw if you pick nullptr it breaks so maybe
                std::cout << "Valid piece selected." << '\n';
            }else{ 
                bool valid_piece = false;
                while(valid_piece == false){
                    std::cout << "Invalid piece selected, select again." << '\n';
                    pieceXY = board.inputCoords();
                    valid_piece = (board.getColourB(pieceXY.first,pieceXY.second) == currentPlayer->getColor());
                }
                std::cout << "Valid piece selected." << '\n';
            }
            std::cout << "Make move: " << '\n';
            std::pair<int,int> posXY = board.inputCoords();
            bool valid_move = board.getSquare(pieceXY.first,pieceXY.second)->isValidMove(pieceXY.first,pieceXY.second,posXY.first,posXY.second,board,currentPlayer->getColor());
                if(valid_move == true){
                    board.movePiece(pieceXY.first,pieceXY.second, posXY.first, posXY.second);
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