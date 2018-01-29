//
// Created by zouz on 29/01/18.
//

#ifndef LIFEISBORNE_GAMEDIRECTIONALINPUT_HPP
#define LIFEISBORNE_GAMEDIRECTIONALINPUT_HPP

#include "ADIrectionalInput.hpp"
#include "JoystickPos.hpp"
#include "../../../utils/Interval.hpp"

namespace Inputs
{

    enum ARROW_POS
    {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };

    using ArrowInputPair = std::pair<ARROW_POS, GameInput>;
    struct DirectionalInputConf
    {
        std::array<ArrowInputPair, 4> conf;
        const uint8_t ControllerId;
        const JoystickPos jpos;
    };

    class GameDirectionalInput : public ADirectionalInput
    {

    public:
        GameDirectionalInput(PlayerInput *playerInfo, const DirectionalInputConf &conf) :
            ADirectionalInput(playerInfo), _controllerId(conf.ControllerId), _jpos(conf.jpos), _conf(conf.conf)
        {
        }

        ~GameDirectionalInput();

    public:

        void process() noexcept override final
        {

            double x = sf::Joystick::getAxisPosition(_controllerId, JoystickAxis[_jpos].first);
            double y = sf::Joystick::getAxisPosition(_controllerId, JoystickAxis[_jpos].second);

            if (_intervalBinding[0].test(x)) {
                __pushInput(ARROW_POS::LEFT);
            } else if (_intervalBinding[1].test(x)) {
                __pushInput(ARROW_POS::RIGHT);
            }

            if (_intervalBinding[0].test(y)) {
                __pushInput(ARROW_POS::UP);
            } else if (_intervalBinding[1].test(y)) {
                __pushInput(ARROW_POS::DOWN);
            }
        }

    private:
        void __pushInput(ARROW_POS toTranslate)
        {
            for (const auto i : _conf) {
                if (i.first == toTranslate) {
                    if (i.second != GameInput::NONE) {
                        _playerInfo->addInput(i.second);
                    }
                    break;
                }
            }
        }

    private:
        const uint8_t _controllerId;
        const JoystickPos _jpos;
        std::array<ArrowInputPair, 4> _conf;
        constexpr std::array<Interval<double>, 2> _intervalBinding = //(Init Sfml Joystick Value range wich goes for x & y to [-100, 100])
            {{
                 {-101, 0},
                 {0, 101},
             }};
    };
}

#endif //LIFEISBORNE_GAMEDIRECTIONALINPUT_HPP
