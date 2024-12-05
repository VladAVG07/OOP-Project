#include "../include/AIPlayer.h"

AIPlayer::AIPlayer(std::vector<Card> hand, std::string name, int balance)
    : Player(std::move(hand), std::move(name), balance) {}

AIPlayer::AIPlayer(const AIPlayer &other) : Player(other){
}

AIPlayer & AIPlayer::operator=(const AIPlayer &other) {
    if(this != &other) {
        Player::operator=(other);
    }
    return *this;
}

std::string AIPlayer::getRole() const {
    return "AI Player";
}

std::unique_ptr<Player> AIPlayer::clone() const {
    return std::make_unique<AIPlayer>(*this);
}
