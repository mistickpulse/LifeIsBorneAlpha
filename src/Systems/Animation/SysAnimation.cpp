//
// Created by zouz on 24/11/17.
//

#include <unordered_map>
#include "../../Entities/AEntity.hpp"
#include "SysAnimation.hpp"

void SysAnimation::compute(std::vector<AEntity *> &entities, const std::chrono::milliseconds &elapsed) {
    std::unordered_map<std::string, AComponent *> NeededComponent;
    for (auto &i : entities) {
        for (const auto &ComponentName : ComponentHandled) {
            AComponent *entityComponent = i->getComponent(ComponentName);
            if (entityComponent) {
                NeededComponent.insert(std::make_pair(ComponentName, entityComponent));
            }
        }
        if (NeededComponent.size() > 0) {
            _execute(NeededComponent, elapsed);
        }

        NeededComponent.clear();
    }
}

SysAnimation::SysAnimation(sf::RenderWindow &win) :
        ASystem(typeid(SysAnimation).name(), SystemPriority::MEDIUM, SystemState::ACTIVE),
        win(win) {}

void SysAnimation::_execute(std::unordered_map<std::string, AComponent *> ComponentToTreat,
                            const std::chrono::milliseconds &el) {
    __animate(ComponentToTreat, el);
}

void SysAnimation::__animate(std::unordered_map<std::string, AComponent *> &components,
                             const std::chrono::milliseconds &el) {
    if (components.size() == ComponentHandled.size()) {
        CPosition *pos = static_cast<CPosition *>(components[typeid(CPosition).name()]);
        CGraphicalBody *body = static_cast<CGraphicalBody *>(components[typeid(CGraphicalBody).name()]);
        CDirection *dir = static_cast<CDirection *>(components[typeid(CDirection).name()]);
        body->updateAnimation(el);
        body->setSpriteRelativePosition(pos->getPos(), dir->getOrientation());
    }
}
