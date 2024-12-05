#include <iostream>
#include <array>
#include <chrono>
#include <thread>

#include <SFML/Graphics.hpp>

#include <Helper.h>
#include "include/Deck.h"
#include "include/Game.h"

//////////////////////////////////////////////////////////////////////
/// NOTE: this include is needed for environment-specific fixes     //
/// You can remove this include and the call from main              //
/// if you have tested on all environments, and it works without it //
#include "env_fixes.h"                                              //
#include "include/PokerExceptions.h"
//////////////////////////////////////////////////////////////////////


int main() {
    ////////////////////////////////////////////////////////////////////////
    /// NOTE: this function call is needed for environment-specific fixes //

    try {
        init_threads();

        Game game(2);

        game.start();

        while (game.isRunning()) {

            using namespace std::chrono_literals;
            std::this_thread::sleep_for(300ms);

            game.update();

            game.render();
        }
    } catch (InvalidPlayerNameException &ex) {
        std::cout << "Eroare: " << ex.what() << "\n";
    } catch (MaxPlayersExcedeedException &ex) {
        std::cout << "Eroare: " << ex.what() << "\n";
    }

    // sf::RenderWindow window;
    // sf::Texture textura;
    // sf::Sprite sprite;
    //
    // if(!textura.loadFromFile("../assets/deck-of-cards/2.1.png")) {
    //     std::cout << "aiaus\n";
    // }
    // sprite.setTexture(textura);

    // ///////////////////////////////////////////////////////////////////////////
    // /// NOTE: sync with env variable APP_WINDOW from .github/workflows/cmake.yml:31
    // window.create(sf::VideoMode({800, 700}), "My Window", sf::Style::Default);
    // ///////////////////////////////////////////////////////////////////////////
    // //
    // ///////////////////////////////////////////////////////////////////////////
    // /// NOTE: mandatory use one of vsync or FPS limit (not both)            ///
    // /// This is needed so we do not burn the GPU                            ///
    // window.setVerticalSyncEnabled(true);                                    ///
    // /// window.setFramerateLimit(60);                                       ///
    // ///////////////////////////////////////////////////////////////////////////
    //
    // while(window.isOpen()) {
    //     bool shouldExit = false;
    //     sf::Event e{};
    //     while(window.pollEvent(e)) {
    //         switch(e.type) {
    //         case sf::Event::Closed:
    //             window.close();
    //             break;
    //         case sf::Event::Resized:
    //             std::cout << "New width: " << window.getSize().x << '\n'
    //                       << "New height: " << window.getSize().y << '\n';
    //             break;
    //         case sf::Event::KeyPressed:
    //             std::cout << "Received key " << (e.key.code == sf::Keyboard::X ? "X" : "(other)") << "\n";
    //             if(e.key.code == sf::Keyboard::Escape)
    //                 shouldExit = true;
    //             break;
    //         default:
    //             break;
    //         }
    //     }
    //     if(shouldExit) {
    //         window.close();
    //         break;
    //     }
    //     using namespace std::chrono_literals;
    //     std::this_thread::sleep_for(300ms);
    //
    //     window.clear();
    //     window.draw(sprite);
    //     window.display();
    // }


    return 0;
}
