//
// Created by zouz on 19/12/17.
//

#ifndef LIFEISBORNE_CONTROLLERMAPPING_HPP
#define LIFEISBORNE_CONTROLLERMAPPING_HPP

#include <array>
#include <SFML/Window/Joystick.hpp>
#include "../AControlMapping.hpp"
#include "../../InputController/ButtonBind.hpp"

struct AxesData {
    AxesData(double min, double max, GameInput input);

    double min;
    double max;
    GameInput input;
};

struct Axes {
    sf::Joystick::Axis JoystickAxes;
    AxesData pos{0.01, 101, GameInput::None};
    AxesData neg{-0.1, -101, GameInput::None};
};

struct Joystick {
    Axes y_axes;
    Axes x_axes;
};

enum JoystickPos {
    LEFT,
    RIGHT,
    ARROW_PAD
};

class ControllerMapping : public AControlMapping {
public:
    ControllerMapping();

    explicit ControllerMapping(const std::string &ConfigFilePath);

    ~ControllerMapping() override = default;

    void setKey(ButtonBind button, GameInput input);

    GameInput translate(ButtonBind controllerKey) const;

    std::pair<GameInput, GameInput> translateJoystick(JoystickPos selectedJoystick, unsigned int ControllerId);

private:
    bool handleJoystickInput(float min, float max, unsigned int controllerId, sf::Joystick::Axis axis);

private:
    std::array<GameInput, 13> _buttonToInput;
    std::array<Joystick, 3> _joysticks;
};

//joystick = 2 axes;
// axes = (2 valeurs + Input) * 2;

#endif //LIFEISBORNE_CONTROLLERMAPPING_HPP
