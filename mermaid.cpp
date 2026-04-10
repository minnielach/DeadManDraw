#include "mermaid.h"
#include <iostream> 

MermaidCard::MermaidCard(int value) : Card(Mermaid, value) {
}

// returns mermaid's string and value
std:: string MermaidCard::str() const {
    return "Mermaid(" + std::to_string(value()) + ")";
}

// mermaid's ability which does not exist but is worth more
void MermaidCard:: play(Game &game, Player &player) {
    std::cout << "No effects but Mermaids are worth more.\n";
}