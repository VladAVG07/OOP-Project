//
// Created by vladg on 12/4/2024.
//

#ifndef POKEREXCEPTIONS_H
#define POKEREXCEPTIONS_H

#include <exception>
#include <string>

class InvalidPlayerNameException : public std::exception {
private:
    std::string message;

public:
    explicit InvalidPlayerNameException(const std::string &message);
    [[nodiscard]] const char* what() const noexcept override;
};

class InvalidBetException : public std::exception {
private:
    std::string message;
public:
    explicit InvalidBetException(const std::string& msg);
    [[nodiscard]] const char* what() const noexcept override;
};


class MaxPlayersExcedeedException : public std::exception {
private:
    std::string message;

public:
    explicit MaxPlayersExcedeedException(const std::string& msg);
    [[nodiscard]] const char* what() const noexcept override;
};


#endif //POKEREXCEPTIONS_H
