//
// Created by zouz on 29/01/18.
//

#ifndef LIFEISBORNE_ABUTTON_HPP
#define LIFEISBORNE_ABUTTON_HPP

#include "../GameInput.hpp"

namespace Inputs
{

    class AButton
    {
    public:
        AButton() = default;
        virtual ~AButton() = default;

    public:
        virtual GameInput process() const = 0;
    };
}

#endif //LIFEISBORNE_ABUTTON_HPP
