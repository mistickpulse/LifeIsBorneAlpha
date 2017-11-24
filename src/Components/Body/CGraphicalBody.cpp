//
// Created by zouz on 16/11/17.
//

#include <vector>
#include <SFML/Graphics/Sprite.hpp>
#include "CGraphicalBody.hpp"
#include "../../Factory/Component/BodyParts/BodyPartFactory.hpp"

CGraphicalBody::CGraphicalBody(const std::vector<std::pair<BodyPartType, std::string>> &BodyPartInfo) :
        AComponent(typeid(CGraphicalBody).name()) {
    for (const auto &i : BodyPartInfo) {
       _addBodyPart(i.first, i.second);
    }

}

void CGraphicalBody::_deleteBodyPart(BodyPartType typeToDel) {
    int offset = 0;
    for (auto &i : _bParts) {
        if (i->getBodyType() == typeToDel) {
            _bParts.erase(_bParts.begin() + offset);
        }
        ++offset;
    }
}

void CGraphicalBody::_addBodyPart(BodyPartType newBodyPart, const std::string &CharacterName) {
    _bParts.push_back(BodyPartFactory::getInstance().genBodyPart(CharacterName, newBodyPart));
}

sf::Sprite &CGraphicalBody::getBodySprite(BodyPartType type, Orientation direction) {
    for (auto &bodyPart : _bParts) {
        if (bodyPart->getBodyType() == type)
            return bodyPart->getAnimationSprite(direction);
    }
}

void CGraphicalBody::updateAnimation(const std::chrono::milliseconds &timeElapsed) {
    for (auto &bodyPart : _bParts) {
        bodyPart->updateAnimation(timeElapsed);
    }
}

void CGraphicalBody::setSpriteRelativePosition(const Position &pos, Orientation dir) {
    for (auto &i : _bParts) {
        i->setSpriteRelativePosition(pos, dir);
    }
}

