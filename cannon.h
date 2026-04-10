#pragma once
#include "card.h"
#include <iostream>

class CannonCard : public Card {
    public:
    CannonCard(int value);

    std::string str() const override;
    void play(Game &game, Player &player) override;
    
};