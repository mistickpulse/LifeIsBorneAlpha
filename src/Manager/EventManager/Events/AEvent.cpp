//
// Created by zouz on 28/01/18.
//

#include <ostream>
#include "AEvent.hpp"

using namespace Evt;

std::basic_ostream<char> &operator<<(std::ostream &stream, const AEvent &evt)
{
    stream << evt.getInfo() << std::endl;
    return stream;
}
