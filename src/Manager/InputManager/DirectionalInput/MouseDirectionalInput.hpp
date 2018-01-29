//
// Created by zouz on 29/01/18.
//

#ifndef LIFEISBORNE_MOUSEDIRECTIONALINPUT_HPP
#define LIFEISBORNE_MOUSEDIRECTIONALINPUT_HPP

#include <SFML/System.hpp>
#include <SFML/Window/Mouse.hpp>
#include <complex>
#include "../PlayerInput.hpp"
#include "ADIrectionalInput.hpp"

namespace Inputs
{

    class MouseDirectionalInput : public ADirectionalInput
    {
    public:
        MouseDirectionalInput(PlayerInput *ref) :
            ADirectionalInput(ref)
        {}

        ~MouseDirectionalInput() = default;

    public:

        void process() noexcept override final
        {
            sf::Vector2i pos = sf::Mouse::getPosition();
            int Posx = pos.x;
            int Posy = pos.y;
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
    };
}

#endif //LIFEISBORNE_MOUSEDIRECTIONALINPUT_HPP
