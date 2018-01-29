//
// Created by zouz on 29/01/18.
//

#include "ControlProfile.hpp"

Inputs::ControlProfile::ControlProfile(InputMode mode, std::string ProfileName) :
    _profileName(std::move(ProfileName)), _mode(mode)
{}
