//
// Created by zouz on 28/01/18.
//

#include <iostream>
#include "ScenesManager.hpp"
#include "../../Scenes/SalleArcade/ArcadeScene.hpp"
#include "../../Scenes/Intro/IntroScene.hpp"

void SceneManager::receive(const Evt::ChangeScene &ev)
{
    std::cout << "Receiving :" << ev << std::endl;
    changeScene(ev.sceneId);
}

SceneManager::SceneManager(sf::RenderWindow &win) :
    win(win)
{
    Evt::EventManager &evtMgr = Evt::EventManager::getInstance();
    evtMgr.subscribe<Evt::ChangeScene>(*this);
    __registerAllScenes();
}

void SceneManager::changeScene(Id id)
{
    __popAll();
    __addScene(id);
}

void SceneManager::update(sf::Time &elapsedTime)
{
    if (_sceneQueue.size()) {
        std::cout << "Processing scene:" << _sceneQueue.front()->getName() << std::endl;
        _sceneQueue.front()->update(elapsedTime);
    }
}

void SceneManager::__popAll()
{
    while (_sceneQueue.size()) {
        __leaveFirstScene();
    }
}

void SceneManager::__addScene(Id id)
{
    _sceneQueue.push(_scenes.at(id._to_string()));
    _sceneQueue.front()->enter();
}

void SceneManager::__leaveFirstScene()
{
    if (_sceneQueue.size()) {
        _sceneQueue.front()->leave();
        _sceneQueue.pop();
    }
}

void SceneManager::receive([[maybe_unused]]const Evt::PauseGame &ev)
{
    _sceneQueue.front()->pause();
}

template <typename SceneType>
void SceneManager::registerScenes(Id id, SceneType &scene)
{
    _scenes.insert({id._to_string(), new SceneType(scene)});
}

template <typename SceneType>
void SceneManager::registerScenes(Id id, SceneType *scene)
{
    _scenes.insert({id._to_string(), scene});
}

SceneManager::~SceneManager()
{
    std::for_each(begin(_scenes), end(_scenes), [](auto &&pair) {
        delete pair.second;
    });
}

void SceneManager::__registerAllScenes()
{
    registerScenes<IntroScene>(Scenes::SceneType::Intro, new IntroScene(win));
    registerScenes<ArcadeScene>(Scenes::SceneType::SalleArcade, new ArcadeScene(win));
}

