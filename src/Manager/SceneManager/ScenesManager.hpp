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
#include "../EventManager/EventManager.hpp"
#include "AScene.hpp"
#include "../../Scenes/ForwardScene.hpp"
#include "../../Scenes/SceneList.hpp"
#include "../EventManager/Events/EventList.hpp"

using Id = Scenes::SceneType;
using StorageKey = std::string;

class SceneManager
{
public:
    explicit SceneManager(sf::RenderWindow &win);
    ~SceneManager();

public:

    void update(sf::Time &elapsedTime);

    template <typename SceneType>
    void registerScenes(Id id, SceneType &scene);

    template <typename SceneType>
    void registerScenes(Id id, SceneType *scene);

    void changeScene(Id id);


    //Event receiver
public:

    void receive(const Evt::ChangeScene &ev);
    void receive(const Evt::PauseGame &ev);


private:

    void __registerAllScenes();

    void __leaveFirstScene();
    void __addScene(Id id);

    void __popAll();

private:
    sf::RenderWindow &win;
    std::queue<AScene *> _sceneQueue;
    std::unordered_map<StorageKey, AScene *> _scenes;
};

#endif //LIFEISBORNE_SCENESMANAGER_HPP
