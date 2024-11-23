//
// Created by vladg on 11/6/2024.
//
#ifndef PLAYER_H
#define PLAYER_H

#include <ostream>
#include <vector>
#include "Card.h"

class Player {
private:
    std::vector<Card> hand;
    std::string name;
    int balance;
    int current_bet;
    bool folded;
    bool active;

public:
    Player(std::vector<Card> hand, std::string name);
    Player();
    ~Player();

    void call(int newBet);
    void check();
    void raise(int newBet);
    void fold();

    void set_active(const bool active);

    std::string get_name();

    Player(const Player &other);
    Player(Player &&other) noexcept;
    Player & operator=(const Player &other);
    Player & operator=(Player &&other) noexcept;
    friend std::ostream & operator<<(std::ostream &os, const Player &obj);
};



#endif //PLAYER_H
