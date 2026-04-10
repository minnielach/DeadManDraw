#include "sword.h"
#include "player.h"
#include "game.h"
#include <iostream>

SwordCard::SwordCard(int value) : Card(Sword, value) {
}

// returns sword's string and value
std::string SwordCard::str() const {
    return "Sword(" + std::to_string(value()) + ")";
}

// sword's ability which is to steal the top card of any suit from the other player's bank
void SwordCard:: play(Game &game, Player &player) {

    // get the other player and their highest values 
    Player& otherPlayer = game.getOtherPlayer();
    std::vector<Card*> swordOptions = otherPlayer.getHighestValueSuit();

    // checks if empty
    if (swordOptions.empty()) {
        std::cout << "No cards in other player's bank. Play continues.\n";
    } else {
        std::cout<< "Steal the top card of any suit from the other player's bank into your play area.\n";
        // prints the options to the player
        for (int i=0; i < swordOptions.size(); i++) {
            std::cout << "(" << i + 1 << ") " << swordOptions[i]->str() << "\n";
        }

        int answer;
        std::cin >> answer;

        // answer - 1 to ensure that the answer matches the option's index
        answer = answer - 1;

        if (answer < 0 || answer >= swordOptions.size()) {
            std::cout << "Invalid choice\n";
            return;
        }

        Card* choosen = swordOptions[answer];

        CardCollection& bank = otherPlayer.getBank();

        // the choosen card is then removed from the other player's bank
        for (int i=0; i<bank.size(); i++) {
            if (bank[i] == choosen) {
                bank.erase(bank.begin() + i);
                break;
            }
        }

        // player gets to play the choosen card
        player.playCard(choosen, game);
    }


}