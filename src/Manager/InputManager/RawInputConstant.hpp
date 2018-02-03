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

    enum RawInputAxis
    {
        LEFT_X,
        LEFT_Y,
        LEFT_CLIC,

        RIGHT_X,
        RIGHT_Y,
        RIGHT_CLIC,

        CROSS_X,
        CROSS_Y,

        MOUSE_X,
        MOUSE_Y
    };
}

#endif //LIFEISBORNE_RAWINPUTCONSTANT_HPP
