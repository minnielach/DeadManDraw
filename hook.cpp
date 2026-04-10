#include "hook.h"
#include "player.h"
#include <iostream>

HookCard::HookCard(int value) : Card(Hook, value) {
}

//returns hook's string and value
std::string HookCard::str() const {
    return "Hook(" + std::to_string(value()) + ")";
}

// hook's abiity which allows player to play any card of the highest value from any suit
void HookCard:: play(Game &game, Player &player) {

    std::vector<Card*> hookOptions = player.getHighestValueSuit();

    // checks if player's bank is empty
    if (hookOptions.empty()) {
        std::cout << "No cards in your bank. Play continues.\n";
    } else {
        std::cout<< "Select a highest value card from any of the suits in your bank.\n";
        // prints the list of options for the player to select
        for (int i=0; i < hookOptions.size(); i++) {
            std::cout << "(" << i + 1 << ")" << hookOptions[i]->str() << "\n";
        }

        int answer;
        std::cin >> answer;

        // answer - 1 ensures that the answer aligns with the indee of the options
        answer = answer - 1;

        if (answer < 0 || answer >= hookOptions.size()) {
            std::cout << "Invalid choice\n";
            return;
        }

        Card* choosen = hookOptions[answer];

        CardCollection& bank = player.getBank();

        // remove the card from the bank
        for (int i=0; i<bank.size(); i++) {
            if (bank[i] == choosen) {
                bank.erase(bank.begin() + i);
                break;
            }
        }

        // the player plays the card
        player.playCard(choosen, game);
    }


}