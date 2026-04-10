#include "key.h"
#include <iostream>

KeyCard::KeyCard(int value) : Card(Chest, value) {

}

std::string KeyCard::str() const {
    return "Key(" + std::to_string(value()) + ")";
}

void KeyCard:: play(Game &game, Player &player) {
    std::cout << "No immidiate effect. If banked with a chest, draw as many bonus cards from the discard pile as you moved into your bank.\n";
}