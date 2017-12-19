//
// Created by zouz on 19/12/17.
//

#ifndef LIFEISBORNE_INPUTMANAGER_HPP
#define LIFEISBORNE_INPUTMANAGER_HPP

#include <queue>
#include <array>
#include "InputController/AInputController.hpp"

namespace {
    const unsigned int maxController = 3; // start to 0
}

class InputManager {
public:
    InputManager() = default;

    ~InputManager() = default;

private:
    void _loadDefaultConfig() = default;

private:
    int controllerConnected{0};
    std::array<AInputController, maxController> controllers;
};

#endif //LIFEISBORNE_INPUTMANAGER_HPP
