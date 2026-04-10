#include "map.h"
#include "game.h"
#include <iostream>


MapCard::MapCard(int value) : Card(Map, value) {
}

// returns map's string and value
std::string MapCard::str() const{
    return "Map(" + std::to_string(value()) + ")";
}

// map's ability which allows player to draw 3 cards from the discard pile and selects one to play
void MapCard:: play(Game &game, Player &player) {

    CardCollection& discardPile = game.getDiscardPile();

    // checks if discard pile is empty
    if (discardPile.empty()) {
        std::cout << "No cards are available in the discard pile.\n";
    } else {

        std::cout << "Draw 3 Cards from the discard and pick one to add to the play area:\n";
        
        // creates a vector to store the discard cards as there may not be 3
        std::vector<Card*> discardCards;

        int count;

        // checks if there is 3 or less
        if (discardPile.size() < 3) {
            count = discardPile.size();
        } else {
            count = 3;
        }

        // for loop which takes the discard cards into the temporary vector 
        for (int i = 0; i < count; i ++) {
            discardCards.push_back(discardPile.back());
            discardPile.pop_back();
        }

        std::cout << "Which card do you pick?";

        // prints the options for the player
        for (int i=0; i < discardCards.size(); i++) {
            std::cout << "(" << i + 1 << ") " << discardCards[i]->str() << "\n";
        }

        int answer;
        std::cin >> answer;

        // answer - 1 ensures that answer matches the option's index
        answer = answer - 1;

        if (answer < 0 || answer >= discardCards.size()) {
            std::cout << "Invalid choice\n";
            return;
        }

        // returns the not choosen cards back to the discard pile
        for (int i=0; i < discardCards.size(); i ++) {
            if (i != answer) {
                discardPile.push_back(discardCards[i]);
            }
        }

        Card* choosen = discardCards[answer];

        // plays choosen card
        player.playCard(choosen, game);

    }
}