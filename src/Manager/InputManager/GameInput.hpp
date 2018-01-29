//
// Created by zouz on 28/01/18.
//

#ifndef LIFEISBORNE_INPUTTYPE_HPP
#define LIFEISBORNE_INPUTTYPE_HPP

#include "../../../Lib/better-enums/enum.h"

namespace Inputs
{

    BETTER_ENUM(GameInput, int,
                NONE,
                ACCEPT,
                REFUSE,
                UP,
                DOWN,
                LEFT,
                RIGHT,

                INTERACT,
                ROLL,
                STATUE,
                SPELL1,
                SPELL2,
                SPELL3,
                SPELL4,
                FUSION
    )
}

#endif //LIFEISBORNE_INPUTTYPE_HPP
