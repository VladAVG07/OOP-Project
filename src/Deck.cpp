//
// Created by vladg on 10/26/2024.
//

#include <vector>
#include "Card.cpp"

class Deck {
private:
    std::vector<Card> cards;

    const std::string suits[4] = {"hearts" , "clubs" , "diamonds" , "spades"};
    const std::string ranks[13] = {"Ace", "2" , "3" , "4" , "5" , "6" , "7"
                            , "8" , "9" , "10" , "Jack" , "Queen" , "King"};

public:
    Deck() {
        for(int i = 0 ; i < 4 ; i++) {
            for(int j = 0 ; j < 13 ; j++) {
                Card c(ranks[j] , suits[i]);
                this->cards.push_back(c);
            }
        }
    };
    ~Deck() = default;

    Deck(const Deck &other)
        : cards(other.cards) {
    }

    Deck(Deck &&other) noexcept
        : cards(std::move(other.cards)) {
    }

    Deck & operator=(const Deck &other) {
        if (this == &other)
            return *this;
        cards = other.cards;
        return *this;
    }

    Deck & operator=(Deck &&other) noexcept {
        if (this == &other)
            return *this;
        cards = std::move(other.cards);
        return *this;
    }

    std::vector<Card> getCards() const {
        return cards;
    }

    void shuffle() {
        srand(time(nullptr));

        for(int i = cards.size() -1 ; i > 0 ; i--) {
            int j = rand() % (i+1);

            Card aux;
            aux = cards[i];
            cards[i] = cards[j];
            cards[j] = aux;
        }
    };

    friend std::ostream& operator<<(std::ostream & out , Deck & d) {
        for(int i = 0 ; i < d.cards.size() ; i++) {
            out << d.cards[i];
        }
        return out;
    }
};
