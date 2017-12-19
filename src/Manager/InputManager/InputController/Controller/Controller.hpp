//
// Created by zouz on 19/12/17.
//

#ifndef LIFEISBORNE_CONTROLLER_HPP
#define LIFEISBORNE_CONTROLLER_HPP

#include "../AInputController.hpp"
#include "../../HitMaps/Controller/ControllerMapping.hpp"

class Controller : public AInputController {
public:
    Controller(ControllerMapping *hitmap);

    ~Controller() = default;

    void update() override;
};

#endif //LIFEISBORNE_CONTROLLER_HPP
