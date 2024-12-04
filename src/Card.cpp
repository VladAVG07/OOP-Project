//
// Created by vladg on 11/6/2024.
//

#include "../include/Card.h"

#include <iostream>

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

bool operator<(const Card &lhs, const Card &rhs) {
    return std::stoi(lhs.rank) < std::stoi(rhs.rank);
}

std::ostream &operator<<(std::ostream &os, const Card &obj) {
    std::string rank1;
    switch (std::stoi(obj.rank)) {
        case 11:
            rank1 = "jack";
            break;
        case 12:
            rank1 = "queen";
            break;
        case 13:
            rank1 = "king";
            break;
        case 14:
            rank1 = "ace";
            break;
        default:
            rank1 = obj.rank;
            break;
    }
    return os
           << "rank: " << rank1
           << " suit: " << obj.suit
           << '\n';
}
