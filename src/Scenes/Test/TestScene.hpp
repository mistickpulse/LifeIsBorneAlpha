//
// Created by zouz on 05/02/18.
//

#ifndef LIFEISBORNE_TESTSCENE_HPP
#define LIFEISBORNE_TESTSCENE_HPP

#include "../../Manager/SceneManager/AScene.hpp"
#include "../../Dungeon/Dungeon.hpp"

class TestScene : public AScene
{
public:
    explicit TestScene(sf::RenderWindow &win);
    ~TestScene() final = default;

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

    gen::GenerationProfile _profile;
    gen::Dungeon _dungeon;
    Inputs::InputManager &_iptMgr;
    sf::Time _timer;
    int Iteration{200};
};

#endif //LIFEISBORNE_TESTSCENE_HPP
