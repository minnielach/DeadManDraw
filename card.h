#include <string> 
#include "player.h"
#include "game.h"

enum CardType {
    Cannon, Chest, Key, Anchor, Sword, Hook, Oracle, Map, Mermaid, Kraken
    };

class Card {

    private:
    CardType _type;
    int _value;

    public:
    Card(CardType type, int value);
    const CardType& type() const;
    int value() const;
    virtual std::string str() const = 0;
    virtual void play(Game &game, Player &player) = 0;
    virtual void willAddToBank(Game &game, Player &player) { }
    
};

typedef std::vector<Card*> CardCollection;