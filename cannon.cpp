#include "cannon.h"
#include "player.h"
#include <iostream>
#include "game.h"


CannonCard::CannonCard(int value) : Card(Cannon, value) {
}

std::string CannonCard::str() const{
    return "Cannon(" + std::to_string(value()) + ")";
}

void CannonCard:: play(Game &game, Player &player) {
    // Discard the top card (i.e. the highest value) of any suit from 2,3,4,5,6,7 the other player’s Bank to the Discard Pile.
    Player& otherPlayer = game.getOtherPlayer();

    Card* remove = otherPlayer.removeHighestValueCard();

    if (remove == nullptr) {
        std::cout << "There is no cards to discard.\n";
    } else {
        game.getDiscardPile().push_back(remove);
        std::cout << "Discarded " << remove->str() << ".\n";
    }
}