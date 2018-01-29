//
// Created by zouz on 29/01/18.
//

#ifndef LIFEISBORNE_JOYSTICKPOS_HPP
#define LIFEISBORNE_JOYSTICKPOS_HPP

#include <utility>
#include <array>
#include <SFML/Window/Joystick.hpp>

namespace Inputs
{

    enum JoystickPos
    {
        LEFT,
        RIGHT,
        ARROW_PAD
    };

    using AxisPair = std::pair<sf::Joystick::Axis, sf::Joystick::Axis>;

    namespace
    {
        constexpr std::array<AxisPair, 3> JoystickAxis =
            {{
                 {sf::Joystick::Axis::X, sf::Joystick::Axis::Y},
                 {sf::Joystick::Axis::U, sf::Joystick::Axis::V},
                 {sf::Joystick::Axis::PovX, sf::Joystick::Axis::PovY}
             }};
    }
}
#endif //LIFEISBORNE_JOYSTICKPOS_HPP
