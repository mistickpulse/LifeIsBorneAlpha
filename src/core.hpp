//
// Created by zouz on 13/11/17.
//

#ifndef LIFEISBORNE_CORE_HPP
#define LIFEISBORNE_CORE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Manager/InputManager/InputManager.hpp"

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
    InputManager _imanager;
};

#endif //LIFEISBORNE_CORE_HPP
