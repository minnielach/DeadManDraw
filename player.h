#pragma once
#include "card.h"
#include <iostream>
#include <vector>


class Player {
    private:
    std::string _name;
    CardCollection playArea;
    CardCollection bank;

    public:
    Player();
    bool playCard(Card *card, Game& game);

    CardCollection& getBank();

    std::string getName() const;

    bool bust() const;
    
    void manageBank();

    void printBank() const;
    void printPlayArea() const;

    int getScore() const;

    Card* removeHighestValueCard();

    std::vector<Card*> getHighestValueSuit() const;

    CardCollection &getPlayArea();
};