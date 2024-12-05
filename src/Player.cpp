#include "../include/Player.h"

#include <iostream>

#include "../include/PokerExceptions.h"

Player::Player(std::vector<Card> hand, std::string name, int balance)
    : hand(std::move(hand)), name(std::move(name)), balance(balance), currentBet(0), folded(false), active(false),
      textura(nullptr), sprite(nullptr) {
    Player::nrPlayers++;
    if(this->name.empty()) {
        throw InvalidPlayerNameException("Nume invalid");
    }
}

Player::Player() : balance(0), currentBet(0), folded(false), active(false), textura(nullptr), sprite(nullptr) {}

Player::~Player() {
    delete textura;
    delete sprite;
    Player::nrPlayers--;
}

void Player::call(int newBet) {
    currentBet = newBet;
    balance -= newBet;
}

void Player::check() {}

void Player::raise(int newBet) {
    currentBet = newBet;
    balance -= newBet;
}

void Player::fold() {
    folded = true;
}

void Player::set_active(bool active) {
    this->active = active;
}

void Player::draw(sf::RenderWindow *window) {
    if (sprite && window) {
        window->draw(*sprite);
    }
}

std::string Player::get_name() const {
    return name;
}

std::string Player::getRole() const {
    return "Normal Player";
}

std::vector<Card> Player::hand1() const {
    return hand;
}

int Player::getHandRank() const {
    return this->handRank;
}

void Player::set_hand(const std::vector<Card> &hand) {
    this->hand.insert(this->hand.end(), hand.begin(), hand.end());
}

void Player::set_hand_rank(int handRank) {
    this->handRank = handRank;
}

void Player::describe() const {
    std::cout << "Name: " << name << ", Balance: $" << balance << ", Role: " << getRole() << std::endl;
}

Player::Player(const Player &other)
    : hand(other.hand), name(other.name), balance(other.balance), currentBet(other.currentBet),
      folded(other.folded), active(other.active), textura(other.textura), sprite(other.sprite) {}

Player::Player(Player &&other) noexcept
    : hand(std::move(other.hand)), name(std::move(other.name)), balance(other.balance), currentBet(other.currentBet),
      folded(other.folded), active(other.active), textura(other.textura), sprite(other.sprite) {
    other.textura = nullptr;
    other.sprite = nullptr;
}

Player &Player::operator=(const Player &other) {
    if (this == &other) return *this;

    hand = other.hand;
    name = other.name;
    balance = other.balance;
    currentBet = other.currentBet;
    folded = other.folded;
    active = other.active;
    textura = other.textura;
    sprite = other.sprite;

    return *this;
}

Player &Player::operator=(Player &&other) noexcept {
    if (this == &other) return *this;

    hand = std::move(other.hand);
    name = std::move(other.name);
    balance = other.balance;
    currentBet = other.currentBet;
    folded = other.folded;
    active = other.active;
    textura = other.textura;
    sprite = other.sprite;

    other.textura = nullptr;
    other.sprite = nullptr;

    return *this;
}

std::ostream &operator<<(std::ostream &os, const Player &obj) {
    os << "Name: " << obj.name << ", Balance: $" << obj.balance;
    return os;
}
