//
// Created by vladg on 11/6/2024.
//
#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Player.h"
#include "Deck.h"

class Game {
private:
    int nrRounds = 3;
    Deck deck;
    std::vector<Player> players;
    std::vector<Card> tableCards;

public:
    Game(int nrPlayers);
    ~Game();

    void start();

    Game(const Game &other)
        : nrRounds(other.nrRounds),
          deck(other.deck),
          players(other.players),
          tableCards(other.tableCards) {
    }

    Game(Game &&other) noexcept
        : nrRounds(other.nrRounds),
          deck(std::move(other.deck)),
          players(std::move(other.players)),
          tableCards(std::move(other.tableCards)) {
    }

    Game & operator=(const Game &other);

    Game & operator=(Game &&other) noexcept;
};



#endif //GAME_H
