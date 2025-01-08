//
// Created by vladg on 12/4/2024.
//

#include "../include/PokerExceptions.h"

InvalidPlayerNameException::InvalidPlayerNameException(const std::string &message) : message(message) {
}

const char * InvalidPlayerNameException::what() const noexcept {
    return message.c_str();
}

InvalidBetException::InvalidBetException(const std::string &message) : message(message){
}

const char * InvalidBetException::what() const noexcept {
    return message.c_str();
}

MaxPlayersExcedeedException::MaxPlayersExcedeedException(const std::string &message) : message(message){
}

const char * MaxPlayersExcedeedException::what() const noexcept {
    return message.c_str();
}
