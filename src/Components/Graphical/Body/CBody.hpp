//
// Created by zouz on 16/11/17.
//

#ifndef LIFEISBORNE_BODY_HPP
#define LIFEISBORNE_BODY_HPP

#include <vector>
#include "BodyPart.hpp"
#include "../../AComponent.hpp"
#include "../../../Utils/Position.hpp"
#include "../../Stats/COrientation.hpp"
#include "BodyPartType.hpp"

class CBody : public AComponent {
public:
    //pair<<BodyPartType, CharacterName>>
    CBody(const std::vector<std::pair<BodyPartType, std::string>> &BodyInformation);
    CBody() = delete;
    ~CBody() = default;

public:
    const std::vector<sf::Sprite> &getBodySprites(Orientation direction);


    void changeBodyPart(BodyPartType newBodyPartType, const std::string &CharacterName);

private:
    void _addBodyPart(BodyPartType newBodyPart, const std::string &CharacterName);
    void _deleteBodyPart(BodyPartType typeToDel);

private:
    std::vector<BodyPart> _bParts;
};


#endif //LIFEISBORNE_BODY_HPP
