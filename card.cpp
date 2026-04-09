#include "card.h"

Card::Card(CardType type, int value){
    _value = value;
    _type = type;
}

CardType Card::type() const{
    return _type;
}

int Card::value() const {
    return _value;
}

std::string Card::toString() {
    return std::to_string(_type + _value);
}
