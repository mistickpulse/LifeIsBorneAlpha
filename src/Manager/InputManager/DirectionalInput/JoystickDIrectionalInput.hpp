//
// Created by zouz on 29/01/18.
//

#ifndef LIFEISBORNE_VECTORDIRECTIONALINPUT_HPP
#define LIFEISBORNE_VECTORDIRECTIONALINPUT_HPP

#include <functional>
#include <complex>
#include "../PlayerInput.hpp"
#include "ADIrectionalInput.hpp"
#include "JoystickPos.hpp"

namespace Inputs
{

    class JoystickDirectionalInput final : public ADirectionalInput
    {
    public:
        JoystickDirectionalInput(PlayerInput *ref, uint8_t ControllerId, JoystickPos pos) :
            ADirectionalInput(ref), _controllerId(ControllerId), _jpos(pos)
        {}

        ~JoystickDirectionalInput() final = default;

        void process() noexcept override final
        {
            int Posx = static_cast<int>(sf::Joystick::getAxisPosition(_controllerId, JoystickAxis[_jpos].first)) +
                       _playerInfo->playerPos.x;
            int Posy = static_cast<int>(sf::Joystick::getAxisPosition(_controllerId, JoystickAxis[_jpos].second)) +
                       _playerInfo->playerPos.y;
            double FirstOperand = std::sqrt(
                (std::pow(_playerInfo->playerPos.x, 2) + std::pow(_playerInfo->playerPos.y, 2)));
            double SecondOperand = std::sqrt((std::pow(Posx, 2) + std::pow(Posy, 2)));
            double res =
                (_playerInfo->playerPos.x * Posx + _playerInfo->playerPos.y * Posy) / (FirstOperand * SecondOperand);
            double angle = std::acos(res);
            //if (Posy < 0) { // A Verifier
            //    angle += M_PI;
            //}
            _playerInfo->Viewer.x = static_cast<int>(_playerInfo->playerPos.x +
                                                     _playerInfo->ViewDistance * std::cos(angle));
            _playerInfo->Viewer.y = static_cast<int>(_playerInfo->playerPos.y +
                                                     _playerInfo->ViewDistance * std::sin(angle));
        }

    public:

        const uint8_t _controllerId;
        const JoystickPos _jpos;
    };
}

#endif //LIFEISBORNE_VECTORDIRECTIONALINPUT_HPP
