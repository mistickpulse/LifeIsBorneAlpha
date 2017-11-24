//
// Created by zouz on 16/11/17.
//

#ifndef LIFEISBORNE_BODY_HPP
#define LIFEISBORNE_BODY_HPP

#include <vector>
#include "GraphicalBodyPart.hpp"
#include "../AComponent.hpp"
#include "../../Utils/Position.hpp"
#include "../Stats/COrientation.hpp"
#include "BodyPartType.hpp"

class CGraphicalBody : public AComponent {
public:
    //pair<<BodyPartType, CharacterName>>
    CGraphicalBody(const std::vector<std::pair<BodyPartType, std::string>> &BodyInformation);

    CGraphicalBody() = delete;

    ~CGraphicalBody() = default;

public:
    sf::Sprite &getBodySprite(BodyPartType type, Orientation direction);

    void updateAnimation(const std::chrono::milliseconds &timeElapsed);

    void setSpriteRelativePosition(const Position &pos, Orientation dir);

private:
    void _addBodyPart(BodyPartType newBodyPart, const std::string &CharacterName);
    void _deleteBodyPart(BodyPartType typeToDel);

private:
    std::vector<GraphicalBodyPart *> _bParts;
};

#endif //LIFEISBORNE_BODY_HPP
