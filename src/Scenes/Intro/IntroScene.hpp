//
// Created by zouz on 28/01/18.
//

#ifndef LIFEISBORNE_INTROSCENE_HPP
#define LIFEISBORNE_INTROSCENE_HPP

#include <SFML/Graphics.hpp>
#include "../../Manager/SceneManager/AScene.hpp"
#include "../../Manager/EventManager/EventManager.hpp"
#include "../../Manager/EventManager/Events/SceneEvents.hpp"
#include "../../Manager/RessourceManager/RessourceManager.hpp"

namespace
{
    const sf::Time maxTimer = sf::seconds(3);
}

class IntroScene : public AScene
{
public:
    IntroScene(sf::RenderWindow &win);
    ~IntroScene() = default;

public:
    void enter() override;
    void leave() override;
    void pause() override;
    void resume() override;
    void draw() override;
    void update(sf::Time &elapsedTime) override;
    void ProcessInput() override;


    //Scene subFonctionalities
private:
    void __load();
    void __unload();

private:
    void __loadTextures();
    void __loadSprites();
private:
    sf::Time _timer;
    RessourceManager<std::string, sf::Texture> _textures;
    RessourceManager<std::string, sf::Sprite> _sprite;
};

#endif //LIFEISBORNE_INTROSCENE_HPP
