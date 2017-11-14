//
// Created by zouz on 14/11/17.
//

#include "IntroManager.hpp"

void IntroManager::reset() {
    _timer = sf::microseconds(0);
}

void IntroManager::update(const sf::Time &elapsedTime) {
    _timer += elapsedTime;
}

bool IntroManager::isIntroFinish() const {
    return _timer >= IntroTime;
}
