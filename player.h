#include "card.h"


class Player {
    private:
    std::string name;
    CardCollection playArea;
    CardCollection bank;

    public:
    Player();
    bool playCard(Card *card, Game& game);

    bool bust() const;
    
    void manageBank() const;

    void printBank() const;
    void printPlayArea() const;

    int getScore() const;

};