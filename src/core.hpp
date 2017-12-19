//
// Created by zouz on 13/11/17.
//

#ifndef LIFEISBORNE_CORE_HPP
#define LIFEISBORNE_CORE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Core {

public:
    Core();
    ~Core() = default;

public:
    void run();

private:
    void subrun();

private:
    sf::RenderWindow win;
};

#endif //LIFEISBORNE_CORE_HPP
