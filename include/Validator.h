//
// Created by vladg on 11/23/2024.
//

#ifndef VALIDATOR_H
#define VALIDATOR_H
#include <vector>

#include "Card.h"


class Validator {

static void validate(const std::vector<Card>& playerHand, const std::pmr::vector<Card>& dealerHand) {

}

public:
    Validator() = default;
    ~Validator();
};


#endif //VALIDATOR_H
