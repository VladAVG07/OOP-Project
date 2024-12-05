//
// Created by vladg on 11/6/2024.
//
#ifndef CARD_H
#define CARD_H

#include <string>
#include <ostream>
#include <SFML/Graphics.hpp>

class Card {
private:
    sf::Texture *textura;
    sf::Sprite *sprite;
    std::string rank;
    std::string suit;

public:
    Card(std::string rank, std::string suit);

    Card();

    ~Card();

    Card(const Card &other);

    Card(Card &&other) noexcept;

    Card &operator=(const Card &other);

    [[nodiscard]] std::string rank1() const;

    void set_rank(const std::string &rank);

    [[nodiscard]] std::string suit1() const;

    void set_suit(const std::string &suit);

    sf::Sprite * sprite1() {
        return sprite;
    }

    friend bool operator<(const Card &lhs, const Card &rhs);

    friend std::ostream &operator<<(std::ostream &os, const Card &obj);
};

#endif //CARD_H
