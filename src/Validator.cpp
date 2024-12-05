//
// Created by vladg on 11/23/2024.
//
#include "../include/Validator.h"

void Validator::getWinner(std::vector<HumanPlayer> &players) {
    int maxRank;
    for(size_t i = 0 ; i < players.size() ; i++) {

    }
}

void Validator::setRanks(std::vector<HumanPlayer> &players) {
    for(size_t i = 0 ; i < players.size() ; i++) {
        std::vector<Card> currHand = players[i].hand1();
        sortHand(currHand);
        if(isRoyalFlush(currHand)) players[i].set_hand_rank(10);
        if(isStraightFlush(currHand)) players[i].set_hand_rank(9);
        if(isFourOfAKind(currHand)) players[i].set_hand_rank(8);
        if(isFullHouse(currHand)) players[i].set_hand_rank(7);
        if(isFlush(currHand)) players[i].set_hand_rank(6);
        if(isStraight(currHand)) players[i].set_hand_rank(5);
        if(isThreeOfAKind(currHand)) players[i].set_hand_rank(4);
        if(isTwoPair(currHand)) players[i].set_hand_rank(3);
        if(isPair(currHand)) players[i].set_hand_rank(2);
        else players[i].set_hand_rank(1);
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
    for(size_t i = 0 ; i < hand.size() - 3 ; i++) {
        if((hand[i].rank1() == hand[i+1].rank1()) == (hand[i+2].rank1() == hand[i+3].rank1())) {
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
