#include "../include/Dealer.h"

Dealer::Dealer(std::vector<Card> hand, std::string name, int balance)
    : Player(std::move(hand), std::move(name), balance) {}

Dealer::Dealer(const Dealer &other) : Player(other) {
}

Dealer & Dealer::operator=(const Dealer &other) {
    if(this != &other) {
        Player::operator=(other);
    }
    return *this;
}

std::string Dealer::getRole() const {
    return "Dealer";
}

std::unique_ptr<Player> Dealer::clone() const {
    return std::make_unique<Dealer>(*this);
}

