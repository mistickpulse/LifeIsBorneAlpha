//
// Created by zouz on 01/02/18.
//

#ifndef LIFEISBORNE_RAWINPUTCONSTANT_HPP
#define LIFEISBORNE_RAWINPUTCONSTANT_HPP

#include <vector>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Joystick.hpp>

namespace Inputs
{
    using RawInputKeyboardButton =  sf::Keyboard::Key;

    enum RawInputControllerButton
    {
        CROSS,
        CIRCLE,
        TRIANGLE,
        SQUARE,
        L1,
        R1,
        L2,
        R2,
        SHARE,
        OPTIONS,
        CENTRAL_BUTTON,
    };

    using sfAxis = sf::Joystick::Axis;
    enum RawInputAxis
    {
        LEFT_X = sfAxis::X,
        LEFT_Y = sfAxis::Y,
        LEFT_CLIC = sfAxis::Z,

        RIGHT_X = sfAxis::U,
        RIGHT_Y = sfAxis::V,
        RIGHT_CLIC = sfAxis::R,

        CROSS_X = sfAxis::PovX,
        CROSS_Y = sfAxis::PovY,
        MOUSE_X,
        MOUSE_Y
    };
}

#endif //LIFEISBORNE_RAWINPUTCONSTANT_HPP
