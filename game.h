#pragma once 
#include "player.h"
#include "card.h"

class Game {
    private:
    Player player1;
    Player player2;

    CardCollection deck;
    CardCollection discardPile;

    bool player1Turn;

    int countTurn;
    int round;

    public:
    Game();

    void createDeck();
    void shuffleDeck();

    void playGame();
    void currentTurn();
    void switchTurns();

    Player& getCurrentPlayer();
    Player& getOtherPlayer();

    Player& getPlayer1();
    Player& getPlayer2();

    CardCollection& getDiscardPile();

    Card* peek();
};