#include "mermaid.h"
#include <iostream> 

MermaidCard::MermaidCard(int value) : Card(Mermaid, value) {
}

std:: string MermaidCard::str() const {
    return "Mermaid(" + std::to_string(value()) + ")";
}

void MermaidCard:: play(Game &game, Player &player) {
    std::cout << "No effects but Mermaids are worth more.\n";
}