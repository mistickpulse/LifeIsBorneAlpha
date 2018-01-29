//
// Created by zouz on 29/01/18.
//

#include "ControlerProfileManager.hpp"

Inputs::ControlProfile &Inputs::ControlerProfilManager::getProfile(const std::string &profileName, InputMode mode)
{
    return _profiles[profileName][mode].second;
}
