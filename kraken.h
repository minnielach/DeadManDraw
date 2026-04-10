#pragma once
#include "card.h"
#include <iostream>

class KrakenCard : public Card {
    public:
    KrakenCard(int value);

    std::string str() const override;
    void play(Game &game, Player &player) override;
    
};