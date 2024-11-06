//
// Created by vladg on 11/6/2024.
//

#include "Game.h"

#include <iostream>

Game::Game(const int nrPlayers) {
    this->players.resize(nrPlayers);
}

Game::~Game() = default;

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

    for(int i = 0 ; i < this->players.size() ; i++) {
        std::cout << "Introduceti numele jucatorului: "  << std::endl;
        std::string numeJucator;
        std::cin >> numeJucator;
        std::vector<Card> playerHand;
        playerHand.push_back(this->deck.dealFromDeck());
        playerHand.push_back(this->deck.dealFromDeck());
        Player p(playerHand , numeJucator);
        this->players[i] = p;
        std::cout << players[i];
    }

    std::cout<<"Cartile de pe masa: " << '\n';
    for(int i = 0 ; i < 3 ; i++) {
        this->tableCards.push_back(this->deck.dealFromDeck());
        std::cout << tableCards[i];
    }

    //TODO AFISARE PENTRU TOATE CARTILE
    for(int i = 0 ; i < 2 ; i++) {
        this->tableCards.push_back(this->deck.dealFromDeck());

        for(int j = 0 ; j < static_cast<int>(this->players.size()) ; j++) {
            while(true) {
                std::cout << this->players[j];
                std::cout << "Optiuni:\n" << "1.Check\n" << "2.Call\n" << "3.Fold\n" << "4.Bet\n";
                int varianta;
                std::cin >> varianta;
                if(varianta == 1) {
                    this->players[i].check();
                    break;
                }
                if(varianta == 2) {
                    this->players[i].call(10);
                    break;
                }
                if(varianta == 3) {
                    this->players[i].fold();
                    break;
                }
                if(varianta == 4) {
                    std::cout << "Cu cat vrei sa maresti? \n";
                    int newBet;
                    std::cin >> newBet;
                    this->players[i].raise(newBet);
                    break;
                }
            }
        }
    }
}


