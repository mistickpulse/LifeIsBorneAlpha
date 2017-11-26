//
// Created by zouz on 26/11/17.
//

#ifndef LIFEISBORNE_CHARACTERLOADER_HPP
#define LIFEISBORNE_CHARACTERLOADER_HPP

#include <string>
#include <vector>
#include <chrono>
#include <unordered_map>
#include <SFML/Graphics/Sprite.hpp>
#include "../../../Utils/Size.hpp"
#include "../../../Components/Stats/Orientation.hpp"
#include "../../../Components/Body/BodyPartType.hpp"


struct AnimationLoader {
    std::string AnimationType; /* Basic */
    std::chrono::milliseconds ADuration; /* ANimation Duration */
    BodyPartAnimation *Sprites;
};

struct BodyPartLoader {
    std::string CharacterName;
    Size canvas;
    std::vector<std::string> AnimationType;
    std::vector<std::string> TextureKeys;
    std::string BodyPart;
    int SpriteQte;
    std::unordered_map<std::string, AnimationLoader> Animations;/* <Animation type, AnimationLoader>; */
};

#endif //LIFEISBORNE_CHARACTERLOADER_HPP
