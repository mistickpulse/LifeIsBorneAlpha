//
// Created by zouz on 19/12/17.
//

#ifndef LIFEISBORNE_ACONTROLMAPPING_HPP
#define LIFEISBORNE_ACONTROLMAPPING_HPP

#include "../InputControllerType.hpp"
#include "../GameInput.hpp"

class AControlMapping {
public:
    explicit AControlMapping(InputControllerType controllerType);

    virtual ~AControlMapping() = default;

    InputControllerType getControllerType() const;

private:
    InputControllerType _controllerType;
};

#endif //LIFEISBORNE_ACONTROLMAPPING_HPP
