//
// Created by zouz on 19/12/17.
//

#ifndef LIFEISBORNE_CONTROLLER_HPP
#define LIFEISBORNE_CONTROLLER_HPP


#include "../AInputController.hpp"
#include "../../HitMaps/Controller/ControllerMapping.hpp"
#include "../ButtonBind.hpp"

class Controller : public AInputController {
public:

public:
    Controller(ControllerMapping *hitmap, unsigned int controllerId);

    ~Controller() override = default;

public:
    void update() override;

private:
    void __handleButtonInputs();

    void __handleJoystickInput(JoystickPos selectedJ);

private:
    ControllerMapping *hitmap;
    const unsigned int _controllerId;
    const unsigned int _buttonQte;

};

#endif //LIFEISBORNE_CONTROLLER_HPP
