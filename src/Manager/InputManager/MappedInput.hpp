//
// Created by zouz on 02/02/18.
//

#ifndef LIFEISBORNE_MAPPEDINPUT_HPP
#define LIFEISBORNE_MAPPEDINPUT_HPP

#include <queue>
#include "../../GameAction.hpp"

struct MappedInput
{
    std::queue<GameAction> _action;
    char ControllerId{-1}; // if == -1 -> Mouse + Keyboard, otherWise -> Only Controller;

};

#endif //LIFEISBORNE_MAPPEDINPUT_HPP
