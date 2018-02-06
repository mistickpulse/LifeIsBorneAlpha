//
// Created by zouz on 02/02/18.
//

#ifndef LIFEISBORNE_BINDINGCONTEXTHELPER_HPP
#define LIFEISBORNE_BINDINGCONTEXTHELPER_HPP

#include <string>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
#include <Thor/Input.hpp>
#include "../../GameAction.hpp"
#include "../../GameState.hpp"
#include "InputConstant.hpp"
#include "RawInputConstant.hpp"
#include "../../utils/Singleton.hpp"

namespace Inputs
{
    struct BindingContextHelper : public Singleton<BindingContextHelper>
    {
        struct RawKeyConverter
        {
            sf::Keyboard::Key operator[](const std::string &id)
            {
                sf::Keyboard::Key key;
                try {
                    key = thor::toKeyboardKey(id);
                } catch (const std::exception &err) {
                    std::cerr << err.what() << std::endl;
                    key = sf::Keyboard::Unknown;
                }
                return key;
            }

            sf::Keyboard::Key at(const std::string &id)
            {
                return thor::toKeyboardKey(id);
            }
        };

        RawKeyConverter rawKeyConverter;

        std::unordered_map<std::string, GameAction> ActionConverter =
            {{
                 {"ACCEPT", GameAction::ACCEPT},
                 {"REFUSE", GameAction::REFUSE},
                 {"LEFT", GameAction::LEFT},
                 {"RIGHT", GameAction::RIGHT},
                 {"UP", GameAction::UP},
                 {"DOWN", GameAction::DOWN},
                 {"SPELL1", GameAction::SPELL1},
                 {"SPELL2", GameAction::SPELL2},
                 {"SPELL3", GameAction::SPELL3},
                 {"SPELL4", GameAction::SPELL4},
                 {"ROLL", GameAction::ROLL},
                 {"STATUE", GameAction::INTERRACT},
                 {"FUSION", GameAction::FUSION},
                 {"INTERRACT", GameAction::INTERRACT},
                 {"PAUSE", GameAction::PAUSE},
                 {"QUIT", GameAction::QUIT},
             }};

        std::unordered_map<std::string, GameState> GameStateConverter =
            {{
                 {"FREE", GameState::FREE},
                 {"UNTARGETABLE", GameState::UNTARGETABLE},
                 {"UNCIBLABLE", GameState::UNCIBLABLE},
                 {"INVINCIBLE", GameState::INVINCIBLE},
                 {"STUNED", GameState::STUNED},
                 {"STUCK", GameState::STUCK},
                 {"FOLOWING", GameState::FOLOWING},
                 {"FUSIONED", GameState::FUSIONED},
                 {"UNFUSIONED", GameState::UNFUSIONED},
                 {"CASTING_SPELL", GameState::CASTING_SPELL},
                 {"FREE", GameState::FREE},
                 {"FREE", GameState::FREE},
             }};

        std::unordered_map<RawInputAxis, sf::Joystick::Axis> JoystickAxisConverter =
            {{
                 {RawInputAxis::LEFT_X, sf::Joystick::Axis::X},
                 {RawInputAxis::LEFT_Y, sf::Joystick::Axis::Y},

                 {RawInputAxis::RIGHT_X, sf::Joystick::Axis::U},
                 {RawInputAxis::RIGHT_Y, sf::Joystick::Axis::V},

                 {RawInputAxis::CROSS_X, sf::Joystick::Axis::PovX},
                 {RawInputAxis::CROSS_Y, sf::Joystick::Axis::PovY},
             }};


        std::unordered_map<std::string, GameRange> GameRangeConverter =
            {{
                 {"BASIC_MOUSE_H", GameRange::BASIC_MOUSE_H},
                 {"BASIC_MOUSE_V", GameRange::BASIC_MOUSE_V},

                 {"BASIC_JOYSTICK_H", GameRange::BASIC_JOYSTICK_H},
                 {"BASIC_JOYSTICK_V", GameRange::BASIC_JOYSTICK_V},

                 {"BASIC_CROSS_H", GameRange::BASIC_CROSS_H},
                 {"BASIC_CROSS_V", GameRange::BASIC_CROSS_V},

                 {"VIEWER_MOUSE_H", GameRange::VIEWER_MOUSE_H},
                 {"VIEWER_MOUSE_V", GameRange::VIEWER_MOUSE_V},


                 {"VIEWER_JOYSTICK_H", GameRange::VIEWER_JOYSTICK_H},
                 {"VIEWER_JOYSTICK_V", GameRange::VIEWER_JOYSTICK_V}
             }};

        std::unordered_map<std::string, RawInputAxis> RawInputAxisEnumConverter =
            {{
                 {"LEFT_X", RawInputAxis::LEFT_X},
                 {"LEFT_Y", RawInputAxis::LEFT_Y},
                 {"LEFT_CLIC", RawInputAxis::LEFT_CLIC},

                 {"RIGHT_X", RawInputAxis::RIGHT_X},
                 {"RIGHT_Y", RawInputAxis::RIGHT_Y},
                 {"RIGHT_CLIC", RawInputAxis::RIGHT_CLIC},

                 {"CROSS_X", RawInputAxis::CROSS_X},
                 {"CROSS_Y", RawInputAxis::CROSS_Y},

                 {"MOUSE_X", RawInputAxis::MOUSE_X},
                 {"MOUSE_Y", RawInputAxis::MOUSE_Y}
             }};

        std::unordered_map<std::string, RawInputControllerButton> RawInputControllerButtonConverter =
            {{
                 {"CROSS", RawInputControllerButton::CROSS},
                 {"CIRCLE", RawInputControllerButton::CIRCLE},
                 {"TRIANGLE", RawInputControllerButton::TRIANGLE},
                 {"SQUARE", RawInputControllerButton::SQUARE},

                 {"L1", RawInputControllerButton::L1},
                 {"R1", RawInputControllerButton::R1},
                 {"L2", RawInputControllerButton::L2},
                 {"R2", RawInputControllerButton::R2},

                 {"SHARE", RawInputControllerButton::SHARE},
                 {"OPTIONS", RawInputControllerButton::OPTIONS},
                 {"CENTRAL_BUTTON", RawInputControllerButton::CENTRAL_BUTTON}
             }};
    };
}

#endif //LIFEISBORNE_BINDINGCONTEXTHELPER_HPP
