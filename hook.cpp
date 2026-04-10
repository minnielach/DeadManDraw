#include "hook.h"
#include "player.h"
#include <iostream>

HookCard::HookCard(int value) : Card(Hook, value) {
}

std::string HookCard::str() const {
    return "Hook(" + std::to_string(value()) + ")";
}

void HookCard:: play(Game &game, Player &player) {

    std::vector<Card*> hookOptions = player.getHighestValueSuit();

    if (hookOptions.empty()) {
        std::cout << "No cards currently in the bank.\n";
    } else {
        std::cout<< "Select a highest value card from any of the suits in your bank.\n";
        for (int i=0; i < hookOptions.size(); i++) {
            std::cout << "(" << i + 1 << ")" << hookOptions[i]->str() << "\n";
        }

        int answer;
        std::cin >> answer;

        answer = answer - 1;

        if (answer < 0 || answer >= hookOptions.size()) {
            std::cout << "Invalid choice\n";
            return;
        }

        Card* choosen = hookOptions[answer];

        CardCollection& bank = player.getBank();

        for (int i=0; i<bank.size(); i++) {
            if (bank[i] == choosen) {
                bank.erase(bank.begin() + i);
                break;
            }
        }

        player.playCard(choosen, game);
    }


}