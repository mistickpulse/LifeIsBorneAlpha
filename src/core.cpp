//
// Created by zouz on 14/11/17.
//



#include <boost/filesystem.hpp>
#include "core.hpp"

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
        subrun(timeStamp);
        win.display();
    }
}

void Core::_init() {
}

Core::Core(): rm(RessourceManager::getInstance()), win(sf::VideoMode(1920, 1080), "Life is Borne")
{
    _init();
}

void Core::subrun(const sf::Time &elapsedTime) {
    win.clear(sf::Color::Black);
    if (!intro.isIntroFinish()) {
        return ;
    }
    else
    {
//        win.close();
    }
}


