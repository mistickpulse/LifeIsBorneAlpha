//
// Created by zouz on 29/01/18.
//

#ifndef LIFEISBORNE_INPUTMODE_HPP
#define LIFEISBORNE_INPUTMODE_HPP

#include <unordered_map>

namespace Inputs
{
    enum InputMode
    {
        GAME,
        MENU,
        LAST
    };

    enum InputType
    {
        KEYBOARD,
        CONTROLER
    };

    const std::unordered_map<InputMode, std::string> InputLabel =
        {{
             {InputMode::GAME, "GAME"},
             {InputMode::MENU, "MENU"}
         }};
}

#endif //LIFEISBORNE_INPUTMODE_HPP
