#include "player.h"
#include <iostream>
#include <cstdlib>

Player::Player() {
    std::string names[] = {"Sam", "Billy", "Jen", "Bob", "Sally", "Joe", "Sue", "Sasha", "Tina", "Marge"};
    _name = names[rand() % 10];

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
        for (int j = i + 1; i < playArea.size(); j++) {
            if(playArea[i]->type() == playArea[i]->type()) {
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
}

void Player::printPlayArea() const {
    std::cout<<_name<<"'s Play Area: \n";
}

int Player::getScore() const {
    int total = 0;
    for (Card* c : playArea) {
        total += c->value(); // change to only adding the highest value of suit together 
    }
}