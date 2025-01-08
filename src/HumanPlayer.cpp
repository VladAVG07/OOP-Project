#include "../include/HumanPlayer.h"

HumanPlayer::HumanPlayer(std::vector<Card> hand, std::string name, int balance)
    : Player(std::move(hand), std::move(name), balance) {}

HumanPlayer::HumanPlayer(const HumanPlayer &other) : Player(other) {}

HumanPlayer & HumanPlayer::operator=(const HumanPlayer &other) {
    if(this != &other) {
        Player::operator=(other);
    }
    return *this;
}

std::string HumanPlayer::getRole() const {
    return "Human Player";
}

std::unique_ptr<Player> HumanPlayer::clone() const {
    return std::make_unique<HumanPlayer>(*this);
}
