//
// Created by zouz on 19/12/17.
//

#include <SFML/Window/Joystick.hpp>
#include "Controller.hpp"


Controller::Controller(ControllerMapping *hitmap, unsigned int controllerId) :
        AInputController(hitmap), hitmap(hitmap), _controllerId(controllerId),
        _buttonQte(sf::Joystick::getButtonCount(controllerId)) {
    if (hitmap == nullptr)
        throw std::runtime_error("Bad Controller Mapping");
}

void Controller::update() {
    if (!sf::Joystick::isConnected(_controllerId)) {
        throw std::runtime_error("Disconnected Joystick");
    }
    __handleButtonInputs();
    __handleJoystickInput(JoystickPos::LEFT);
    __handleJoystickInput(JoystickPos::ARROW_PAD);
    __handleJoystickInput(JoystickPos::RIGHT);
}

void Controller::__handleButtonInputs() {
    for (unsigned int i = 0; i < _buttonQte; ++i) {
        if (sf::Joystick::isButtonPressed(_controllerId, i)) {
            GameInput res = hitmap->translate(static_cast<ButtonBind >(i));
            if (res != GameInput::None)
                addInput(res);
        }
    }
}

void Controller::__handleJoystickInput(JoystickPos selectedJ) {
    std::pair<GameInput, GameInput> ret(hitmap->translateJoystick(selectedJ, _controllerId));

    if (ret.first != GameInput::None) {
        addInput(ret.first);
    }
    if (ret.second != GameInput::None) {
        addInput(ret.second);
    }
}

