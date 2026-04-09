#include <string> 
#include <vector>

enum CardType {
    Cannon, Chest, Key, Sword, Hook, Oracle, Map, Mermaid, Kraken
    };

class Card {

    private:
    CardType _type;
    int _value;

    public:
    Card(CardType type, int value);

    virtual ~Card() {};

    const CardType& type() const;
    int value() const;

    virtual std::string str() const = 0;
    virtual void play(Game &game, Player &player) = 0;
    virtual void willAddToBank(Game &game, Player &player) { }
    
};

typedef std::vector<Card*> CardCollection;