//
// Created by zouz on 28/01/18.
//

#include <iostream>
#include "ArcadeScene.hpp"
#include "TextureId.hpp"

void ArcadeScene::enter()
{
    _evtMgr.emit<Evt::ChangeInputContext>(Inputs::ContextList::Game);
    _evtMgr.emit<Evt::ChangePlayerMode>(PlayerMode::FOUR_PLAYER);

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

    ArcadeSprites Boris = ArcadeSprites::Boris;
    ArcadeSprites var = ArcadeSprites::BackGround;
    win.draw(_sprite[var._to_string()]);

    unsigned int _playerQte = _inputMgr.getPlayerQte();
    auto &PlayersInput = _inputMgr.getPlayerInputs();

    for (unsigned int CPlayerId = 0; CPlayerId < _playerQte && CPlayerId < PlayersInput.size(); ++CPlayerId) {
        auto &mi = *PlayersInput[CPlayerId];
        _sprite[Boris._to_string()].setPosition(mi._pos.x, mi._pos.y);
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
    Inputs::PlayerMappedInput &PlayersInput = _inputMgr.getPlayerInputs();
    unsigned int _playerQte = _inputMgr.getPlayerQte();

    //TMP
    for (unsigned int CPlayerId = 0; CPlayerId < _playerQte && CPlayerId < PlayersInput.size(); ++CPlayerId) {
        Inputs::MappedInput &mi = *PlayersInput[CPlayerId];
        while (mi._action.size()) {
            GameAction act = mi._action.front();
            mi._action.pop();
            if (act == GameAction::UP) {
                mi._pos.y -= 0.2;
            } else if (act == GameAction::DOWN) {
                mi._pos.y += 0.2;
            }
            if (act == GameAction::LEFT) {
                mi._pos.x -= 0.2;
            } else if (act == GameAction::RIGHT) {
                mi._pos.x += 0.2;
            }
        }
    }
}

ArcadeScene::ArcadeScene(sf::RenderWindow &win) :
    AScene(win, "Arcade")
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
