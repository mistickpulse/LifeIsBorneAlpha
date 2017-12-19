//
// Created by zouz on 19/12/17.
//

#include "../InputControllerType.hpp"
#include "AControlMapping.hpp"

AControlMapping::AControlMapping(InputControllerType controllerType) :
        _controllerType(controllerType) {

}

InputControllerType AControlMapping::getControllerType() const {
    return _controllerType;
}
