//
// Created by zouz on 24/11/17.
//

#include "../Components/AComponent.hpp"
#include "AEntity.hpp"

AComponent *AEntity::getComponent(const std::string &ComponentId) {
    for (auto &i : _components) {
        if (i->getType() == ComponentId)
            return i;
    }
    return nullptr;
}

void AEntity::addComponent(AComponent *cmp) {
    _components.push_back(cmp);
}

