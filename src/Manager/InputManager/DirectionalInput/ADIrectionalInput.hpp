//
// Created by zouz on 29/01/18.
//

#ifndef LIFEISBORNE_ADIRECTIONALINPUT_HPP
#define LIFEISBORNE_ADIRECTIONALINPUT_HPP

#include "../PlayerInput.hpp"

namespace Inputs
{
    class ADirectionalInput
    {
    public:
        ADirectionalInput(PlayerInput *playerInfo) :
            _playerInfo(playerInfo)
        {}

        virtual ~ADirectionalInput() = default;

    public:
        virtual void process() = 0;

    protected:

        PlayerInput *_playerInfo;
    };
}

#endif //LIFEISBORNE_ADIRECTIONALINPUT_HPP
