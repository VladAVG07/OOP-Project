//
// Created by vladg on 11/6/2024.
//
#ifndef DECK_H
#define DECK_H

#include <vector>
#include "Card.h"


class Deck {
private:
    std::vector<Card> cards;

    const std::string suits[4] = {"hearts" , "clubs" , "diamonds" , "spades"};
    const std::string ranks[13] = {"Ace", "2" , "3" , "4" , "5" , "6" , "7"
                            , "8" , "9" , "10" , "Jack" , "Queen" , "King"};

    const int DECK_SIZE = 52;

public:
    Deck();
    ~Deck();
    Deck(const Deck &other);
    Deck(Deck &&other) noexcept;
    Deck & operator=(const Deck &other);
    Deck & operator=(Deck &&other) noexcept;
    std::vector<Card> getCards() const;
    void shuffle();
    Card dealFromDeck();
    friend std::ostream& operator<<(std::ostream & out , Deck & d);
};



#endif //DECK_H
