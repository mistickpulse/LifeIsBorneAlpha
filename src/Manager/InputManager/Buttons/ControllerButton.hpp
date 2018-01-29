//
// Created by zouz on 29/01/18.
//

#ifndef LIFEISBORNE_CONTROLLERBUTTON_HPP
#define LIFEISBORNE_CONTROLLERBUTTON_HPP

#include <SFML/Window/Joystick.hpp>
#include "../GameInput.hpp"
#include "AButton.hpp"

class ControllerButton final : public AButton
{
public:
    ControllerButton(uint8_t JoystickId, uint8_t ButtonId, GameInput processResult) :
        AButton(), _joystickId(JoystickId), _buttonId(ButtonId), _result(processResult)
    {}

    ~ControllerButton() final = default;

    GameInput process() const override
    {
        if (sf::Joystick::isButtonPressed(_joystickId, _buttonId)) {
            return _result;
        }
        return GameInput::NONE;
    }

private:
    const int _joystickId;
    const int _buttonId;
    const GameInput _result;
};

#endif //LIFEISBORNE_CONTROLLERBUTTON_HPP
