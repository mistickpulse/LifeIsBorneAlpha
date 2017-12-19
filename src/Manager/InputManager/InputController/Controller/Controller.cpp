//
// Created by zouz on 19/12/17.
//

#include "Controller.hpp"


Controller::Controller(ControllerMapping *hitmap, int controllerId) :
        AInputController(hitmap), controllerId(controllerId) {

}

void Controller::update() {
}
