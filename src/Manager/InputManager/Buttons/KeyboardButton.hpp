//
// Created by zouz on 29/01/18.
//

#ifndef LIFEISBORNE_KEYBOARDBUTTON_HPP
#define LIFEISBORNE_KEYBOARDBUTTON_HPP

#include <SFML/Window/Keyboard.hpp>
#include "../GameInput.hpp"
#include "AButton.hpp"

class KeyboardButton final : public AButton
{
public:

    KeyboardButton(sf::Keyboard::Key key, GameInput processResult) :
        AButton(), _key(key), _result(processResult)
    {}

    ~KeyboardButton() final = default;

public:

    GameInput process() const override
    {
        return GameInput::NONE;
    }

private:
    const sf::Keyboard::Key _key;
    const GameInput _result;
};

#endif //LIFEISBORNE_KEYBOARDBUTTON_HPP
