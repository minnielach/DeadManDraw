#include "cannon.h"
#include "player.h"
#include <iostream>
#include "game.h"


CannonCard::CannonCard(int value) : Card(Cannon, value) {
}

// returns cannon's string and value 
std::string CannonCard::str() const{
    return "Cannon(" + std::to_string(value()) + ")";
}

// cannon's ability which discards the top card of any suit in the other player's bank 
void CannonCard:: play(Game &game, Player &player) {
    Player& otherPlayer = game.getOtherPlayer();

    // finds the highest value card
    Card* remove = otherPlayer.removeHighestValueCard();

    // removes the card into discard pile, or if lets player know that they do not have a card to discard
    if (remove == nullptr) {
        std::cout << "There is no cards to discard.\n";
    } else {
        game.getDiscardPile().push_back(remove);
        std::cout << "Discarded " << remove->str() << ".\n";
    }
}