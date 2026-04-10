#pragma once
#include "card.h"
#include <iostream>

class SwordCard : public Card {
    public:
    SwordCard(int value);

    std::string str() const override;
    void play(Game &game, Player &player) override;
    
};