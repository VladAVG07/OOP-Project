#ifndef DEALER_H
#define DEALER_H

#include "Player.h"

class Dealer : public Player {
public:
    Dealer(std::vector<Card> hand, std::string name, int balance);

    Dealer(const Dealer &other);
    Dealer& operator=(const Dealer& other);

    [[nodiscard]] std::string getRole() const override;
    [[nodiscard]] std::unique_ptr<Player> clone() const override;
};

#endif //DEALER_H
