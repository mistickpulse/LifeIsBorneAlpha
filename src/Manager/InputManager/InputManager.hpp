//
// Created by zouz on 19/12/17.
//

#ifndef LIFEISBORNE_INPUTMANAGER_HPP
#define LIFEISBORNE_INPUTMANAGER_HPP

#include <queue>
#include <array>
#include <unordered_map>
#include <map>
#include "../../utils/Singleton.hpp"
#include "../EventManager/Events/EventList.hpp"

namespace Inputs
{
    namespace
    {
        const unsigned int maxController = 3; // start to 0
        const unsigned int maxSfmlController = 7;
    }

    class InputManager : public Singleton<InputManager>
    {
    public:
        InputManager();

        ~InputManager() override;

        void __load();
    };
}

#endif //LIFEISBORNE_INPUTMANAGER_HPP
