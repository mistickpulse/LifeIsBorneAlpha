//
// Created by zouz on 16/11/17.
//

#ifndef LIFEISBORNE_BODYPART_HPP
#define LIFEISBORNE_BODYPART_HPP

#include <string>
#include <vector>
#include <array>
#include <SFML/Graphics/Sprite.hpp>
#include "../../../Utils/Size.hpp"
#include "../../Stats/Orientation.hpp"
#include "../../../enum.h"
#include "BodyPartType.hpp"


class BodyPart {
public:
    BodyPart(BindDirectionVSprite &SpriteSrc, BodyPartType type, const Size &canvasSize);

    ~BodyPart() = default;

public:
    std::vector<sf::Sprite> &getBodySprite(Orientation bodyOrientation);

    BodyPartType getBodyType() {
        return _type;
    }

    BodyPart &operator=(const BodyPart &src);

private:
    BindDirectionVSprite _sprites;
    BodyPartType _type;
    const Size _canvas;
};



#endif //LIFEISBORNE_BODYPART_HPP
