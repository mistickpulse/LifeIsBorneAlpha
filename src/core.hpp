//
// Created by zouz on 13/11/17.
//

#ifndef LIFEISBORNE_CORE_HPP
#define LIFEISBORNE_CORE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Manager/InputManager/InputManager.hpp"
#include "Manager/RessourceManager/RessourceManager.hpp"
#include "Manager/SceneManager/ScenesManager.hpp"
#include "Manager/EventManager/EventManager.hpp"

class Core {

public:
    Core();
    ~Core() = default;

public:
    void run();

private:
    sf::RenderWindow win;
    EventManager &_evtMgr;
    InputManager _imanager;
    SceneManager _scManager;

    RessourceManager<sf::Texture> _Textures;
};

#endif //LIFEISBORNE_CORE_HPP
