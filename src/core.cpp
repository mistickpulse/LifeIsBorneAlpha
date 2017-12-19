//
// Created by zouz on 14/11/17.
//

#include <boost/filesystem.hpp>
#include <iostream>
#include "core.hpp"

namespace {
    const sf::VideoMode WindowSize{1080, 720};
    const std::string WindowName("LifeIsBorne");
}

Core::Core() :
        win(WindowSize, WindowName) {
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
        _imanager.update();
        win.display();
    }
}

void Core::subrun() {
}

