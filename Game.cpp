#include "Game.h"

Game::Game(std::string name1, std::string name2){
    player1.setName(name1); 
    player1.setColor('W');

    player2.setName(name2);
    player2.setColor('B');

    currentPlayer = &player1;

}

void Game::switchTurn(){
    if(currentPlayer = &player1){
        currentPlayer = &player2;
    }else{
        currentPlayer = &player1;
    }
}

void Game::start(){

    bool gameEnd = isGameOver();

    board.printBoard();
    
    std::cout << "Choose piece : " << std::endl;
    std::pair<int,int> pieceXY = board.choosePiece();
    std::cout << "Choose position: " << std::endl;
    std::pair<int,int> posXY = board.newPosition();
    board.movePiece(pieceXY.first, pieceXY.second, posXY.first, posXY.second);

    board.printBoard();
    //if piece symbol is upper or lower
    //if(currentPlayer == player1)
    //  get piece_pos
    //  if(isupper(squares[i][j]->getsymbol()))
    //  else
    //  get piece_pos again until right so its a while loop
        


}

bool Game::isGameOver() const{
    return false;
}