//
// Created by zouz on 01/02/18.
//

#ifndef LIFEISBORNE_PARAMEVENT_HPP
#define LIFEISBORNE_PARAMEVENT_HPP

#include "AEvent.hpp"

namespace Evt
{

    struct ChangeScreenSize : public AEvent
    {
        ChangeScreenSize(int x, int y) :
            AEvent("Changing screen size"),
            size_x(x), size_y(y)
        {}

        int size_x;
        int size_y;
    };
}

#endif //LIFEISBORNE_PARAMEVENT_HPP
