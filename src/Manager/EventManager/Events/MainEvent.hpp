//
// Created by zouz on 29/01/18.
//

#ifndef LIFEISBORNE_MAINEVENT_HPP
#define LIFEISBORNE_MAINEVENT_HPP

#include "AEvent.hpp"
namespace Evt
{

    struct StopGame : public AEvent
    {
        explicit StopGame() :
            AEvent("Stopping Game")
        {}
    };
} // namespace Evt

#endif //LIFEISBORNE_MAINEVENT_HPP
