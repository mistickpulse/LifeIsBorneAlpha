//
// Created by zouz on 28/01/18.
//

#include <ostream>
#include "AEvent.hpp"

std::basic_ostream<char> &operator<<(std::ostream &stream, const Evt::AEvent &evt)
{
    stream << evt.getInfo() << std::endl;
    return stream;
}
