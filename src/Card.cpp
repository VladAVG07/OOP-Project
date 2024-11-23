//
// Created by vladg on 11/6/2024.
//

#include "Card.h"

Card::Card(std::string rank, std::string suit) {
    this->rank = rank;
    this->suit = suit;
}

Card::Card() = default;

Card::~Card() = default;

Card::Card(const Card &other)
    : rank(other.rank),
      suit(other.suit) {
}

Card::Card(Card &&other) noexcept : rank(other.rank),
                                    suit(other.suit) {
}

Card &Card::operator=(const Card &other) {
    if (this == &other)
        return *this;
    this->rank = other.rank;
    this->suit = other.suit;
    return *this;
}

std::string Card::rank1() const {
    return this->rank;
}

void Card::set_rank(const std::string &rank) {
    this->rank = rank;
}

std::string Card::suit1() const {
    return this->suit;
}

void Card::set_suit(const std::string &suit) {
    this->suit = suit;
}

std::ostream & operator<<(std::ostream &os, const Card &obj) {
    return os
           << "rank: " << obj.rank
           << " suit: " << obj.suit
            << '\n';
}








