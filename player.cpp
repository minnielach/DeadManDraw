#include "player.h"
#include <iostream>
#include <cstdlib>

Player::Player() {
    std::string names[] = {"Sam", "Billy", "Jen", "Bob", "Sally", "Joe", "Sue", "Sasha", "Tina", "Marge"};
    _name = names[rand() % 10];

}

// returns player's name
std::string Player:: getName() const {
    return this->_name;
}

// return's player's bank
CardCollection& Player:: getBank() {
    return bank;
}

// allows player to play the card
bool Player::playCard(Card *card, Game& game) {
    // adds the card to the play arena
    playArea.push_back(card);

    // checks if player has busted (if not, card is played)
    if (bust()) {
        return true;
    }
    else {
        card->play(game, *this);
        return false;
    }
}

// boolean used to check if the player has busted
bool Player::bust() const {

    // for loop which compares each card in the play area to see if there is a duplicate
    for (int i = 0; i < playArea.size(); i++) {
        for (int j = i + 1; j < playArea.size(); j++) {
            if(playArea[i]->type() == playArea[j]->type()) {
                return true;
            }
        }

    }

    return false;

}

// cards in the play area are added to the bank
void Player::manageBank() {
    for (Card* c : playArea) {
        bank.push_back(c);
    }

    // play area cleared
    playArea.clear();
}

// prints the player's bank
void Player::printBank() const {
    std::cout<<_name<<"'s Bank: \n";

    for (Card* c : bank) {
        std::cout << c->str(); 
        std::cout<< "\n";
    }
}

// prints the player's play area
void Player::printPlayArea() const {
    std::cout<<_name<<"'s Play Area: \n";

    for (Card* c : playArea) {
        std::cout << c->str(); 
        std::cout<< "\n";
    }
}

// returns the total score 
int Player::getScore() const {
    int total = 0;

    // temporary vector added to keep track of the highest value card of suits they have
    std::vector<Card*> score = getHighestValueSuit();

    // adds the value of the cards
    for (Card* c : score) {
        total += c->value();
    }

    return total;
}

// removes the highest value card which is to support the cannon's ability
Card* Player::removeHighestValueCard() { 
    if (bank.empty()) {
        return nullptr;
    }

    int highestValue = 0;
    
    // for loop which compared which card is the highest in their bank
    for (int i=0; i < bank.size(); i++) {
        if (bank[i]->value() > bank[highestValue]->value()) {
            highestValue = i;
        }
    }

    Card* card=bank[highestValue];

    // removes the card from the bank
    bank.erase(bank.begin() + highestValue);


    return card;
}

// returns the highest value card in each suit
std::vector<Card*> Player:: getHighestValueSuit() const{
    // creates a temporary array for each suit
    Card* highest[9] = {nullptr};

    // for loop which checks the cards types and value in the bank 
    for (Card* c : bank) {
        int cardType = c-> type();

        // if statement which returns null if they do not have the suit, or if that card's value is higher than the other card's value (ensuring that they the same card type)
        if (highest[cardType] == nullptr || c->value() > highest[cardType]->value()) {
            highest[cardType] = c;
        }
    }

    // creates a temporary vector of the highest values
    std::vector<Card*> listOfHighestValue;

    // removes all of the nulls in the vector
    for (int i = 0; i < 9; i++) {
        if (highest[i] != nullptr) {
            listOfHighestValue.push_back(highest[i]);
        }
    }

    return listOfHighestValue;

}

// returns play area
CardCollection& Player :: getPlayArea() {
    return playArea;
}