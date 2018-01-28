//
// Created by zouz on 28/01/18.
//

#ifndef LIFEISBORNE_AEVENT_HPP
#define LIFEISBORNE_AEVENT_HPP

#include <string>

class AEvent
{
};

class TestEvent : public AEvent
{
public:
    TestEvent(const std::string &id) : id(id)
    {
    }

    std::string id;
};

#endif //LIFEISBORNE_AEVENT_HPP
