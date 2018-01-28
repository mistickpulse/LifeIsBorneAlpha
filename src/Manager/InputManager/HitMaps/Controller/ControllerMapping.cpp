//
// Created by zouz on 19/12/17.
//

#include <iostream>
#include "ControllerMapping.hpp"

ControllerMapping::ControllerMapping() :
        AControlMapping(InputControllerType::Controller) {
    _buttonToInput.fill(GameInput::None);
    _buttonToInput[ButtonBind::CROSS] = GameInput::Select;
    _buttonToInput[ButtonBind::CIRCLE] = GameInput::Back;
    _buttonToInput[ButtonBind::SQUARE] = GameInput::None;
    _buttonToInput[ButtonBind::TRIANGLE] = GameInput::None;

    /*
    _buttonToInput[ButtonBind::L1] = GameInput::None;
    _buttonToInput[ButtonBind::L2] = GameInput::None;
    _buttonToInput[ButtonBind::R1] = GameInput::None;
    _buttonToInput[ButtonBind::R2] = GameInput::None;

    _buttonToInput[ButtonBind::OPTIONS] = GameInput::None;
    _buttonToInput[ButtonBind::SHARE] = GameInput::None;

    _buttonToInput[ButtonBind::CENTRAL_BUTTON] = GameInput::None;
    _buttonToInput[ButtonBind::RIGHT_JOYSTICK_CLIC] = GameInput::None;
    _buttonToInput[ButtonBind::LEFT_JOYSTICK_CLIC] = GameInput::None;
    */

    _joysticks[JoystickPos::LEFT].x_axes.JoystickAxes = sf::Joystick::Axis::X;
    _joysticks[JoystickPos::LEFT].x_axes.pos.input = GameInput::Right;
    _joysticks[JoystickPos::LEFT].x_axes.neg.input = GameInput::Left;

    _joysticks[JoystickPos::LEFT].y_axes.JoystickAxes = sf::Joystick::Axis::Y;
    _joysticks[JoystickPos::LEFT].y_axes.pos.input = GameInput::Up;
    _joysticks[JoystickPos::LEFT].y_axes.neg.input = GameInput::Down;

    // ================================================== //

    _joysticks[JoystickPos::RIGHT].x_axes.JoystickAxes = sf::Joystick::Axis::U;
    _joysticks[JoystickPos::RIGHT].x_axes.pos.input = GameInput::None;
    _joysticks[JoystickPos::RIGHT].x_axes.neg.input = GameInput::None;

    _joysticks[JoystickPos::RIGHT].y_axes.JoystickAxes = sf::Joystick::Axis::V;
    _joysticks[JoystickPos::RIGHT].y_axes.pos.input = GameInput::None;
    _joysticks[JoystickPos::RIGHT].y_axes.neg.input = GameInput::None;

    // ================================================== //

    _joysticks[JoystickPos::ARROW_PAD].x_axes.JoystickAxes = sf::Joystick::Axis::PovX;
    _joysticks[JoystickPos::ARROW_PAD].x_axes.pos.input = GameInput::Right;
    _joysticks[JoystickPos::ARROW_PAD].x_axes.neg.input = GameInput::Left;

    _joysticks[JoystickPos::ARROW_PAD].y_axes.JoystickAxes = sf::Joystick::Axis::PovY;
    _joysticks[JoystickPos::ARROW_PAD].y_axes.pos.input = GameInput::Up;
    _joysticks[JoystickPos::ARROW_PAD].y_axes.neg.input = GameInput::Down;
}

ControllerMapping::ControllerMapping([[maybe_unused]]const std::string &ConfigFilePath) :
        AControlMapping(InputControllerType::Controller) {
}

GameInput ControllerMapping::translate(ButtonBind controllerKey) const {
    return _buttonToInput[controllerKey];
}


void ControllerMapping::setKey(ButtonBind button, GameInput bind) {
    _buttonToInput[button] = bind;
}

std::pair<GameInput, GameInput>
ControllerMapping::translateJoystick(JoystickPos selectedJoystick, unsigned int ControllerId) {
    GameInput InputXaxis = GameInput::None;
    GameInput InputYaxis = GameInput::None;

    Joystick &j = _joysticks[selectedJoystick];
    if (handleJoystickInput(j.x_axes.neg.min, j.x_axes.neg.max, ControllerId, j.x_axes.JoystickAxes)) {
        InputXaxis = j.x_axes.neg.input;
    }

    if (handleJoystickInput(j.x_axes.pos.min, j.x_axes.pos.max, ControllerId, j.x_axes.JoystickAxes)) {
        InputXaxis = j.x_axes.pos.input;
    }

    if (handleJoystickInput(j.y_axes.neg.min, j.y_axes.neg.max, ControllerId, j.y_axes.JoystickAxes)) {
        InputYaxis = j.y_axes.neg.input;
    }

    if (handleJoystickInput(j.y_axes.pos.min, j.y_axes.pos.max, ControllerId, j.y_axes.JoystickAxes)) {
        InputYaxis = j.y_axes.pos.input;
    }
    return std::pair<GameInput, GameInput>(InputXaxis, InputYaxis);
}

bool ControllerMapping::handleJoystickInput(float min, float max, unsigned int controllerId, sf::Joystick::Axis axis) {
    double val = sf::Joystick::getAxisPosition(controllerId, axis);
    if ((val > 0 && val > min && val < max) || (val < 0 && val > max && val < min)) {
        return true;
    }
    return false;
}

AxesData::AxesData(double min, double max, GameInput input) :
        min(min), max(max), input(input) {
}

