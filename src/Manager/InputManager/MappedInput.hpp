//
// Created by zouz on 02/02/18.
//

#ifndef LIFEISBORNE_MAPPEDINPUT_HPP
#define LIFEISBORNE_MAPPEDINPUT_HPP

#include <queue>
#include "../../GameAction.hpp"
#include "../../utils/Position.hpp"
#include "RawInputConstant.hpp"

namespace Inputs
{

    struct MappedInput
    {
        std::queue<GameAction> _action;
        Position _pos;
        std::vector<RawInputAxis> *_axis;
        char ControllerId{-1}; // if == -1 -> Mouse + Keyboard, otherWise -> Only Controller;
        friend std::ostream &operator<<(std::ostream &stream, const Inputs::MappedInput &mi);
    };

    std::ostream &operator<<(std::ostream &stream, const Inputs::MappedInput &mi);
}


#endif //LIFEISBORNE_MAPPEDINPUT_HPP
