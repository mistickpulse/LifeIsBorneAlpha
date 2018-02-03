//
// Created by zouz on 28/01/18.
//

#include <iostream>
#include "ArcadeScene.hpp"
#include "TextureId.hpp"

void ArcadeScene::enter()
{
    _evtMgr.emit<Evt::ChangeInputContext>(Inputs::ContextList::Game);
    std::cout << "entering Scene:" << _name << std::endl;
    win.clear(sf::Color::Black);
    __load();
}

void ArcadeScene::leave()
{
    __unload();
}

void ArcadeScene::pause()
{
}

void ArcadeScene::resume()
{
}

void ArcadeScene::draw()
{
    win.clear(sf::Color::Black);
    ArcadeSprites var = ArcadeSprites::BackGround;
    win.draw(_sprite[var._to_string()]);
}

void ArcadeScene::update([[maybe_unused]]sf::Time &elapsedTime)
{
    draw();
    ProcessInput();
}

void ArcadeScene::ProcessInput()
{
    _inputMgr.update();
    Inputs::PlayerMappedInput &Players = _inputMgr.getPlayerInputs();
    ArcadeSprites var = ArcadeSprites::BackGround;
    auto pos = _sprite[var._to_string()].getPosition();
    while (Players[0]->_action.size()) {
        GameAction act = Players[0]->_action.front();
        if (act == GameAction::UP) {
            pos.y -= 1;
        } else if (act == GameAction::DOWN) {
            pos.y += 1;
        } else if (act == GameAction::LEFT) {
            pos.x -= 1;
        } else if (act == GameAction::RIGHT) {
            pos.x += 1;
        }
        _sprite[var._to_string()].setPosition(pos);
        Players[0]->_action.pop();
    }
}

ArcadeScene::ArcadeScene(sf::RenderWindow &win) :
    AScene(win, "Arcade Scene")
{}

void ArcadeScene::__load()
{
    __loadTextures();
    __loadSprites();
}

void ArcadeScene::__loadTextures()
{
    std::string test = "./../Ressources/ScenesTmp/Menu.png";
    ArcadeTexture var = ArcadeTexture::BackGround;
    _textures.add(var._to_string(), test);
}

void ArcadeScene::__loadSprites()
{
    ArcadeSprites var = ArcadeSprites::BackGround;
    ArcadeTexture tmp = ArcadeTexture::BackGround;
    _sprite.add(var._to_string(), _textures[tmp._to_string()]);
}

void ArcadeScene::__unload()
{
    _textures.clear();
    _sprite.clear();
}
