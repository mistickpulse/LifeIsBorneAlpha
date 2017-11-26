//
// Created by zouz on 16/11/17.
//

#ifndef LIFEISBORNE_BODYPARTTYPE_HPP
#define LIFEISBORNE_BODYPARTTYPE_HPP

#include <SFML/Graphics/Sprite.hpp>
#include <vector>
#include <map>
#include "../../enum.h"
#include "../Stats/Orientation.hpp"

using BodyPartAnimation = std::map<Orientation, std::vector<sf::Sprite *>>;
using BodyPartAnimationType = std::map<std::string, BodyPartAnimation>;

BETTER_ENUM(BodyPartType, int,
    Hair = 0,
    Head,
    Chest,
    Arms,
    Leggs);

#endif //LIFEISBORNE_BODYPARTTYPE_HPP
