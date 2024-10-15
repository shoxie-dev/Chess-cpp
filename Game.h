/*
#ifndef _GAME_
#define _GAME_
#include "Player.h"
#include "Board.h"
class Game{
    private:
        Player player1,player2;
        Board board;
        Player* currentPlayer;
    public:

        Game(std::string name1, std::string name2);
        ~Game();
        void switchTurn();
        void start();

};

#endif
*/