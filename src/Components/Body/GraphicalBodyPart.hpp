//
// Created by zouz on 16/11/17.
//

#ifndef LIFEISBORNE_BODYPART_HPP
#define LIFEISBORNE_BODYPART_HPP

#include <string>
#include <vector>
#include <array>
#include <SFML/Graphics/Sprite.hpp>
#include <chrono>
#include "../../Utils/Size.hpp"
#include "../Stats/Orientation.hpp"
#include "../../enum.h"
#include "BodyPartType.hpp"
#include "../../Utils/Position.hpp"


class GraphicalBodyPart {
public:
    GraphicalBodyPart(BindDirectionVSprite &SpriteSrc, BodyPartType type, const Size &canvasSize,
                      const std::chrono::milliseconds &ADuration);

    ~GraphicalBodyPart() = default;

    GraphicalBodyPart() = delete;

public:
    void updateAnimation(const std::chrono::milliseconds &elasped_time);

    void setSpriteRelativePosition(const Position &pos, Orientation dir);

    sf::Sprite &getAnimationSprite(Orientation bodyOrientation);

    BodyPartType getBodyType() {
        return _type;
    }

    GraphicalBodyPart &operator=(const GraphicalBodyPart &src);

private:
    std::chrono::milliseconds _AnimationDuration;
    std::chrono::milliseconds _AnimationCurrentTick;
    std::chrono::milliseconds _AnimationTick;

    std::vector<std::pair<Orientation, std::vector<sf::Sprite>>> &_sprites;
    BodyPartType _type;
    const Size _canvas;
};

#endif //LIFEISBORNE_BODYPART_HPP
