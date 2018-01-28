//
// Created by zouz on 19/12/17.
//


#include <SFML/Window/Joystick.hpp>
#include <iostream>
#include "InputManager.hpp"
#include "InputController/Controller/Controller.hpp"


InputManager::InputManager() {
    __loadConfigs();
    for (unsigned int i = 0; i < maxSfmlController && _controllerConnected < maxController; ++i) {
        if (sf::Joystick::isConnected(i)) {
            _controllers[_controllerConnected] = new Controller(
                static_cast<ControllerMapping *>(_controllerMappings[_controllerConnected]), _controllerConnected);
            _controllerConnected += 1;
            std::cout << "Loading controller : id[" << i << "] Button["
                      << sf::Joystick::getButtonCount(_controllerConnected - 1) << std::endl;
            std::cout << "Controllers connected :[" << _controllerConnected << "]" << std::endl;
        }
    }
}

InputManager::~InputManager() {
    for (unsigned int i = 0; i < _controllerConnected; ++i) {
        delete _controllers[i];
    }
    for (unsigned int i = 0; i < maxController; ++i) {
        delete _controllerMappings[i];
    }
}

void InputManager::__loadDefaultConfig() {

}

void InputManager::__loadConfigs() {
    _controllerMappings.fill(nullptr);
    for (unsigned int i = 0; i < maxController; ++i) {
        _controllerMappings[i] = new ControllerMapping();
    }
}

ControllerMapping *InputManager::__getControllerLastMapping() {
    for (unsigned int i = _lastControllerConfigLoaded; i < maxController; ++i) {
        if (_controllerMappings[i]->getControllerType() == InputControllerType::Controller) {
            _lastControllerConfigLoaded += 1;
            return static_cast<ControllerMapping *>(_controllerMappings[i]);
        }
    }
    return nullptr;
}

void InputManager::update() {
    //std::cerr << "==================" << std::endl;
    for (unsigned int i = 0; i < _controllerConnected; ++i) {
        _controllers[i]->update();
    }
}
