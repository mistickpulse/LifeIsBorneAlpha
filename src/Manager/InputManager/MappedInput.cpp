//
// Created by zouz on 03/02/18.
//

#include <iostream>
#include "MappedInput.hpp"

std::ostream &Inputs::operator<<(std::ostream &stream, const Inputs::MappedInput &mi)
{
    stream << " ======[" << ((mi.ControllerId == -1) ? "Keyboard" : "Controller") << "["
           << static_cast<int>(mi.ControllerId) << "]" << std::endl;
    stream << " ==Actions[" << mi._action.size() << "]" << std::endl;
    stream << " ====>[" << mi._pos.x << ", " << mi._pos.y << "]" << std::endl;
    return stream;
}
