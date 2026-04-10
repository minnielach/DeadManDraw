#include "oracle.h"
#include "game.h"
#include <iostream>

OracleCard::OracleCard(int value) : Card(Oracle, value) {
}

std::string OracleCard::str() const {
    return "Oracle(" + std::to_string(value()) + ")";
}

void OracleCard:: play(Game &game, Player &player) {
    Card* nextCard = game.peek();
    
    if (nextCard == nullptr) {
        std::cout << "Deck is empty\n";
    } else {
        std:: cout << nextCard->str() << " is the next card in the deck.\n";
    }
}