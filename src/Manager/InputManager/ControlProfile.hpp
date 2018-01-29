//
// Created by zouz on 29/01/18.
//

#ifndef LIFEISBORNE_CONTROLPROFILE_HPP
#define LIFEISBORNE_CONTROLPROFILE_HPP

#include <string>
#include <memory>
#include "InputMode.hpp"
#include "DirectionalInput/ADIrectionalInput.hpp"
#include "Buttons/AButton.hpp"

namespace Inputs
{

    class ControlProfile
    {
    public:
        explicit ControlProfile(InputMode mode = InputMode::GAME, std::string ProfileName = "Default");

        ~ControlProfile() = default;

    public:

    private:
        const std::string _profileName;
        InputMode _mode;

        std::vector<std::shared_ptr<ADirectionalInput>> _directionalInputs;
        std::vector<std::shared_ptr<AButton>> _buttons;
    };
}

#endif //LIFEISBORNE_CONTROLPROFILE_HPP
