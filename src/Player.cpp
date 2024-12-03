//
// Created by vladg on 11/6/2024.
//

#include "../include/Player.h"

Player::Player(std::vector<Card> hand, std::string name) {
    this->hand = hand;
    this->name = name;
    this->balance = 1000;
    this->currentBet = 10;
    folded = false;
    this->active = true;
}

Player::Player() = default;

Player::~Player()  {
    delete sprite;
    delete textura;
};

Player::Player(const Player &other)
    : hand(other.hand),
      name(other.name),
      balance(other.balance),
      currentBet(other.currentBet),
      folded(other.folded),
      active(other.active) {
}

Player::Player(Player &&other) noexcept
    : hand(std::move(other.hand)),
      name(std::move(other.name)),
      balance(other.balance),
      currentBet(other.currentBet),
      folded(other.folded),
      active(other.active) {
}

Player &Player::operator=(const Player &other) {
    if (this == &other)
        return *this;
    hand = other.hand;
    name = other.name;
    balance = other.balance;
    currentBet = other.currentBet;
    folded = other.folded;
    active = other.active;
    return *this;
}

Player &Player::operator=(Player &&other) noexcept {
    if (this == &other)
        return *this;
    hand = std::move(other.hand);
    name = std::move(other.name);
    balance = other.balance;
    currentBet = other.currentBet;
    folded = other.folded;
    active = other.active;
    return *this;
}

void Player::check() {
    this->active = false;
}

void Player::fold() {
    this->folded = true;
}

void Player::set_active(const bool active) {
    this->active = active;
}

void Player::call(int newBet) {
    if (this->currentBet + newBet < this->balance) {
        this->fold();
    } else {
        this->currentBet += newBet;
        this->check();
    }
}

void Player::raise(int newBet) {
    this->currentBet += newBet;
}

std::string Player::get_name() {
    return this->name;
}

void Player::draw(sf::RenderWindow *window) {
    window->draw(*this->sprite);
}


std::ostream &operator<<(std::ostream &os, const Player &obj) {
    os << obj.name << '\n' << "balance: " << obj.balance << " current bet:" << obj.currentBet << '\n';
    for (int i = 0; i < 2; i++) {
        os << obj.hand[i] << " / ";
    }
    os << '\n';
    return os;
}
