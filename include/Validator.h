//
// Created by vladg on 11/23/2024.
//

#ifndef VALIDATOR_H
#define VALIDATOR_H
#include <vector>

#include "Card.h"
#include "HumanPlayer.h"
#include "Player.h"
#include "Collection.h"


class Validator {
public:
    Validator() = default;
    ~Validator();

    static void getWinner(Collection<std::shared_ptr<Player>> &players);
    static void setRanks(Collection<std::shared_ptr<Player>> &players);
    static void sortHand(std::vector<Card> &hand);
    static bool isRoyalFlush(std::vector<Card> &hand);
    static bool isStraightFlush(std::vector<Card> &hand);
    static bool isFourOfAKind(std::vector<Card> &hand);
    static bool isFullHouse(std::vector<Card> &hand);
    static bool isFlush(std::vector<Card> &hand);
    static bool isStraight(std::vector<Card> &hand);
    static bool isThreeOfAKind(std::vector<Card> &hand);
    static bool isTwoPair(std::vector<Card> &hand);
    static bool isPair(const std::vector<Card> &hand);
    static auto HighCard(std::vector<Card> &hand) -> Card;
};


#endif //VALIDATOR_H
