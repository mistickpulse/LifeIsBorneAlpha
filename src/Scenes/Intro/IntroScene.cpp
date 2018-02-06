//
// Created by zouz on 28/01/18.
//

#include <iostream>
#include "IntroScene.hpp"
#include "TextureId.hpp"

void IntroScene::enter()
{
    _evtMgr.emit<Evt::ChangeInputContext>(Inputs::ContextList::Menu);
    std::cout << "entering Scene" << _name << std::endl;
    win.clear(sf::Color::Black);
    __load();
}

void IntroScene::leave()
{
    __unload();
    _timer = sf::seconds(0);
}

void IntroScene::pause()
{
}

void IntroScene::resume()
{
}

void IntroScene::draw()
{
    IntroSprites var = IntroSprites::BackGround;
    win.draw(_sprite[var._to_string()]);
}

void IntroScene::update(sf::Time &elapsedTime)
{
    _timer += elapsedTime;
    draw();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::T)) {
        _evtMgr.emit<Evt::ChangeScene>(Scenes::SceneType::TestScene);
    }
    if (_timer >= maxTimer) {
        _evtMgr.emit<Evt::ChangeScene>(Scenes::SceneType::SalleArcade);
    }
}

void IntroScene::ProcessInput()
{
}

IntroScene::IntroScene(sf::RenderWindow &win) :
    AScene(win, "Intro Scene")
{}

void IntroScene::__load()
{
    __loadTextures();
    __loadSprites();
}

void IntroScene::__loadTextures()
{
    std::string test = "./../Ressources/ScenesTmp/Intro.png";
    IntroTexture var = IntroTexture::BackGround;
    _textures.add(var._to_string(), test);
}

void IntroScene::__loadSprites()
{
    IntroSprites var = IntroSprites::BackGround;
    IntroTexture tmp = IntroTexture::BackGround;
    _sprite.add(var._to_string(), _textures[tmp._to_string()]);
}

void IntroScene::__unload()
{
    _textures.clear();
    _sprite.clear();
}
