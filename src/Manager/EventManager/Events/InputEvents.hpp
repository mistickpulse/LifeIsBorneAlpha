//
// Created by zouz on 29/01/18.
//

#ifndef LIFEISBORNE_INPUTEVENTS_HPP
#define LIFEISBORNE_INPUTEVENTS_HPP

#include "AEvent.hpp"
#include "../../InputManager/InputManager.hpp"
#include "../../InputManager/InputMode.hpp"

namespace Evt
{
    struct AddPlayer : public AEvent
    {
        explicit AddPlayer(uint8_t Qte) :
            AEvent("Adding a player"), qte(Qte)
        {}

        const uint8_t qte;
    };

    struct RemovePlayer : public AEvent
    {
        explicit RemovePlayer(uint8_t Qte) :
            AEvent("Removing a player"), qte(Qte)
        {}

        const uint8_t qte;
    };

    struct ChangeControlMode : public AEvent
    {
        explicit ChangeControlMode(Inputs::InputMode m) :
            AEvent("Changing Control Mode"), mode(m)
        {}

        Inputs::InputMode mode;
    };
}

#endif //LIFEISBORNE_INPUTEVENTS_HPP
