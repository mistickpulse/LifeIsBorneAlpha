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
    win(WindowSize, WindowName), _evtMgr(EventManager::getInstance())
{
}

void Core::run() {
    sf::Clock clock;
    sf::Time timeStamp;

    while (win.isOpen()) {
        timeStamp = clock.restart();
        sf::Event ev;

        while (win.pollEvent(ev)) {
           if (ev.type == sf::Event::Closed)
               win.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
            EventManager::getInstance().emit<TestEvent>("zob");
        }
        _imanager.update();
        win.display();
    }
}

