#include "card.h"

Card::Card(CardType type, int value){
    _value = value;
    _type = type;
}

const CardType& Card:: type() const{
    return _type;
}

int Card::value() const {
    return _value;
}
