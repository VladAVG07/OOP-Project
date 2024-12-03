//
// Created by vladg on 11/6/2024.
//
#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Player.h"
#include "Deck.h"
#include <SFML/Graphics.hpp>

#include "Dealer.h"

class Game {
private:
    int nrRounds = 3;
    Deck deck;
    std::vector<Player> players;
    std::vector<Card> tableCards;

    sf::RenderWindow *window;
    sf::VideoMode videoMode;
    sf::Event ev;
    sf::Font *font;
    sf::Text *titleText;

    void initWindow();
    void initVar();

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

    Game &operator=(const Game &other);

    Game &operator=(Game &&other) noexcept;

    void update();

    void render();

    void pollEvents();

    [[nodiscard]] bool isRunning() const;
};


#endif //GAME_H
