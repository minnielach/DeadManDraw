#include "game.h"
#include "player.h"
#include "card.h"
#include "cannon.h"
#include "chest.h"
#include "key.h"
#include "hook.h"
#include "sword.h"
#include "kraken.h"
#include "mermaid.h"
#include "oracle.h"
#include "map.h"
#include <iostream>
#include "game_title.h"
#include <algorithm>
#include <random>

Game::Game() {
    player1Turn = true;
    countTurn = 1;
    round = 1;

    createDeck();
    shuffleDeck();

}

void Game::createDeck() {
    for (int i = 2; i < 8; i++) {
        deck.push_back(new CannonCard(i));
    }

    for (int i = 2; i < 8; i++) {
        deck.push_back(new ChestCard(i));
    }

    for (int i = 2; i < 8; i++) {
        deck.push_back(new KeyCard(i));
    }

    for (int i = 2; i < 8; i++) {
        deck.push_back(new SwordCard(i));
    }

    for (int i = 2; i < 8; i++) {
        deck.push_back(new HookCard(i));
    }

    for (int i = 2; i < 8; i++) {
        deck.push_back(new OracleCard(i));
    }

    for (int i = 2; i < 8; i++) {
        deck.push_back(new MapCard(i));
    }

    for (int i = 2; i < 8; i++) {
        deck.push_back(new KrakenCard(i));
    }

    for (int i = 4; i < 10; i++) {
        deck.push_back(new MermaidCard(i));
    }
}

void Game:: shuffleDeck() {

    std::random_device rd; 
    std::mt19937 g(rd()); 

    std::shuffle(deck.begin(), deck.end(), g);

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

Card* Game:: peek() {
    if (deck.empty()) {
        return nullptr;
    }

    return deck.back();
}

Card* Game:: drawCard() {
    if (deck.empty()) {
        return nullptr;
    } else {
        Card* drawnCard = deck.back();
        deck.pop_back();
        return drawnCard;
    }
}