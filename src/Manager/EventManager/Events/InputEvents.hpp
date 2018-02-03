//
// Created by zouz on 29/01/18.
//

#ifndef LIFEISBORNE_INPUTEVENTS_HPP
#define LIFEISBORNE_INPUTEVENTS_HPP

#include "AEvent.hpp"
#include "../../InputManager/Context/ContextList.hpp"
#include "../../../PlayerMode.hpp"

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

    struct ChangeInputContext : public AEvent
    {
        explicit ChangeInputContext(Inputs::ContextList _ctx) :
            AEvent("Changin Input Context"), ctx(_ctx)
        {}

        Inputs::ContextList ctx;
    };

    struct ChangePlayerMode : public AEvent
    {
        explicit ChangePlayerMode(PlayerMode mode) :
            AEvent("Changing Player Mode"), _mode(mode)
        {}

        PlayerMode _mode;
    };

    struct DisconectedJoystick : public AEvent
    {
        explicit DisconectedJoystick(int PlayerId) :
            AEvent("Disconected Joystick"), _playerId(PlayerId)
        {
        }

        int _playerId;
    };
}

#endif //LIFEISBORNE_INPUTEVENTS_HPP
