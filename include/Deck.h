//
// Created by vladg on 11/6/2024.
//
#ifndef DECK_H
#define DECK_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "Card.h"
#include "Collection.h"


class Deck {
private:
    sf::Texture *textura;
    sf::Sprite *sprite;
    Collection<Card> cards;

    const std::string suits[4] = {"hearts", "clubs", "diamonds", "spades"};
    const std::string ranks[13] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "11" ,"12", "13", "14"};

    const int DECK_SIZE = 52;

public:
    Deck();

    ~Deck();

    Deck(const Deck &other);

    Deck(Deck &&other) noexcept;

    Deck &operator=(const Deck &other);

    Deck &operator=(Deck &&other) noexcept;

    [[nodiscard]] Collection<Card> getCards() const;

    void shuffle();

    Card dealFromDeck();

    [[nodiscard]] sf::Sprite * sprite1() const {
        return sprite;
    }

    friend std::ostream &operator<<(std::ostream &out, Deck &d);
};


#endif //DECK_H
