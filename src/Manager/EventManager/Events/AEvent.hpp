//
// Created by zouz on 30/01/18.
//

#ifndef LIFEISBORNE_AEVENT_HPP
#define LIFEISBORNE_AEVENT_HPP

#include <string>

namespace Evt
{

    struct AEvent
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

        virtual ~AEvent() = default;

    private:
        std::string _info;
    };
}

std::ostream &operator<<(std::ostream &stream, const Evt::AEvent &evt);

#endif //LIFEISBORNE_AEVENT_HPP
