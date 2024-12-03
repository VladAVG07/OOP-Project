//
// Created by vladg on 11/6/2024.
//

#include "../include/Game.h"

#include <cmath>
#include <iostream>

void Game::initWindow() {
    this->videoMode.height = 1000;
    this->videoMode.width = 1600;
    this->window = new sf::RenderWindow(this->videoMode, "My Window", sf::Style::Close);
    this->window->setVerticalSyncEnabled(true);
    this->deck.sprite1()->setPosition(sf::Vector2f{0 , 400});
}

void Game::initVar() {
    this->window = nullptr;
    this->font = new sf::Font();
    this->font->loadFromFile("../assets/fonts/KingdomCrown.otf");
}

Game::Game(const int nrPlayers) {
    this->initVar();
    this->initWindow();
    this->players.resize(nrPlayers);
}

Game::~Game() {
    delete this->window;
};

Game &Game::operator=(const Game &other) {
    if (this == &other)
        return *this;
    nrRounds = other.nrRounds;
    deck = other.deck;
    players = other.players;
    tableCards = other.tableCards;
    return *this;
}

Game &Game::operator=(Game &&other) noexcept {
    if (this == &other)
        return *this;
    nrRounds = other.nrRounds;
    deck = std::move(other.deck);
    players = std::move(other.players);
    tableCards = std::move(other.tableCards);
    return *this;
}


void Game::start() {
    std::cout << "Start Game, player numbers: " << this->players.size() << std::endl;
    this->deck.shuffle();
    //std::cout << this->deck;
    std::cout << "---------------------\n";

    for (int i = 0; i < static_cast<int>(this->players.size()); i++) {
        std::cout << "Introduceti numele jucatorului: " << std::endl;
        std::string numeJucator;
        std::cin >> numeJucator;
        std::vector<Card> playerHand;
        playerHand.push_back(this->deck.dealFromDeck());
        playerHand.push_back(this->deck.dealFromDeck());
        Player p(playerHand, numeJucator);
        this->players[i] = p;
        std::cout << players[i];
    }

    std::cout << "Cartile de pe masa: " << '\n';
    for (int i = 0; i < 3; i++) {
        this->tableCards.push_back(this->deck.dealFromDeck());
        std::cout << tableCards[i];
    }

    //TODO AFISARE PENTRU TOATE CARTILE
}

void Game::update() {
    this->pollEvents();
}

void Game::render() {
    this->window->clear();

    //TODO Draw the game here
    this->window->draw(*this->deck.sprite1());

    this->window->display();
}

void Game::pollEvents() {
    while (this->window->pollEvent(this->ev)) {
        switch (this->ev.type) {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (ev.key.code == sf::Keyboard::Escape) {
                    this->window->close();
                }
                break;
            default:
                break;
        }
    }
}

bool Game::isRunning() const {
    return this->window->isOpen();
}
