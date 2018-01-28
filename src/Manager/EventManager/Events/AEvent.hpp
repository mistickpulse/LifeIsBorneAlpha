//
// Created by zouz on 28/01/18.
//

#ifndef LIFEISBORNE_AEVENT_HPP
#define LIFEISBORNE_AEVENT_HPP

#include <string>

namespace Evt
{

    class AEvent
    {
    public:
        explicit AEvent(const std::string &info) :
            _info(info)
        {
        }

        const std::string &getInfo() const
        {
            return _info;
        }

    private:
        std::string _info;
    };
}

std::ostream &operator<<(std::ostream &stream, const Evt::AEvent &evt);

#endif //LIFEISBORNE_AEVENT_HPP
