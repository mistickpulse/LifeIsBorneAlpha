//
// Created by zouz on 28/01/18.
//

#include <iostream>
#include "ArcadeScene.hpp"
#include "TextureId.hpp"

void ArcadeScene::enter()
{
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
    ArcadeSprites var = ArcadeSprites::BackGround;
    std::cout << "Before get spr" << std::endl;
    win.draw(_sprite[var._to_string()]);
}

void ArcadeScene::update([[maybe_unused]]sf::Time &elapsedTime)
{
    draw();

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
        _evtMgr.emit<Evt::ChangeScene>(Scenes::SceneType::Intro);
    }
}

void ArcadeScene::ProcessInput()
{
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
