//
// Created by vladg on 1/9/2025.
//

#include "../include/PlayerFactory.h"

std::shared_ptr<Player> PlayerFactory::createPlayer(
    const std::string& type,
    const std::string& name,
    int balance,
    std::vector<Card> hand
) {
    if (type == "Human") {
        return std::make_shared<HumanPlayer>(hand, name, balance);
    } else if (type == "AI") {
        return std::make_shared<AIPlayer>(hand,name, balance);
    } else if (type == "Dealer") {
        return std::make_shared<Dealer>(hand,name, balance);
    } else {
        throw std::invalid_argument("Invalid player type");
    }
}

