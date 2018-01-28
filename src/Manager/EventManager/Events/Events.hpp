//
// Created by zouz on 28/01/18.
//

#ifndef LIFEISBORNE_EVENTS_HPP
#define LIFEISBORNE_EVENTS_HPP

#include "AEvent.hpp"
#include "../../../Scenes/SceneList.hpp"

namespace Evt
{

    struct ChangeScene : public AEvent
    {
        explicit ChangeScene(Scenes::SceneType type) : AEvent(std::string("Change Scene to ->") + type._to_string()),
                                                       sceneId(type)
        {
        }

        const Scenes::SceneType sceneId;
    };

    struct StopGame : public AEvent
    {
        explicit StopGame() :
            AEvent("Stopping Game")
        {}
    };

    struct PauseGame : public AEvent
    {
        explicit PauseGame() :
            AEvent("Pausing Game")
        {}
    };
}

#endif //LIFEISBORNE_EVENTS_HPP
