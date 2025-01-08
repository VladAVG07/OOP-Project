//
// Created by vladg on 11/23/2024.
//
#include "../include/Validator.h"

#include <iostream>

void Validator::getWinner(std::vector<std::shared_ptr<Player>> &players) {
    int maxRank = 0;
    for(const auto& player : players) {
        if(player->getHandRank() > maxRank) maxRank = player->getHandRank();
    }

    for(const auto& player : players) {
        if(player->getHandRank() == maxRank) {
            std::cout << "jucatorul " << player->get_name() << " castigator\n";
        }
    }
}

void Validator::setRanks(std::vector<std::shared_ptr<Player>> &players) {
    for (const auto& currentPlayer : players) {
        std::vector<Card> currHand = currentPlayer->hand1();

        sortHand(currHand);

        if (isRoyalFlush(currHand)) currentPlayer->set_hand_rank(10);
        else if (isStraightFlush(currHand)) currentPlayer->set_hand_rank(9);
        else if (isFourOfAKind(currHand)) currentPlayer->set_hand_rank(8);
        else if (isFullHouse(currHand)) currentPlayer->set_hand_rank(7);
        else if (isFlush(currHand)) currentPlayer->set_hand_rank(6);
        else if (isStraight(currHand)) currentPlayer->set_hand_rank(5);
        else if (isThreeOfAKind(currHand)) currentPlayer->set_hand_rank(4);
        else if (isTwoPair(currHand)) currentPlayer->set_hand_rank(3);
        else if (isPair(currHand)) currentPlayer->set_hand_rank(2);
        else currentPlayer->set_hand_rank(1);
    }
}



void Validator::sortHand(std::vector<Card> &hand) {
    std::sort(hand.begin(), hand.end());
}

bool Validator::isRoyalFlush(std::vector<Card> &hand) {
    if(isFlush(hand)) {
        if(hand[0].rank1() == "10" && hand[1].rank1() == "11"
            && hand[2].rank1() == "12" && hand[3].rank1() == "13"
            && hand[4].rank1() == "14") {
            return true;
        }
    }
    return false;
}

bool Validator::isStraightFlush(std::vector<Card> &hand) {
    if(isFlush(hand) && isStraight(hand)) {
        return true;
    }
    return false;
}

bool Validator::isFourOfAKind(std::vector<Card> &hand) {
    for (size_t i = 0; i < hand.size() - 3; i++) {
        if (hand[i].rank1() == hand[i + 1].rank1() &&
            hand[i].rank1() == hand[i + 2].rank1() &&
            hand[i].rank1() == hand[i + 3].rank1()) {
            return true;
            }
    }
    return false;
}


bool Validator::isFullHouse(std::vector<Card> &hand) {
    if(isPair(hand) && isThreeOfAKind(hand)) {
        return true;
    }
    return false;
}

bool Validator::isFlush(std::vector<Card> &hand) {
    for (size_t i = 0; i < hand.size() - 1; i++) {
        if (hand[i].suit1() != hand[i + 1].suit1()) {
            return false;
        }
    }
    return true;
}

bool Validator::isStraight(std::vector<Card> &hand) {
    for (size_t i = hand.size() -1 ; i > 0; i--) {
        if(std::stoi(hand[i].rank1()) - std::stoi(hand[i-1].rank1()) != 1) {
            return false;
        }
    }
    return true;
}

bool Validator::isThreeOfAKind(std::vector<Card> &hand) {
    for (size_t i = 0; i < hand.size() - 2; i++) {
        if (hand[i].rank1() == hand[i + 1].rank1() && hand[i + 1].rank1() == hand[i + 2].rank1()) {
            return true;
        }
    }
    return false;
}

bool Validator::isTwoPair(std::vector<Card> &hand) {
    int nrPairs = 0;
    for (size_t i = 0; i < hand.size() - 1; i++) {
        if (hand[i].rank1() == hand[i + 1].rank1()) {
            nrPairs++;
        }
    }
    if (nrPairs == 2) return true;
    return false;
}

bool Validator::isPair(const std::vector<Card> &hand) {
    for (size_t i = 0; i < hand.size() - 1; i++) {
        if (hand[i].rank1() == hand[i + 1].rank1()) {
            return true;
        }
    }
    return false;
}

Card Validator::HighCard(std::vector<Card> &hand) {
    return hand[hand.size() - 1];
}
