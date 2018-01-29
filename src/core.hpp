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
#include "Manager/EventManager/Events/MainEvent.hpp"

class Core : public Receiver<Core>
{

public:
    Core();
    ~Core() = default;

public:
    void run();

    //Event Receivers
public:
    void receive(const Evt::StopGame &ev);


private:
    sf::RenderWindow win;
    Evt::EventManager &_evtMgr;
    SceneManager _scManager;

    RessourceManager<std::string, sf::Texture> _Textures;
    RessourceManager<std::string, sf::Sprite> _sprites;
};

#endif //LIFEISBORNE_CORE_HPP
