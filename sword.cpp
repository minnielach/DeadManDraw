#include "sword.h"
#include "player.h"
#include "game.h"
#include <iostream>

SwordCard::SwordCard(int value) : Card(Sword, value) {
}

std::string SwordCard::str() const {
    return "Sword(" + std::to_string(value()) + ")";
}

void SwordCard:: play(Game &game, Player &player) {

    Player& otherPlayer = game.getOtherPlayer();
    std::vector<Card*> swordOptions = otherPlayer.getHighestValueSuit();

    if (swordOptions.empty()) {
        std::cout << "No cards currently in their bank to steal.\n";
    } else {
        std::cout<< "Steal the top card of any suit from the other player's bank into your play area.\n";
        for (int i=0; i < swordOptions.size(); i++) {
            std::cout << "(" << i + 1 << ")" << swordOptions[i]->str() << "\n";
        }

        int answer;
        std::cin >> answer;

        answer = answer - 1;

        if (answer < 0 || answer >= swordOptions.size()) {
            std::cout << "Invalid choice\n";
            return;
        }

        Card* choosen = swordOptions[answer];

        CardCollection& bank = otherPlayer.getBank();

        for (int i=0; i<bank.size(); i++) {
            if (bank[i] == choosen) {
                bank.erase(bank.begin() + i);
                break;
            }
        }

        player.playCard(choosen, game);
    }


}