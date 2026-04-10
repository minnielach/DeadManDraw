#include "game.h"
#include <iostream>

Game::Game() {
    player1Turn = true;
    countTurn = 1;
    round = 1;

    createDeck();
    shuffleDeck();

}

void Game::createDeck() {
    // add the suits to deck once they are made
}

void Game::shuffleDeck() {
    // use shuffle function once create deck is done
}

void Game::playGame() {
    while (!deck.empty() && countTurn <= 20) {
        currentTurn();
    }

    std::cout << "--- Game Over ---\n";
}

void Game::currentTurn() {
    // print round and turn
    // print player's name turn
    // print player's bank 
    // player draws card + play ability
    // add to play area
    // check if player has bust
    // ask to play again if no switch turn (repeat player 2)
}

void Game::switchTurns() {
    if (player1Turn) {
        player1Turn = false;
    } else {
        player1Turn = true;
    }
}

Player& Game:: getPlayer1() {
    return player1;
}

Player& Game:: getPlayer2() {
    return player2;
}

CardCollection& Game:: getDiscardPile() {
    return discardPile;
}

Player& Game:: getCurrentPlayer() {
    if (player1Turn) {
        return player1;
    } else {
        return player2;
    }
}

Player& Game::getOtherPlayer() {
    if (player1Turn) {
        return player2;
    } else {
        return player1;
    }
}

Card* :: Game:: peek() {
    if (deck.empty()) {
        return nullptr;
    }

    return deck.back();
}

Card* :: Game:: drawCard() {
    if (deck.empty()) {
        return nullptr;
    } else {
        Card* drawnCard = deck.back();
        deck.pop_back();
        return drawnCard;
    }
}