//
// Created by zouz on 16/11/17.
//

#ifndef LIFEISBORNE_BODYPARTTYPE_HPP
#define LIFEISBORNE_BODYPARTTYPE_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <vector>
#include "../../enum.h"
#include "../Stats/Orientation.hpp"

using BindDirectionVSprite = std::vector<std::pair<Orientation, std::vector<sf::Sprite>>>;

BETTER_ENUM(BodyPartType, int,
    Hair = 0,
    Head,
    Chest,
    Arms,
    Leggs);

#endif //LIFEISBORNE_BODYPARTTYPE_HPP
