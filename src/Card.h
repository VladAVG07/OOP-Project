//
// Created by vladg on 11/6/2024.
//
#ifndef CARD_H
#define CARD_H

#include <string>
#include <ostream>

class Card {
private:
    std::string rank;
    std::string suit;

public:
    Card(std::string rank, std::string suit);
    Card();
    ~Card();
    Card(const Card &other);
    Card(Card &&other) noexcept ;
    Card & operator=(const Card &other);

    std::string rank1() const;

    void set_rank(const std::string &rank);

    std::string suit1() const;

    void set_suit(const std::string &suit);

    friend std::ostream & operator<<(std::ostream &os, const Card &obj);
};

#endif //CARD_H
