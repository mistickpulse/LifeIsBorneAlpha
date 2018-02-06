//
// Created by zouz on 05/02/18.
//

#include <SFML/Graphics/Text.hpp>
#include "TestScene.hpp"

void TestScene::enter()
{

    _profile.size_y = 1080;
    _profile.size_x = 1920;
    _profile.MinimumSizeRoomX = _profile.size_x / 12;
    _profile.MinimumSizeRoomY = _profile.size_y / 12;

    _profile.MaxRandomTry = 200;

    _profile.mode = gen::RoomGenerationMode::Normal;
    Iteration = 42;
    _dungeon.create(_profile, Iteration);
}

void TestScene::leave()
{
}

void TestScene::pause()
{
}

void TestScene::resume()
{
}

void TestScene::draw()
{
}

void TestScene::update(sf::Time &elapsedTime)
{
    win.clear(sf::Color::Black);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
        _dungeon.create(_profile, Iteration);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        Iteration--;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        Iteration++;
    }
    sf::Text t;
    t.setString(std::to_string(Iteration));
    t.setPosition(10.0f, 10.0f);
    t.setColor(sf::Color::Red);
    win.draw(t);
    win << _dungeon;
}

void TestScene::ProcessInput()
{
}

void TestScene::__load()
{
}

void TestScene::__unload()
{
}

void TestScene::__loadTextures()
{
}

void TestScene::__loadSprites()
{
}

TestScene::TestScene(sf::RenderWindow &win) :
    AScene(win, "Test Scene"), _iptMgr(Inputs::InputManager::getInstance())
{
}


