//
// Created by vladg on 11/29/2024.
//

#ifndef DEALER_H
#define DEALER_H
#include "Player.h"
#include "SFML/Graphics.hpp"


class Dealer : public Player {
private:

public:
    Dealer();

    ~Dealer();

    [[nodiscard]] sf::Texture * textura1() const;

    [[nodiscard]] sf::Sprite * sprite1() const;

    void set_sprite(sf::Sprite *sprite);

    void initVars();
};



#endif //DEALER_H
