//
// Created by vladg on 1/9/2025.
//

#ifndef PLAYERFACTORY_H
#define PLAYERFACTORY_H

#include <memory>
#include <string>
#include <stdexcept>
#include "Player.h"
#include "HumanPlayer.h"
#include "AIPlayer.h"
#include "Dealer.h"
#include "Card.h"

class PlayerFactory {
public:
    static std::shared_ptr<Player> createPlayer(
        const std::string& type,
        const std::string& name,
        int balance,
        std::vector<Card> hand
    );
};

#endif //PLAYERFACTORY_H
