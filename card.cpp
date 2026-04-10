#include "card.h"

Card::Card(CardType type, int value){
    _value = value;
    _type = type;
}

// returns the type of card
const CardType& Card:: type() const{
    return _type;
}

// returns the value of the card
int Card::value() const {
    return _value;
}
