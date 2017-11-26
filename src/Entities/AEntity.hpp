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

    virtual ~AEntity() = default;

    AComponent *getComponent(const std::string &ComponentId);

    void addComponent(AComponent *cmp);

private:
    std::vector<AComponent *> _components;
};

#endif //LIFEISBORNE_AENTITY_HPP
