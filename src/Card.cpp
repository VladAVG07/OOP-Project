#include <string>
#include <ostream>

class Card {
private:
    std::string rank;
    std::string suit;

public:
    Card(std::string rank , std::string suit) {
        this->rank = rank;
        this->suit = suit;
    }
    Card() = default;
    ~Card() = default;

    Card(const Card &other)
        : rank(other.rank),
          suit(other.suit) {
    }

    Card(Card &&other) noexcept
        : rank(other.rank),
          suit(other.suit) {
    }

    Card & operator=(const Card &other) {
        if (this == &other)
            return *this;
        this->rank = other.rank;
        this->suit = other.suit;
        return *this;
    }

    std::string rank1() const {
        return rank;
    }

    std::string suit1() const {
        return suit;
    }

    friend std::ostream & operator<<(std::ostream &os, const Card &obj) {
        return os
               << "rank: " << obj.rank
               << " suit: " << obj.suit
                << '\n';
    }
};
