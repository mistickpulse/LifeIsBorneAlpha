//
// Created by zouz on 29/01/18.
//

#ifndef LIFEISBORNE_PLAYERINPUT_HPP
#define LIFEISBORNE_PLAYERINPUT_HPP

#include <queue>
#include "../../utils/Position.hpp"
#include "GameInput.hpp"
#include "InputMode.hpp"

namespace Inputs
{
    namespace
    {
        const int viewDistance = 30;
    }

    struct PlayerInput
    {
        PlayerInput() :
            ViewDistance(viewDistance)
        {}

        const unsigned int ViewDistance;
        Position playerPos;
        Position Viewer;
        Position mousePos;
        InputMode mode;
        std::queue<GameInput> _inputs;

        void addInput(const GameInput i)
        {
            _inputs.push(i);
        }
    };
}

#endif //LIFEISBORNE_PLAYERINPUT_HPP
