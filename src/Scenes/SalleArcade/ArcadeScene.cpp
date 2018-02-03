//
// Created by zouz on 28/01/18.
//

#include <iostream>
#include "ArcadeScene.hpp"
#include "TextureId.hpp"

void ArcadeScene::enter()
{
    _evtMgr.emit<Evt::ChangeInputContext>(Inputs::ContextList::Game);
    _evtMgr.emit<Evt::ChangePlayerMode>(PlayerMode::TWO_PLAYER);

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

    ArcadeSprites Boris = ArcadeSprites::Boris;

    for (auto &i : _inputMgr.getPlayerInputs()) {
        _sprite[Boris._to_string()].setPosition(i->_pos.x, i->_pos.y);
        win.draw(_sprite[Boris._to_string()]);
    }
}

void ArcadeScene::update([[maybe_unused]]sf::Time &elapsedTime)
{
    ProcessInput();
    draw();
}

void ArcadeScene::ProcessInput()
{
    _inputMgr.update();
    Inputs::PlayerMappedInput &Players = _inputMgr.getPlayerInputs();

    for (auto &i : Players) {
        while (i->_action.size()) {
            GameAction act = i->_action.front();
            i->_action.pop();
            if (act == GameAction::UP) {
                i->_pos.y -= 1;
            } else if (act == GameAction::DOWN) {
                i->_pos.y += 1;
            }
            if (act == GameAction::LEFT) {
                i->_pos.x -= 1;
            } else if (act == GameAction::RIGHT) {
                i->_pos.x += 1;
            }
        }
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
    std::string boris = "./../Ressources/tmp2.png";

    ArcadeTexture var = ArcadeTexture::BackGround;
    ArcadeTexture b = ArcadeTexture::Boris;
    _textures.add(var._to_string(), test);
    _textures.add(b._to_string(), boris);
}

void ArcadeScene::__loadSprites()
{
    ArcadeSprites var = ArcadeSprites::BackGround;
    ArcadeTexture tmp = ArcadeTexture::BackGround;

    ArcadeTexture borisT = ArcadeTexture::Boris;
    ArcadeSprites borisS = ArcadeSprites::Boris;
    _sprite.add(var._to_string(), _textures[tmp._to_string()]);
    _sprite.add(borisS._to_string(), _textures[borisT._to_string()]);
}

void ArcadeScene::__unload()
{
    _textures.clear();
    _sprite.clear();
}
