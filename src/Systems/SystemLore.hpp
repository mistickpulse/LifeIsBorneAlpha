//
// Created by zouz on 14/11/17.
//

#ifndef LIFEISBORNE_SYSTEMLORE_HPP
#define LIFEISBORNE_SYSTEMLORE_HPP

#include <array>
#include <string>

enum SystemPriority {
    LOW,
    MEDIUM,
    HIGH
};

enum SystemState {
    ACTIVE,
    INACTIVE
};

namespace {

    std::array<std::string, 20> SystemIdReferences = {"Collision", "test"};

}

#endif //LIFEISBORNE_SYSTEMLORE_HPP
