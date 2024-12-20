//
// Created by vladg on 11/6/2024.
//

#include "Deck.h"

Deck::Deck() {
    for(int i = 0 ; i < 4 ; i++) {
        for(int j = 0 ; j < 13 ; j++) {
            Card c(ranks[j] , suits[i]);
            this->cards.push_back(c);
        }
    }
}

Deck::~Deck() = default;
Deck::Deck(const Deck &other) : cards(other.cards) {}
Deck::Deck(Deck &&other) noexcept : cards(std::move(other.cards)) {}
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

std::vector<Card> Deck::getCards() const {
    return this->cards;
}

void Deck::shuffle() {
    srand(time(nullptr));

    for(int i = DECK_SIZE-1 ; i > 0 ; i--) {
        int j = rand() % (i+1);

        Card aux;
        aux = cards[i];
        cards[i] = cards[j];
        cards[j] = aux;
    }
}

Card Deck::dealFromDeck() {
    Card newCard = this->cards[cards.size() -1];
    this->cards.pop_back();
    return newCard;
}

std::ostream& operator<<(std::ostream & out , Deck & d) {
    for(int i = 0 ; i < d.DECK_SIZE ; i++) {
        out << d.cards[i];
    }
    return out;
}








