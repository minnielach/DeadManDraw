#include <string> 

enum CardType {
    Cannon, Chest, Key, Anchor, Sword, Hook, Oracle, Map, Mermaid, Kraken
    };

class Card {

    private:
    CardType _type;
    int _value;

    public:
    Card(CardType type, int value);
    CardType type() const;
    int value() const;
    std::string toString();
};