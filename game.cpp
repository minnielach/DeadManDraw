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

// creates all cards and adds them to the deck
void Game::createDeck() {

    // for loop for each card type and is added to the deck
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

// randomly shuffles the cards in the deck using random number generator
void Game:: shuffleDeck() {

    std::random_device rd; 
    std::mt19937 g(rd()); 

    std::shuffle(deck.begin(), deck.end(), g);

}

// starts the game
void Game::playGame() {
    std::cout << GAME_TITLE << "\n";
    std::cout << "Starting Dead Man's Draw++\n";
    // continues to plau until 20 turns have passed or deck is empty
    while (!deck.empty() && countTurn <= 20) {
        currentTurn();
    }

    // end of game 
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

// ensures that a player's turn follows the proper format and rules.
void Game::currentTurn() {

    //prints the beginning for each round
    std:: cout << "--- Round " << round << ", Turn " << countTurn << " ---\n";

    Player& player = getCurrentPlayer();

    std:: cout << player.getName() << "'s turn\n";

    player.printBank();

    std:: cout << "| " << player.getName() << "'s score: " << player.getScore() << "\n";

    // boolean added so that a player's turn will end when busted or does not want to draw
    bool play = true;

    while (play) {
        
        Card* draw = drawCard();

        if (draw == nullptr) {
            std::cout << "No more cards in deck.\n";
            return;
        }

        std::cout << player.getName() << " draws " << draw->str() << "\n";

        bool bust = player.playCard(draw, *this);

        // checks if player has busted once a card is drawn
        if (bust) {
            std:: cout << "BUST! " << player.getName() << " loses all cards in play area!\n";

            // discards cards into discard pile if busted
            CardCollection& discardCards = getDiscardPile();
            for (Card* c : player.getPlayArea()) {
                discardCards.push_back(c);
            }

            // clears their play area
            player.getPlayArea().clear();

            play = false;
        } else {
            // asks if player wants to draw again
            std:: cout << "\n\nDraw again? (y/n)\n"; 
            char answer;
            std::cin >> answer;

            if (answer != 'y') {
                player.manageBank();
            play=false;
            }
        }
    }

    // switches turn and turn number goes up by one
    switchTurns();
    countTurn++;

    // once player 1 and player 2 has played then round goes up by one
    if (countTurn % 2 == 1) {
        round ++;
    }

}

// switches the player's turn 
void Game::switchTurns() {
    if (player1Turn) {
        player1Turn = false;
    } else {
        player1Turn = true;
    }
}

// returns player 1 information
Player& Game:: getPlayer1() {
    return player1;
}

// returns 2 information
Player& Game:: getPlayer2() {
    return player2;
}

// returns the discard pile
CardCollection& Game:: getDiscardPile() {
    return discardPile;
}

// return the player currently playing
Player& Game:: getCurrentPlayer() {
    if (player1Turn) {
        return player1;
    } else {
        return player2;
    }
}

// return the player that is not currently playing
Player& Game::getOtherPlayer() {
    if (player1Turn) {
        return player2;
    } else {
        return player1;
    }
}

// looks at the first card in the deck without touching it
Card* Game:: peek() {
    if (deck.empty()) {
        return nullptr;
    }

    return deck.back();
}

// allows player to draw the first card in the deck
Card* Game:: drawCard() {
    if (deck.empty()) {
        return nullptr;
    } else {
        Card* drawnCard = deck.back();
        deck.pop_back();
        return drawnCard;
    }
}