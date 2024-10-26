//
// Created by vladg on 10/26/2024.
//

#include <ostream>
#include <vector>
#include "Card.cpp"

class Player {
private:
    std::vector<Card> hand;
    std::string name;
    int balance;
    int current_bet;
    bool folded;
    bool active;

public:
    Player(std::vector<Card> hand, std::string name) {
        this->hand = hand;
        this->name = name;
        this->balance = 1000;
        this->current_bet = 10;
        folded = false;
    }

    ~Player() = default;

    void call(int newBet) {
        if(this->current_bet+newBet < this->balance) {
            this->fold();
        } else {
            this->current_bet += newBet;
            this->check();
        }
    };

    void check() {
        this->active = false;
    };

    void raise(int newBet) {
        this->current_bet += newBet;
    };

    void fold() {
        this->folded = true;
    };

    void set_active(bool active) {
        this->active = active;
    };

    Player(const Player &other)
        : hand(other.hand),
          name(other.name),
          balance(other.balance),
          current_bet(other.current_bet),
          folded(other.folded),
          active(other.active) {
    }

    Player(Player &&other) noexcept
        : hand(std::move(other.hand)),
          name(std::move(other.name)),
          balance(other.balance),
          current_bet(other.current_bet),
          folded(other.folded),
          active(other.active) {
    }

    Player & operator=(const Player &other) {
        if (this == &other)
            return *this;
        hand = other.hand;
        name = other.name;
        balance = other.balance;
        current_bet = other.current_bet;
        folded = other.folded;
        active = other.active;
        return *this;
    }

    Player & operator=(Player &&other) noexcept {
        if (this == &other)
            return *this;
        hand = std::move(other.hand);
        name = std::move(other.name);
        balance = other.balance;
        current_bet = other.current_bet;
        folded = other.folded;
        active = other.active;
        return *this;
    }

    friend std::ostream & operator<<(std::ostream &os, const Player &obj) {
        os << obj.name << '\n' << "balance: " << obj.balance << " current bet:" << obj.current_bet << '\n';
        for(int i = 0 ; i < 2 ; i++) {
            os << obj.hand[i] << " / ";
        }
        os << '\n';
        return os;
    }
};
