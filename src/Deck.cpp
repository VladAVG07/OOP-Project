//
// Created by vladg on 11/6/2024.
//

#include "../include/Deck.h"

#include <iostream>

Deck::Deck() {
    // this->textura = new sf::Texture;
    // if(!this->textura->loadFromFile("../assets/deck-of-cards/Back1.png")) {
    //     std::cout<< "aiaus\n";
    // }
    // this->sprite = new sf::Sprite;
    // this->sprite->setTexture(*this->textura);
    // this->sprite->setScale(2, 2);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            Card c(ranks[j], suits[i]);
            this->cards.add(c);
        }
    }
}

Deck::~Deck() = default;

Deck::Deck(const Deck &other) : cards(other.cards) {
}

Deck::Deck(Deck &&other) noexcept : cards(std::move(other.cards)) {
}

Deck &Deck::operator=(const Deck &other) {
    if (this == &other)
        return *this;
    cards = other.cards;
    return *this;
}

Deck &Deck::operator=(Deck &&other) noexcept {
    if (this == &other)
        return *this;
    cards = std::move(other.cards);
    return *this;
}

Collection<Card> Deck::getCards() const {
    return this->cards;
}

void Deck::shuffle() {
    srand(time(nullptr));

    for (int i = DECK_SIZE - 1; i > 0; i--) {
        int j = rand() % (i + 1);

        Card aux;
        aux = cards.getAt(i);
        cards.getAt(i) = cards.getAt(j);
        cards.getAt(j) = aux;
    }
}

Card Deck::dealFromDeck() {
    Card newCard = this->cards.getAt(cards.size() - 1);
    this->cards.removeLast();
    return newCard;
}

std::ostream &operator<<(std::ostream &out, Deck &d) {
    for (int i = 0; i < d.DECK_SIZE; i++) {
        out << d.cards.getAt(i);
    }
    return out;
}
