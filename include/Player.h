#ifndef PLAYER_H
#define PLAYER_H

#include <ostream>
#include <vector>
#include <string>
#include <memory>
#include "Card.h"
#include <SFML/Graphics.hpp>

class Player {
protected:
    std::vector<Card> hand;
    std::string name;
    int balance;
    int currentBet;
    bool folded;
    bool active;
    int handRank;

    sf::Texture *textura;
    sf::Sprite *sprite;

    inline static int nrPlayers;

public:
    Player(std::vector<Card> hand, std::string name, int balance);

    Player();

    virtual ~Player();
    void call(int newBet);
    void check();

    [[nodiscard]] int balance1() const;

    [[nodiscard]] bool active1() const;

    void raise(int newBet);
    void fold();
    void set_active(bool active);

    void draw(sf::RenderWindow *window);

    [[nodiscard]] std::string get_name() const;

    [[nodiscard]] virtual std::unique_ptr<Player> clone() const = 0;

    [[nodiscard]] virtual std::string getRole() const;

    [[nodiscard]] std::vector<Card> hand1() const;

    void set_hand(const std::vector<Card> &hand);

    void set_hand_rank(int hand_rank);

    [[nodiscard]] int getHandRank() const;

    void describe() const;

    Player(const Player &other);
    Player(Player &&other) noexcept;
    Player &operator=(const Player &other);
    Player &operator=(Player &&other) noexcept;

    friend std::ostream &operator<<(std::ostream &os, const Player &obj);};


#endif //PLAYER_H
