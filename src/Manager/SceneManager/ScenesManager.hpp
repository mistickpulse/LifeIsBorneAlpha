//
// Created by zouz on 27/01/18.
//

#ifndef LIFEISBORNE_SCENESMANAGER_HPP
#define LIFEISBORNE_SCENESMANAGER_HPP

#include <string>
#include <unordered_map>
#include <bits/unordered_map.h>
#include <queue>
#include <memory>
#include "../EventManager/Receiver.hpp"
#include "../EventManager/EventManager.hpp"

class AScene
{
};

using Id = unsigned int;

class SceneManager : public Receiver<SceneManager>
{
public:
    SceneManager()
    {
        EventManager &evtMgr = EventManager::getInstance();
        evtMgr.subscribe<TestEvent>(*this);
    }

    ~SceneManager() = default;

public:
    void receive([[maybe_unused]]const TestEvent &evt)
    {
        std::cout << "ZOB JE RECOIt EVENT" << std::endl;
    }

private:

    void registerScenes(Id id, AScene &scene)
    {
        _scenes.insert({id, std::make_shared<AScene>(scene)});
    }

    void changeScene(Id id)
    {
        queue.push(_scenes[id]);
    }

private:
    std::queue<std::shared_ptr<AScene>> queue;
    std::unordered_map<Id, std::shared_ptr<AScene>> _scenes;
};

#endif //LIFEISBORNE_SCENESMANAGER_HPP
