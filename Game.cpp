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
        if(currentPlayer == &player1){
            std::cout << "Choose piece player 1: " << std::endl;
            std::pair<int,int> pieceXY = board.choosePiece();
            if(board.getColourB(pieceXY.first,pieceXY.second) == 'W'){//isValidPiece('W'), btw if you pick nullptr it breaks so maybe
                std::pair<int,int> posXY = board.newPosition();
                bool valid_move = board.getPiece(pieceXY.first,pieceXY.second)->isValidMove(pieceXY.first,pieceXY.second,posXY.first,posXY.second,board,'W');
                if(valid_move == true){
                    board.movePiece(pieceXY.first,pieceXY.second, posXY.first, posXY.second);
                    board.printBoard();
                }
                std::cout << "valid piece selected " << std::endl;
            }else{
                std::cout << "invalid piece selected " << std::endl;
            }
        }

        if(currentPlayer == &player2){
            std::cout << "Choose piece player 2: " << std::endl;
            std::pair<int,int> pieceXY = board.choosePiece();
            if(board.getColourB(pieceXY.first,pieceXY.second) == 'B'){//isValidPiece('W'), btw if you pick nullptr it breaks so maybe
                std::pair<int,int> posXY = board.newPosition();
                bool valid_move = board.getPiece(pieceXY.first,pieceXY.second)->isValidMove(pieceXY.first,pieceXY.second,posXY.first,posXY.second,board,'B');
                if(valid_move == true){
                    board.movePiece(pieceXY.first,pieceXY.second, posXY.first, posXY.second);
                    board.printBoard();
                }
                std::cout << "valid piece selected " << std::endl;
            }else{
                std::cout << "invalid piece selected " << std::endl;
            }
        }
        
        switchTurn();

    }
    board.printBoard();
    //if piece symbol is upper or lower
    //if(currentPlayer == player1)
    //  get piece_pos
    //  if(isupper(squares[i][j]->getsymbol()))
    //      BOOL isvalidmove
    //      if(isvalid_move)
    //          make move
    //      else
    //       get new move then make it
    //  else
    //      get piece_pos again until right so its a while loop
        


}

bool Game::isGameOver() const{
    return false;
}