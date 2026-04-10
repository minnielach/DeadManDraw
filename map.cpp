#include "map.h"
#include "game.h"
#include <iostream>


MapCard::MapCard(int value) : Card(Map, value) {
}

std::string MapCard::str() const{
    return "Map(" + std::to_string(value()) + ")";
}

void MapCard:: play(Game &game, Player &player) {

    CardCollection& discardPile = game.getDiscardPile();

    if (discardPile.empty()) {
        std::cout << "No cards are available in the discard pile.\n";
    } else {

        std::cout << "Draw 3 Cards from the discard and pick one to add to the play area:\n";
        
        std::vector<Card*> discardCards;

        int count;

        if (discardPile.size() < 3) {
            count = discardPile.size();
        } else {
            count = 3;
        }

        for (int i = 0; i < count; i ++) {
            discardCards.push_back(discardPile.back());
            discardPile.pop_back();
        }

        std::cout << "Which card do you pick?";

        for (int i=0; i < discardCards.size(); i++) {
            std::cout << "(" << i + 1 << ")" << discardCards[i]->str() << "\n";
        }

        int answer;
        std::cin >> answer;

        answer = answer - 1;

        if (answer < 0 || answer >= discardCards.size()) {
            std::cout << "Invalid choice\n";
            return;
        }

        for (int i=0; i < discardCards.size(); i ++) {
            if (i != answer) {
                discardPile.push_back(discardCards[i]);
            }
        }

        Card* choosen = discardCards[answer];

        player.playCard(choosen, game);

    }
}