//
// Created by zouz on 14/11/17.
//

#ifndef LIFEISBORNE_AENTITY_HPP
#define LIFEISBORNE_AENTITY_HPP

#include <vector>
#include "../Components/AComponent.hpp"

class AEntity {
public:
   AEntity() = default;
    ~AEntity() = default;

private:
    std::vector<AComponent> _components;
};

#endif //LIFEISBORNE_AENTITY_HPP
