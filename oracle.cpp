#include "oracle.h"
#include <iostream>

OracleCard::OracleCard(int value) : Card(Oracle, value) {
}

std::string OracleCard::str() const {
    return "Oracle(" + std::to_string(value()) + ")";
}

void OracleCard:: play(Game &game, Player &player) {
    

}
