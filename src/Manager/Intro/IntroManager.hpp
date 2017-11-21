//
// Created by zouz on 14/11/17.
//

#ifndef LIFEISBORNE_INTROMANAGER_HPP
#define LIFEISBORNE_INTROMANAGER_HPP

#include <SFML/System/Time.hpp>

namespace {
    sf::Time IntroTime(sf::seconds(5.0));
}

class IntroManager {
public:
    IntroManager() = default;
    ~IntroManager() = default;

public:
    void reset();
    void update(const sf::Time &elapsedTime);
    bool isIntroFinish() const;

private:
    sf::Time _timer;
};

#endif //LIFEISBORNE_INTROMANAGER_HPP
