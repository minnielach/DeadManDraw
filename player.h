#pragma once
#include "card.h"


class Player {
    private:
    std::string _name;
    CardCollection playArea;
    CardCollection bank;

    public:
    Player();
    bool playCard(Card *card, Game& game);

    bool bust() const;
    
    void manageBank();

    void printBank() const;
    void printPlayArea() const;

    int getScore() const;

};