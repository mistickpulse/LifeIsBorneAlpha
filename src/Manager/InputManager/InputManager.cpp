//
// Created by zouz on 19/12/17.
//


#include <SFML/Window/Joystick.hpp>
#include "InputManager.hpp"
#include "InputController/Controller/Controller.hpp"

InputManager::InputManager() {
    __loadConfigs();
    for (unsigned int i = 0; i < maxSfmlController && controllerConnected < maxController; ++i) {
        if (sf::Joystick::isConnected(i)) {
            _controllers[controllerConnected] = new Controller(__getControllerLastMapping(), controllerConnected);
        }
    }
}

InputManager::~InputManager() {

}

void InputManager::__loadDefaultConfig() {

}

void InputManager::__loadConfigs() {
    for (int i = 0; i < maxController; ++i) {
        _controllerMappings[i] = new ControllerMapping();
    }
}

ControllerMapping *InputManager::__getControllerLastMapping() {
    for (int i = lastControllerConfigLoaded; i < maxController; ++i) {
        if (_controllerMappings[i]->getControllerType() == InputControllerType::Controller) {
            lastControllerConfigLoaded += 1;
            return static_cast<ControllerMapping *>(_controllerMappings[i]);
        }
    }
}
