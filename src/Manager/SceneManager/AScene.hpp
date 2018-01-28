//
// Created by zouz on 28/01/18.
//

#ifndef LIFEISBORNE_ASCENE_HPP
#define LIFEISBORNE_ASCENE_HPP

#include <SFML/Graphics/RenderWindow.hpp>

class AScene
{
public:
    AScene(sf::RenderWindow &win, const std::string &SceneName) :
        win(win), _name(SceneName)
    {
    }

    virtual ~AScene() = default;

public:
    virtual void enter() = 0;
    virtual void leave() = 0;
    virtual void pause() = 0;
    virtual void resume() = 0;
    virtual void update(sf::Time &elapsedTime) = 0;
    virtual void ProcessInput() = 0;
    virtual void draw() = 0;

protected:
    sf::RenderWindow &win;
    const std::string _name;
    bool _paused = false;
};

#endif //LIFEISBORNE_ASCENE_HPP
