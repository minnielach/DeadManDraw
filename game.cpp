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
    std::cout << GAME_TITLE << "\n";
    std::cout << "Starting Dead Man's Draw++\n";
    while (!deck.empty() && countTurn <= 20) {
        currentTurn();
    }

    std::cout << "--- Game Over ---\n";
    std::cout << player1.getName() << "'s Bank: \n";
    player1.printBank();
    std:: cout << "| " << player1.getName() << "'s score: " << player1.getScore()<< "\n";
    std::cout << player2.getName() << "'s Bank: \n";
    player2.printBank();
    std:: cout << "| " << player2.getName() << "'s score: " << player2.getScore() << "\n";
    if (player1.getScore() > player2.getScore()) {
        std:: cout << player1.getName() << " wins!";
    } else {
        std:: cout << player2.getName() << " wins!";
    }

}

void Game::currentTurn() {
    std:: cout << "--- Round " << round << ", Turn " << countTurn << " ---\n";

    Player& player = getCurrentPlayer();

    std:: cout << player.getName() << "'s turn\n";

    player.printBank();

    std:: cout << "| " << player.getName() << "'s score: " << player.getScore() << "\n";

    bool play = true;

    while (play) {
        
        Card* draw = drawCard();

        if (draw == nullptr) {
            std::cout << "No more cards in deck.\n";
            return;
        }

        std::cout << player.getName() << " draws " << draw->str() << "\n";

        bool bust = player.playCard(draw, *this);

        if (bust) {
            std:: cout << "BUST! " << player.getName() << " loses all cards in play area!\n";

            CardCollection& discardCards = getDiscardPile();
            for (Card* c : player.getPlayArea()) {
                discardCards.push_back(c);
            }

            player.getPlayArea().clear();

            play = false;
        } else {
            std:: cout << "\n\nDraw again? (y/n)\n"; 
            char answer;
            std::cin >> answer;

            if (answer != 'y') {
                player.manageBank();
            play=false;
            }
        }
    }

    switchTurns();
    countTurn++;

    if (countTurn % 2 == 1) {
        round ++;
    }

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