#ifndef AIPLAYER_H
#define AIPLAYER_H

#include "Player.h"

class AIPlayer : public Player {
public:
    AIPlayer(std::vector<Card> hand, std::string name, int balance);

    AIPlayer(const AIPlayer &other);
    AIPlayer& operator=(const AIPlayer & other);

    [[nodiscard]] std::string getRole() const override;
    [[nodiscard]] std::unique_ptr<Player> clone() const override;
};

#endif //AIPLAYER_H
