//
// Created by zouz on 29/01/18.
//

#ifndef LIFEISBORNE_CONTROLLER_HPP
#define LIFEISBORNE_CONTROLLER_HPP

#include "Buttons/AButton.hpp"
#include "PlayerInput.hpp"
#include "DirectionalInput/ADIrectionalInput.hpp"
#include "ControlProfile.hpp"

namespace Inputs
{

    class Controller
    {
    public:
        explicit Controller(PlayerInput *playerInput) :
            _profileName(""),
            _playerInput(playerInput),
            _mode(playerInput->mode)
        {
        }

        Controller(PlayerInput *playerInput, const std::string profileName) :
            _profileName(std::move(profileName)), _playerInput(playerInput)
        {}

        ~Controller() = default;

    public:
        void changePlayerBind(PlayerInput *newPlayer)
        {
            _playerInput = newPlayer;
        }

        bool loadConf([[maybe_unused]]const std::string &Profile)
        {
            return false;
        }

        void ChangeConf([[maybe_unused]]const ControlProfile &profile)
        {
        }

        void process()
        {
            for (auto i : _directionalInputs) {
                i->process();
            }
            for (auto i : _buttons) {
                i->process();
            }
        }

    private:
        std::vector<std::shared_ptr<ADirectionalInput>> _directionalInputs;
        std::vector<std::shared_ptr<AButton>> _buttons;

    private:
        std::string _profileName{""};
        PlayerInput *_playerInput;
        InputMode _mode;
    };
}

#endif //LIFEISBORNE_CONTROLLER_HPP
