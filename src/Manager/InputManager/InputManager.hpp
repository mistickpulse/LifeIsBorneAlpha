//
// Created by zouz on 19/12/17.
//

#ifndef LIFEISBORNE_INPUTMANAGER_HPP
#define LIFEISBORNE_INPUTMANAGER_HPP

#include <queue>
#include <array>
#include "InputController/AInputController.hpp"
#include "HitMaps/Controller/ControllerMapping.hpp"

namespace {
    const unsigned int maxController = 3; // start to 0
    const unsigned int maxSfmlController = 7;
}

class InputManager {
public:
    InputManager();

    ~InputManager();

    void update();
private:
    void __loadDefaultConfig();

    void __loadConfigs();

    ControllerMapping *__getControllerLastMapping();

private:
    unsigned int _controllerConnected{0};
    unsigned int _lastControllerConfigLoaded{0};
private:
    std::array<AInputController *, maxController> _controllers;
    std::array<AControlMapping *, maxController> _controllerMappings;
};

#endif //LIFEISBORNE_INPUTMANAGER_HPP
