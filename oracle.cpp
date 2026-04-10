#include "oracle.h"
#include "game.h"
#include <iostream>

OracleCard::OracleCard(int value) : Card(Oracle, value) {
}

// returns oracle's string and value
std::string OracleCard::str() const {
    return "Oracle(" + std::to_string(value()) + ")";
}

// oracle's ability which is to let the player see the next card in the deck ( allowing them to select if they want to draw or not)
void OracleCard:: play(Game &game, Player &player) {
    // peek function used from game.cpp
    Card* nextCard = game.peek();

    // checks if the deck is empty 
    if (nextCard == nullptr) {
        std::cout << "Deck is empty\n";
    } else {
        //prints next card
        std:: cout << nextCard->str() << " is the next card in the deck.\n";
    }
}