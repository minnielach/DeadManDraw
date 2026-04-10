#pragma once
#include "card.h"

class KeyCard : public Card {
    public:
    KeyCard(int value);

    std::string str() const override;
    void play(Game &game, Player &player) override;
    
};