//
// Created by vladg on 11/6/2024.
//

#include "../include/Game.h"

#include <cmath>
#include <iostream>

#include "../include/PokerExceptions.h"
#include "../include/Validator.h"
#include "../include/PlayerDecorator.h"
#include "../include/Collection.h"
#include "../include/PlayerFactory.h"


void Game::initWindow() {
    // this->videoMode.height = 1000;
    // this->videoMode.width = 1600;
    // this->window = new sf::RenderWindow(this->videoMode, "My Window", sf::Style::Close);
    // this->window->setVerticalSyncEnabled(true);
    this->deck.sprite1()->setPosition(sf::Vector2f{0, 400});
}

void Game::initVar() {
    this->window = nullptr;
    this->font = new sf::Font();
    this->font->loadFromFile("../assets/fonts/KingdomCrown.otf");
}

Game::Game(const int nrPlayers) {
    if (nrPlayers > 2) {
        throw MaxPlayersExcedeedException("prea multi jucatori");
    }
    this->nrPlayers = nrPlayers;
    // this->initVar();
    // this->initWindow();
}

Game::~Game() {
    //delete this->window;
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
    char playAgain = 'y';

    while (playAgain == 'y' || playAgain == 'Y') {
        std::cout << "Start Game, player numbers: " << this->players.size() << std::endl;
        this->deck = Deck();
        this->deck.shuffle();
        std::cout << this->deck;
        std::cout << "---------------------\n";

        this->players.clear();

        for (int i = 0; i < this->nrPlayers; i++) {
            std::cout << "Introduceti numele jucatorului: " << std::endl;
            std::string numeJucator;
            std::cin >> numeJucator;
            std::vector<Card> playerHand;
            playerHand.push_back(this->deck.dealFromDeck());
            playerHand.push_back(this->deck.dealFromDeck());
            auto p = PlayerFactory::createPlayer("Human" , numeJucator , 1000, playerHand );
            this->players.add(p);
            auto player = players.getAt(i);
            if (player) {
                std::cout << *player << '\n';
                std::shared_ptr<Player> decoratedPlayer = std::make_shared<PlayerDecorator>(player);
                decoratedPlayer->modifyBalance();
            } else {
                std::cerr << "Error: Player not found at index " << i << std::endl;
                return;
            }
        }

        std::vector<Card> dealerHand;
        dealerHand.push_back(this->deck.dealFromDeck());
        dealerHand.push_back(this->deck.dealFromDeck());

        auto d = PlayerFactory::createPlayer("Dealer" , "Dealer" , 1000 , dealerHand);
        this->players.add(d);

        std::cout << "Dealerul a intrat in joc, let's start" << "\n";

        std::vector<Card> tableCards;
        tableCards.emplace_back(this->deck.dealFromDeck());
        tableCards.emplace_back(this->deck.dealFromDeck());
        tableCards.emplace_back(this->deck.dealFromDeck());

        for (int i = 1; i <= 2; i++) {
            int tableBet = 0;
            int activePlayers = 0;
            for (const auto& player : players) {
                if (!std::dynamic_pointer_cast<Dealer>(player) && player->active1()) {
                    activePlayers++;
                    std::cout << "Pariul de la masa: " << tableBet << "\n";
                    std::cout << *player << "\n";
                    for (const auto& card : player->hand1()) {
                        std::cout << card;
                    }
                    std::cout << "Optiuni: " << "\n" << "1.Check" << "\n" << "2.Call" << "\n" << "3.Bet" << "\n" << "4.Fold" << "\n";
                    int optiune;
                    std::cin >> optiune;
                    switch (optiune) {
                        case 1:
                            if (!tableBet) {
                                player->check();
                            } else {
                                std::cout << "Va trebui sa maresti betul cu " << tableBet << "\n";
                                player->call(tableBet);
                            }
                            break;
                        case 2:
                            std::cout << "Va trebui sa maresti betul cu " << tableBet << "\n";
                            player->call(tableBet);
                            break;
                        case 3:
                            std::cout << "Cu cat vrei sa maresti?" << "\n";
                            int bet;
                            std::cin >> bet;
                            if (bet > player->balance1()) std::cout << "nu ai atatia bani" << "\n";
                            player->raise(bet);
                            tableBet = bet;
                            break;
                        case 4:
                            player->fold();
                            break;
                        default:
                            std::cout << "Optiune gresita ghinion" << "\n";
                            break;
                    }
                }
                if (player->balance1() <= 0 || !player->active1()) {
                    player->fold();
                    activePlayers--;
                }
            }
            if (activePlayers == 1) {
                std::cout << "avem un castigator, meciul s-a terminat" << "\n";
            }
            std::cout << "\n" << "--------------CARTILE DE PE MASA-----------------" << "\n";
            for (const auto& card : tableCards) {
                std::cout << card;
            }
            std::cout << "--------------CARTILE DE PE MASA-----------------" << "\n";
        }

        for (const auto& player : this->players) {
            player->set_hand(tableCards);
            std::cout << player->get_name() <<  " mana:" << "\n";
            for (const auto& card : player->hand1()) {
                std::cout << card;
            }
        }

        Validator::setRanks(this->players);

        for (const auto& player : players) {
            std::cout << player->getHandRank() << '\n';
        }

        Validator::getWinner(this->players);

        std::cout << "Vrei sa continui cu o noua runda? (y/n): ";
        std::cin >> playAgain;

    }
}

void Game::update() {
    this->pollEvents();
}

void Game::render() {
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
