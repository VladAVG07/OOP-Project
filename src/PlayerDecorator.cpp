#include "../include/PlayerDecorator.h"

#include <iostream>
#include <ctime>

PlayerDecorator::PlayerDecorator(std::shared_ptr<Player> player)
    : wrappedPlayer(player), Player(player->hand1(), player->get_name(), player->balance1()) {
}

void PlayerDecorator::modifyBalance() {
    int chance = rand() % 100;
    if (chance < 50) {
        int newBalance = wrappedPlayer->balance1() * 2;
        std::cout << wrappedPlayer->get_name() << " balanta s-a dublat balanta: multumiri decorator pattern " << newBalance << std::endl;
        wrappedPlayer->set_balance(newBalance);
    } else {
        std::cout << wrappedPlayer->get_name() << " balanta ramane la fel aiurea " << wrappedPlayer->balance1() <<
                std::endl;
    }
}

std::unique_ptr<Player> PlayerDecorator::clone() const {
    return wrappedPlayer->clone();
}
