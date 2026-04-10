#include "player.h"
#include <iostream>
#include <cstdlib>

Player::Player() {
    std::string names[] = {"Sam", "Billy", "Jen", "Bob", "Sally", "Joe", "Sue", "Sasha", "Tina", "Marge"};
    _name = names[rand() % 10];

}

std::string Player:: getName() const {
    return _name;
}

CardCollection& Player:: getBank() {
    return bank;
}

bool Player::playCard(Card *card, Game& game) {
    playArea.push_back(card);

    if (bust()) {
        return true;
    }
    else {
        card->play(game, *this);
        return false;
    }
}

bool Player::bust() const {
    for (int i = 0; i < playArea.size(); i++) {
        for (int j = i + 1; j < playArea.size(); j++) {
            if(playArea[i]->type() == playArea[j]->type()) {
                return true;
            }
        }

    }

    return false;

}

void Player::manageBank() {
    for (Card* c : playArea) {
        bank.push_back(c);
    }

    playArea.clear();
}

void Player::printBank() const {
    std::cout<<_name<<"'s Bank: \n";

    for (Card* c : bank) {
        std::cout << c->str(); 
        std::cout<< "\n";
    }
}

void Player::printPlayArea() const {
    std::cout<<_name<<"'s Play Area: \n";

    for (Card* c : playArea) {
        std::cout << c->str(); 
        std::cout<< "\n";
    }
}

int Player::getScore() const {
    int total = 0;

    std::vector<Card*> score = getHighestValueSuit();

    for (Card* c : score) {
        total += c->value(); // change to only adding the highest value of suit together 
    }

    return total;
}

Card* Player::removeHighestValueCard() { // canons ability
    if (bank.empty()) {
        return nullptr;
    }

    int highestValue = 0;

    for (int i=0; i < bank.size(); i++) {
        if (bank[i]->value() > bank[highestValue]->value()) {
            highestValue = i;
        }
    }

    Card* card=bank[highestValue];

    bank.erase(bank.begin() + highestValue);


    return card;
}

std::vector<Card*> Player:: getHighestValueSuit() const{
    Card* highest[9] = {nullptr};

    for (Card* c : bank) {
        int cardType = c-> type();

        if (highest[cardType] == nullptr || c->value() > highest[cardType]->value()) {
            highest[cardType] = c;
        }
    }

    std::vector<Card*> listOfHighestValue;

    for (int i = 0; i < 9; i++) {
        if (highest[i] != nullptr) {
            listOfHighestValue.push_back(highest[i]);
        }
    }

    return listOfHighestValue;

}