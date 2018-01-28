//
// Created by zouz on 14/11/17.
//

#include <boost/filesystem.hpp>
#include <iostream>
#include "core.hpp"

namespace {
    const sf::VideoMode WindowSize{1920, 1080};
    const std::string WindowName("LifeIsBorne");
}

Core::Core() :
    win(WindowSize, WindowName), _evtMgr(Evt::EventManager::getInstance()), _scManager(win)
{
    _evtMgr.subscribe<Evt::StopGame>(*this);
}

void Core::run() {
    _evtMgr.emit<Evt::ChangeScene>(Scenes::SceneType::Intro);
    sf::Clock clock;
    sf::Time timeStamp;

    while (win.isOpen()) {
        timeStamp = clock.restart();
        sf::Event ev;

        while (win.pollEvent(ev)) {
           if (ev.type == sf::Event::Closed)
               win.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            _evtMgr.emit<Evt::StopGame>();
        }
        _imanager.update();
        _scManager.update(timeStamp);
        win.display();
    }
}

void Core::receive([[maybe_unused]]const Evt::StopGame &ev)
{
    std::cout << "Closing Game" << std::endl;
    win.close();
}


