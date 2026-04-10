#pragma once
#include "card.h"

class OracleCard : public Card {
    public:
    OracleCard(int value);

    std::string str() const override;
    void play(Game &game, Player &player) override;
    
};