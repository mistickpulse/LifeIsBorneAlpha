//
// Created by zouz on 13/11/17.
//

#ifndef LIFEISBORNE_CORE_HPP
#define LIFEISBORNE_CORE_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Entities/AEntity.hpp"
#include "GamePhases.hpp"
#include "Manager/Intro/IntroManager.hpp"
#include "Manager/RessourceManager/RessourceManager.hpp"
#include "Manager/ConfigManager/ConfigManager.hpp"

class Core {

public:
    Core();
    ~Core() = default;

public:
    void _init();
    void run();
    void subrun(const sf::Time &elapsedTime);

private:
    ConfigManager _configManager;
    RessourceManager &rm;
    IntroManager intro;
    GamePhases _currentPhase;
    sf::RenderWindow win;
    std::vector<AEntity> entities;
};

#endif //LIFEISBORNE_CORE_HPP
