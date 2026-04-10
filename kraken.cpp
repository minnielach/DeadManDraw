#include "kraken.h"
#include "game.h"
#include <iostream>

KrakenCard::KrakenCard(int value) : Card(Kraken, value) {
}

// returns kraken's string and value
std::string KrakenCard::str() const{
    return "Kraken(" + std::to_string(value()) + ")";
}

// kraken's ability which allows the player to draw 3 cards from the deck and they must be played
void KrakenCard:: play(Game &game, Player &player) {
    std:: cout << "Draw 3 cards from the deck and play each.\n";

    // player draws 3 cards from the deck
    for (int i=0; i < 3; i++) {
        Card* krakenCards = game.drawCard();

        if (krakenCards == nullptr) {
            std:: cout << "There are no more cards in the deck.\n";
            return;
        }

        std::cout << player.getName() << " draws a " << krakenCards->str() << "\n";

        // checks if player has busted once card is played
        bool bust = player.playCard(krakenCards, game);

        if(bust) {
            std::cout << "BUST! " << player.getName() << " loses all cards in play area!\n";
            return;
        }
    }
}