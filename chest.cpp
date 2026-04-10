#include "chest.h"
#include <iostream>

ChestCard::ChestCard(int value) : Card(Chest, value) {

}

// returns chest's string and value 
std::string ChestCard::str() const {
    return "Chest(" + std::to_string(value()) + ")";
}

// chest's ability which was no immedidiate effect
void ChestCard:: play(Game &game, Player &player) {
    std::cout << "No immidiate effect. If banked with a key, draw as many bonus cards from the discard pile as you moved into your bank.\n";
}