#ifndef PLAYER_DECORATOR_H
#define PLAYER_DECORATOR_H

#include "Player.h"

class PlayerDecorator : public Player {
protected:
    std::shared_ptr<Player> wrappedPlayer;

public:
    PlayerDecorator(std::shared_ptr<Player> player);
    virtual void modifyBalance() override;
    std::unique_ptr<Player> clone() const override;
};

#endif // PLAYER_DECORATOR_H
