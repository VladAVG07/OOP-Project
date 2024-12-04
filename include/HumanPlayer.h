#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"

class HumanPlayer : public Player {
public:
    HumanPlayer(std::vector<Card> hand, std::string name, int balance);

    HumanPlayer(const HumanPlayer& other);
    HumanPlayer& operator=(const HumanPlayer& other);

    [[nodiscard]] std::string getRole() const override;
    [[nodiscard]] std::unique_ptr<Player> clone() const override;
};

#endif //HUMANPLAYER_H
