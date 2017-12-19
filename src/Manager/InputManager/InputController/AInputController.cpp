//
// Created by zouz on 19/12/17.
//

#include <algorithm>
#include <SFML/Window/Joystick.hpp>
#include "AInputController.hpp"

AInputController::AInputController(AControlMapping *controllerMapping) :
        _mapKey(controllerMapping), _controllerType(controllerMapping->getControllerType()) {

}

InputControllerType AInputController::getControllerType() const {
    return InputControllerType::Controller;
}

void AInputController::changeControllerMap(AControlMapping *controllerMapping) {
    _mapKey = controllerMapping;
}

GameInput AInputController::getLastInput() {
    GameInput ret = _inputs.front();
    _inputs.pop();
    return ret;
}

void AInputController::addInput(GameInput input) {
    _inputs.push(input);
}
